# GlyphaSDL

A work-in-progress port of **Glypha III** from the original Macintosh environment to C and SDL2.

The project preserves parts of the original game structure and gradually replaces Macintosh Toolbox and QuickDraw functionality with portable SDL2-based implementations.

## Current state

The port is currently focused on:

- Replacing QuickDraw graphics operations with SDL2 rendering.
- Recreating selected Macintosh data types and utility functions.
- Building a portable C codebase with CMake.
- Adding isolated tests for the compatibility layer.

The original source structure is intentionally retained in several areas to make the porting process easier to follow.

## Building

Requirements:

- C11 compiler
- CMake 4.0+
- SDL2
- SDL2_image
- SDL2_mixer

Configure and build with:

```bash
cmake -B build
cmake --build build
```

## Tests

Some compatibility and rendering functions can be exercised through the test runner:

```bash
NewCode --test <test-name>
```

The tests currently cover parts of the SDL compatibility layer, timing functions, rectangle operations, memory handles, texture loading and rendering.

## Project structure

```text
src/        Main game and ported game logic
src/CoreSDL SDL2 compatibility layer
include/    Public headers
Tests/      Test runner and isolated tests
Img/        Game graphics and related resources
Snd/        Sound resources
doc/        Notes about the original Macintosh implementation
cmake/      CMake modules
```

## License

The project is intended as a technical porting and preservation effort.  
Original game code and assets may be subject to their respective copyrights and licenses.