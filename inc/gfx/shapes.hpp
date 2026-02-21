#ifndef GFX_SHAPES_HPP
#define GFX_SHAPES_HPP

#include "framebuffer.hpp"

namespace gfx {

    template <typename PixelType>
    void drawHLine(IFrameBuffer<PixelType>& fb, int x, int y, int w, PixelType color) {
        for (int i = 0; i < w; ++i) {
            int dx = x + i;
            if (dx >= 0 && dx < fb.getWidth() && y >= 0 && y < fb.getHeight())
                fb.setPixel(dx, y, color);
        }
    }

    template <typename PixelType>
    void drawVLine(IFrameBuffer<PixelType>& fb, int x, int y, int h, PixelType color) {
        for (int i = 0; i < h; ++i) {
            int dy = y + i;
            if (x >= 0 && x < fb.getWidth() && dy >= 0 && dy < fb.getHeight())
                fb.setPixel(x, dy, color);
        }
    }

    template <typename PixelType>
    void drawLine(IFrameBuffer<PixelType>& fb, int x0, int y0, int x1, int y1, PixelType color) {
        int dx = x1 - x0;
        int dy = y1 - y0;
        int sx = (dx > 0) ? 1 : -1;
        int sy = (dy > 0) ? 1 : -1;
        dx = (dx < 0) ? -dx : dx;
        dy = (dy < 0) ? -dy : dy;

        int err = dx - dy;

        while (true) {
            if (x0 >= 0 && x0 < fb.getWidth() && y0 >= 0 && y0 < fb.getHeight())
                fb.setPixel(x0, y0, color);

            if (x0 == x1 && y0 == y1) break;

            int e2 = 2 * err;
            if (e2 > -dy) { err -= dy; x0 += sx; }
            if (e2 <  dx) { err += dx; y0 += sy; }
        }
    }

    template <typename PixelType>
    void drawRect(IFrameBuffer<PixelType>& fb, int x, int y, int w, int h, PixelType color) {
        drawHLine(fb, x, y, w, color);
        drawHLine(fb, x, y + h - 1, w, color);
        drawVLine(fb, x, y, h, color);
        drawVLine(fb, x + w - 1, y, h, color);
    }

    template <typename PixelType>
    void drawFilledRect(IFrameBuffer<PixelType>& fb, int x, int y, int w, int h, PixelType color) {
        for (int row = 0; row < h; ++row)
            drawHLine(fb, x, y + row, w, color);
    }

    template <typename PixelType>
    void fill(IFrameBuffer<PixelType>& fb, PixelType color) {
        for (int y = 0; y < fb.getHeight(); ++y)
            for (int x = 0; x < fb.getWidth(); ++x)
                fb.setPixel(x, y, color);
    }

    template <typename PixelType>
    void drawCircle(IFrameBuffer<PixelType>& fb, int cx, int cy, int r, PixelType color) {
        int x = 0, y = r;
        int d = 1 - r;

        auto plot8 = [&](int px, int py) {
            auto set = [&](int sx, int sy) {
                if (sx >= 0 && sx < fb.getWidth() && sy >= 0 && sy < fb.getHeight())
                    fb.setPixel(sx, sy, color);
            };
            set(cx + px, cy + py); set(cx - px, cy + py);
            set(cx + px, cy - py); set(cx - px, cy - py);
            set(cx + py, cy + px); set(cx - py, cy + px);
            set(cx + py, cy - px); set(cx - py, cy - px);
        };

        while (x <= y) {
            plot8(x, y);
            if (d < 0) {
                d += 2 * x + 3;
            } else {
                d += 2 * (x - y) + 5;
                --y;
            }
            ++x;
        }
    }

    template <typename PixelType>
    void drawFilledCircle(IFrameBuffer<PixelType>& fb, int cx, int cy, int r, PixelType color) {
        int x = 0, y = r;
        int d = 1 - r;

        auto hline = [&](int lx, int rx, int ly) {
            if (ly < 0 || ly >= fb.getHeight()) return;
            if (lx < 0) lx = 0;
            if (rx >= fb.getWidth()) rx = fb.getWidth() - 1;
            for (int i = lx; i <= rx; ++i)
                fb.setPixel(i, ly, color);
        };

        while (x <= y) {
            hline(cx - x, cx + x, cy + y);
            hline(cx - x, cx + x, cy - y);
            hline(cx - y, cx + y, cy + x);
            hline(cx - y, cx + y, cy - x);
            if (d < 0) {
                d += 2 * x + 3;
            } else {
                d += 2 * (x - y) + 5;
                --y;
            }
            ++x;
        }
    }

}

#endif
