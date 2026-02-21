#ifndef GFX_ICON_HPP
#define GFX_ICON_HPP

#include <bitset>
#include <array>
#include <cstddef>
#include <cstdint>
#include "framebuffer.hpp"

namespace gfx {

    template <std::size_t Width, std::size_t Height>
    class icon {
        public:
            using row_t  = std::bitset<Width>;
            using data_t = std::array<row_t, Height>;

            constexpr icon(const data_t& rows) : data_(rows) {}

            static constexpr std::size_t width  = Width;
            static constexpr std::size_t height = Height;

            constexpr const row_t& row(std::size_t y) const { return data_[y]; }

            constexpr bool pixel(std::size_t x, std::size_t y) const {
                return data_[y][Width - 1 - x];
            }

        private:
            data_t data_;
    };

    template <typename PixelType, typename IconType>
    void drawIcon(gfx::IFrameBuffer<PixelType>& fb, const IconType& icon,
                  int x, int y, gfx::Anchor anchor, PixelType color) {

        auto origin = gfx::get_origin(x, y, (int)IconType::width, (int)IconType::height, anchor);
        int startX = origin.first;
        int startY = origin.second;

        for (std::size_t iy = 0; iy < IconType::height; ++iy) {
            int drawY = startY + int(iy);
            if (drawY < 0 || drawY >= fb.getHeight()) continue;

            for (std::size_t ix = 0; ix < IconType::width; ++ix) {
                if (icon.pixel(ix, iy)) {
                    int drawX = startX + int(ix);
                    if (drawX >= 0 && drawX < fb.getWidth()) {
                        fb.setPixel(drawX, drawY, color);
                    }
                }
            }
        }
    }

}

// Battery icons
extern const gfx::icon<14, 8> battery_empty;
extern const gfx::icon<14, 8> battery_1_4;
extern const gfx::icon<14, 8> battery_2_4;
extern const gfx::icon<14, 8> battery_3_4;
extern const gfx::icon<14, 8> battery_full;

// Wireless icons
extern const gfx::icon<14, 10> wireless_1;
extern const gfx::icon<14, 10> wireless_2;
extern const gfx::icon<14, 10> wireless_3;
extern const gfx::icon<14, 10> wireless_4;

// UI icons
extern const gfx::icon<7, 7> dot_filled;
extern const gfx::icon<7, 7> dot_outline;
extern const gfx::icon<7, 7> arrow_up;
extern const gfx::icon<7, 7> arrow_down;
extern const gfx::icon<8, 9> arrow_left_empty;
extern const gfx::icon<8, 9> arrow_left_filled;
extern const gfx::icon<9, 9> checkbox_empty;
extern const gfx::icon<9, 9> checkbox_empty_checked;
extern const gfx::icon<9, 9> checkbox_filled;
extern const gfx::icon<9, 9> checkbox_filled_checked;

#endif
