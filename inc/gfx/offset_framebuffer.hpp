#ifndef GFX_OFFSET_FRAMEBUFFER_HPP
#define GFX_OFFSET_FRAMEBUFFER_HPP

#include "framebuffer.hpp"

namespace gfx {

    template <typename PixelType>
    class OffsetFrameBuffer : public IFrameBuffer<PixelType> {
        public:
            explicit OffsetFrameBuffer(IFrameBuffer<PixelType>& wrapped, int offsetX = 0, int offsetY = 0)
                : wrapped_(wrapped), offsetX_(offsetX), offsetY_(offsetY) {}

            virtual ~OffsetFrameBuffer() = default;

            // --- Pixel operations with offset applied ---
            PixelType getPixel(int x, int y) const override {
                return wrapped_.getPixel(x + offsetX_, y + offsetY_);
            }

            void setPixel(int x, int y, PixelType color) override {
                wrapped_.setPixel(x + offsetX_, y + offsetY_, color);
            }

            // --- Metadata ---
            int getWidth() const override {
                return wrapped_.getWidth() - offsetX_;
            }

            int getHeight() const override {
                return wrapped_.getHeight() - offsetY_;
            }

            // --- Offset configuration ---
            void setOffset(int offsetX, int offsetY) {
                offsetX_ = offsetX;
                offsetY_ = offsetY;
            }

            int getOffsetX() const { return offsetX_; }
            int getOffsetY() const { return offsetY_; }

        private:
            IFrameBuffer<PixelType>& wrapped_;
            int offsetX_;
            int offsetY_;
    };

}

#endif
