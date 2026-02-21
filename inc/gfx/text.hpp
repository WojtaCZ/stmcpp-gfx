#ifndef GFX_TEXT_HPP
#define GFX_TEXT_HPP

#include <cstdint>
#include <array>
#include <bitset>
#include <type_traits>
#include <utility>
#include <cstring>
#include "framebuffer.hpp"

namespace gfx::text {

    template <std::size_t Width, std::size_t Height>
    class character {
        public:
            static_assert(Width > 0, "Width must be > 0");
            static_assert(Height > 0, "Height must be > 0");

            using bit_row_t  = std::bitset<Width>;
            using bit_data_t = std::array<bit_row_t, Height>;

            static constexpr std::size_t width  = Width;
            static constexpr std::size_t height = Height;

            constexpr character(const bit_data_t& rows) : data_(rows) {}

            constexpr bool pixel(std::size_t x, std::size_t y) const {
                if (x >= Width || y >= Height) return false;
                return data_[y][Width - 1 - x];
            }

        private:
            bit_data_t data_;
    };

    class font {
        public:
            virtual bool pixel(char c, std::size_t x, std::size_t y) const = 0;
            virtual std::size_t width() const = 0;
            virtual std::size_t height() const = 0;
            virtual ~font() = default;
    };

    template <std::size_t Width, std::size_t Height, std::size_t Count, char StartChar = ' '>
    class font_ascii : public font {
        public:
            using char_type = character<Width, Height>;

            constexpr font_ascii(const std::array<char_type, Count>& chars)
                : chars_(chars) {}

            bool pixel(char c, std::size_t x, std::size_t y) const override {
                if (c < StartChar || c >= StartChar + static_cast<char>(Count)) return false;
                return chars_[c - StartChar].pixel(x, y);
            }

            std::size_t width() const override { return Width; }
            std::size_t height() const override { return Height; }

        private:
            std::array<char_type, Count> chars_;
    };

    template <typename PixelType, typename FontType>
    void drawText(gfx::IFrameBuffer<PixelType>& fb, const FontType& f, const char* text,
                  int x, int y, gfx::Anchor anchor, PixelType color) {

        if (!text || *text == '\0') return;

        std::size_t length = std::strlen(text);
        int textWidth = int(length) * int(f.width());
        int textHeight = int(f.height());

        auto origin = get_origin(x, y, textWidth, textHeight, anchor);
        int startX = origin.first;
        int startY = origin.second;

        int cursorX = startX;

        for (std::size_t ci = 0; ci < length; ++ci) {
            char c = text[ci];

            if (cursorX + int(f.width()) < 0 || cursorX >= int(fb.getWidth())) {
                cursorX += int(f.width());
                continue;
            }

            for (std::size_t fy = 0; fy < f.height(); ++fy) {
                int drawY = startY + int(fy);
                if (drawY < 0 || drawY >= int(fb.getHeight())) continue;

                for (std::size_t fx = 0; fx < f.width(); ++fx) {
                    if (f.pixel(c, fx, fy)) {
                        int drawX = cursorX + int(fx);
                        if (drawX >= 0 && drawX < int(fb.getWidth())) {
                            fb.setPixel(drawX, drawY, color);
                        }
                    }
                }
            }
            cursorX += int(f.width());
        }
    }

    extern const font_ascii<7, 10, 95> Font_7x10;
    extern const font_ascii<11, 18, 95> Font_11x18;
    extern const font_ascii<16, 26, 95> Font_16x26;

}
#endif
