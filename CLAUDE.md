# CLAUDE.md — lib/gfx

## Overview

Hardware-independent graphics primitives library for embedded displays. Zero external dependencies. Compiled as part of the parent `midicontrol-fw` CMake project (STM32G431, Cortex-M4, C++23, `-fno-exceptions`).

## Architecture

All code lives in namespace `gfx::` (text primitives in `gfx::text::`).

### Headers (`inc/gfx/`)

- **`framebuffer.hpp`** — `IFrameBuffer<PixelType>` interface (virtual setPixel/getPixel/getWidth/getHeight), `Anchor` enum (9 points), `get_origin()` helper.

- **`icon.hpp`** — `gfx::icon<W,H>` template backed by `std::array<std::bitset<W>, H>`. Pixel convention: x=0 is left/MSB. `drawIcon()` template function. Extern declarations for battery, wireless, and UI icons.

- **`text.hpp`** — `gfx::text::character<W,H>`, abstract `font` interface, `font_ascii<W,H,N>` concrete template. `drawText()` template. Extern Font_7x10, Font_11x18, Font_16x26.

- **`shapes.hpp`** — Header-only templates: `drawHLine`, `drawVLine`, `drawLine` (Bresenham), `drawRect`, `drawFilledRect`, `drawCircle` (midpoint), `drawFilledCircle`, `fill`.

### Sources (`src/`)

- `font_7x10.cpp`, `font_11x18.cpp`, `font_16x26.cpp` — Font data in `gfx::text` namespace.
- `icons.cpp` — Icon data (battery, wireless, UI dot/arrow/checkbox icons).

## Icon definition pattern

```cpp
const gfx::icon<14, 8> my_icon({
    std::bitset<14>("00111111111111"),
    // ...
});
```

Declare new icons `extern` in `icon.hpp` and define them in `src/icons.cpp`.
