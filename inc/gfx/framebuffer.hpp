#ifndef GFX_FRAMEBUFFER_HPP
#define GFX_FRAMEBUFFER_HPP

#include <cstdint>
#include <cstddef>
#include <utility>

namespace gfx {

    enum class Anchor {
        TopLeft,    TopCenter,    TopRight,
        CenterLeft, Center,       CenterRight,
        BottomLeft, BottomCenter, BottomRight
    };

    inline std::pair<int, int> get_origin(int x, int y, int width, int height, Anchor anchor) {
        int finalX = x;
        int finalY = y;

        switch (anchor) {
            case Anchor::TopCenter: case Anchor::Center: case Anchor::BottomCenter:
                finalX -= width / 2; break;
            case Anchor::TopRight: case Anchor::CenterRight: case Anchor::BottomRight:
                finalX -= width; break;
            default: break;
        }

        switch (anchor) {
            case Anchor::CenterLeft: case Anchor::Center: case Anchor::CenterRight:
                finalY -= height / 2; break;
            case Anchor::BottomLeft: case Anchor::BottomCenter: case Anchor::BottomRight:
                finalY -= height; break;
            default: break;
        }
        return {finalX, finalY};
    }

    template <typename PixelType>
    class IFrameBuffer {
        public:
            virtual ~IFrameBuffer() = default;

            virtual PixelType getPixel(int x, int y) const = 0;
            virtual void setPixel(int x, int y, PixelType color) = 0;

            virtual int getWidth() const = 0;
            virtual int getHeight() const = 0;
    };

}

#endif
