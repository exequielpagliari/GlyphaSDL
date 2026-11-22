# Contributing to GlyphaSDL

Thank you for your interest in contributing to GlyphaSDL.

GlyphaSDL is a work-in-progress port of **Glypha III** from the original Macintosh environment to C and SDL2. The project is still under active development, so contributions that help improve the port, its compatibility layer, testing, portability, or documentation are welcome.

## Ways to contribute

Some useful areas include:

- SDL2 and rendering
- Macintosh Toolbox and QuickDraw compatibility
- C code and portability
- Tests
- Build system and CMake
- Documentation
- Bug fixes and code cleanup

You do not need to work on the whole project. A small, focused contribution is useful.

## Before making changes

Please check the existing issues and source code before starting work.

For changes involving the original Macintosh behavior, the documentation in `doc/` may provide useful context.

When possible, test changes in isolation before modifying larger parts of the port.

## Issues

If you find a bug or an incomplete part of the port, an issue is useful even if you do not have a solution yet.

A useful issue should include:

- What was expected.
- What actually happens.
- Steps to reproduce the problem.
- Relevant files or functions.
- Any useful logs or error messages.

For rendering or compatibility problems, a small reproducible example or isolated test is especially helpful.

## Pull requests

Keep pull requests focused on a specific problem or improvement.

A good pull request should:

- Explain what was changed and why.
- Keep unrelated changes out of the same PR.
- Include tests when appropriate.
- Make sure the project still builds.
- Mention known limitations or remaining problems.

Large changes are welcome when necessary, but discussing them in an issue first can make the work easier to coordinate.

## Code style

The project is written primarily in C.

When modifying existing code:

- Prefer the existing style of the surrounding code.
- Keep changes readable and explicit.
- Avoid introducing unnecessary dependencies.
- Preserve the original game structure when there is a good reason to do so.
- Prefer small, testable changes over large rewrites.

## Testing

The project includes isolated tests for parts of the compatibility layer.

Tests can be run through the executable with:

```bash
GlyphaSDL --test <test-name>
```

If you add or modify compatibility functionality, consider adding or updating an isolated test for it.

## Porting philosophy

GlyphaSDL is not intended to be a conventional rewrite of the original game.

An important part of the project is understanding the original Macintosh implementation and replacing its platform-specific functionality with portable equivalents.

When possible, preserve the behavior and intent of the original code rather than simply reproducing its implementation details.

## Questions and discussion

If you are unsure whether a change fits the project, open an issue and describe the problem or proposed approach.

There is no requirement to have a complete solution before starting a discussion.
