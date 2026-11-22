#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "SDL.h"
#include "SDL_image.h"
#include "CoreSDL/SDL_Interface.h"
#include "CoreSDL/SDL_Utilities.h"

#include "TestRunner.h"

extern Boolean playing;
extern Boolean pausing;
extern Boolean evenFrame;
extern SDL_Renderer *renderer;
extern Boolean quitting;
long tickWait;

static int TestRandom(void)
{
    /*
     * Random() debe producir el mismo resultado que la implementación
     * original para una misma semilla.
     */
    srand(12345);

    int expected = (short)rand();

    srand(12345);

    int actual = Random();

    if (actual != expected) {
        fprintf(
            stderr,
            "Random FAILED: expected=%d actual=%d\n",
            expected,
            actual
        );

        return 0;
    }

    printf("Random PASSED: %d\n", actual);

    return 1;
}

static int TestTickCount(void)
{
    Uint16 before;
    Uint16 after;

    before = (Uint16)TickCount();

    SDL_Delay(10);

    after = (Uint16)TickCount();

    Uint16 elapsed = (Uint16)(after - before);

    if (elapsed < 5 || elapsed > 100)
    {
        fprintf(stderr,
            "TickCount FAILED: elapsed=%u ms\n",
            elapsed);
        return 0;
    }

    printf("TickCount PASSED: elapsed=%u ms\n", elapsed);
    return 1;
}

static int TestLogNextTick(void)
{
	

    long before = TickCount();

    LogNextTick(100);

    long after = tickNext;

    long expected = before + 100;

    if (after != expected)
    {
        fprintf(stderr,
            "LogNextTick FAILED: expected=%ld actual=%ld\n",
            expected,
            after);
        return 0;
    }

    printf("LogNextTick PASSED: tickNext=%ld\n", after);
    return 1;
}

static int TestWaitForNextTick(void)
{
    Uint32 before;
    Uint32 after;
    Uint32 elapsed;

    tickNext = (long)SDL_GetTicks() + 30;

    before = SDL_GetTicks();

    WaitForNextTick();

    after = SDL_GetTicks();

    elapsed = after - before;

    if (elapsed < 20)
    {
        fprintf(stderr,
            "WaitForNextTick FAILED: elapsed=%u ms\n",
            elapsed);
        return 0;
    }

    printf("WaitForNextTick PASSED: elapsed=%u ms\n", elapsed);
    return 1;
}

static int TestNewHandle(void)
{
    const Size size = 32;

    Handle h = NewHandle(size);

    if (!h)
    {
        fprintf(stderr, "NewHandle FAILED: returned NULL\n");
        return 0;
    }

    if (!*h)
    {
        fprintf(stderr, "NewHandle FAILED: data pointer is NULL\n");
        DisposeHandle(h);
        return 0;
    }

    for (Size i = 0; i < size; ++i)
    {
        if ((*h)[i] != 0)
        {
            fprintf(stderr,
                "NewHandle FAILED: byte %zu is not zero\n",
                (size_t)i);

            DisposeHandle(h);
            return 0;
        }
    }

    printf("NewHandle PASSED: %zu bytes initialized to zero\n",
        (size_t)size);

    DisposeHandle(h);
    return 1;
}

static int TestDisposeHandle(void)
{
    DisposeHandle(NULL);

    Handle h = NewHandle(16);

    if (!h)
    {
        fprintf(stderr,
            "DisposeHandle FAILED: NewHandle returned NULL\n");
        return 0;
    }

    DisposeHandle(h);

    printf("DisposeHandle PASSED\n");
    return 1;
}

static int RectEqual(const SDL_Rect* a, const SDL_Rect* b)
{
    return a->x == b->x &&
        a->y == b->y &&
        a->w == b->w &&
        a->h == b->h;
}

static int TestSetRect(void)
{
    SDL_Rect rect = { 100, 200, 300, 400 };

    SetRect(&rect, 10, 20, 30, 40);

    SDL_Rect expected = {
        10, 20, 30, 40
    };

    if (!RectEqual(&rect, &expected))
    {
        fprintf(stderr,
            "SetRect FAILED: got (%d,%d,%d,%d), "
            "expected (%d,%d,%d,%d)\n",
            rect.x, rect.y, rect.w, rect.h,
            expected.x, expected.y,
            expected.w, expected.h);

        return 0;
    }

    printf("SetRect PASSED\n");
    return 1;
}

static int TestOffsetRect(void)
{
    SDL_Rect rect = {
        10, 20, 30, 40
    };

    OffsetRect(&rect, 5, -3);

    SDL_Rect expected = {
        15, 17, 30, 40
    };

    if (!RectEqual(&rect, &expected))
    {
        fprintf(stderr,
            "OffsetRect FAILED: got (%d,%d,%d,%d), "
            "expected (%d,%d,%d,%d)\n",
            rect.x, rect.y, rect.w, rect.h,
            expected.x, expected.y,
            expected.w, expected.h);

        return 0;
    }

    printf("OffsetRect PASSED\n");
    return 1;
}

static int TestZeroRectCorner(void)
{
    SDL_Rect rect = {
        10, 20, 110, 220
    };

    ZeroRectCorner(&rect);

    SDL_Rect expected = {
        0, 0, 100, 200
    };

    if (!RectEqual(&rect, &expected))
    {
        fprintf(stderr,
            "ZeroRectCorner FAILED: got (%d,%d,%d,%d), "
            "expected (%d,%d,%d,%d)\n",
            rect.x, rect.y, rect.w, rect.h,
            expected.x, expected.y,
            expected.w, expected.h);

        return 0;
    }

    printf("ZeroRectCorner PASSED\n");
    return 1;
}

static int TestLoadTexture(void)
{
    if (!renderer)
    {
        fprintf(stderr,
            "loadTexture FAILED: renderer is NULL\n");
        return 0;
    }

    Texture* texture = loadTexture("test_texture.bmp");

    if (!texture)
    {
        fprintf(stderr,
            "loadTexture FAILED: texture is NULL\n");
        return 0;
    }

    SDL_DestroyTexture(texture);

    printf("loadTexture PASSED\n");
    return 1;
}

static int TestCopyBitsSDL(void)
{
    if (!renderer)
    {
        fprintf(stderr,
            "CopyBits_SDL FAILED: renderer is NULL\n");
        return 0;
    }

    // -------------------------------------------------
    // Crear superficie fuente
    // -------------------------------------------------

    SDL_Surface* surface =
        SDL_CreateRGBSurfaceWithFormat(
            0,
            4,
            4,
            32,
            SDL_PIXELFORMAT_RGBA32);

    if (!surface)
    {
        fprintf(stderr,
            "CopyBits_SDL FAILED: could not create surface: %s\n",
            SDL_GetError());
        return 0;
    }

    SDL_FillRect(
        surface,
        NULL,
        SDL_MapRGBA(
            surface->format,
            255, 255, 255, 255));

    SDL_Texture* srcTexture =
        SDL_CreateTextureFromSurface(renderer, surface);

    SDL_FreeSurface(surface);

    if (!srcTexture)
    {
        fprintf(stderr,
            "CopyBits_SDL FAILED: could not create source texture: %s\n",
            SDL_GetError());
        return 0;
    }

    // -------------------------------------------------
    // Crear textura destino (workSrcMap simulado)
    // -------------------------------------------------

    SDL_Texture* dstTexture =
        SDL_CreateTexture(
            renderer,
            SDL_PIXELFORMAT_RGBA8888,
            SDL_TEXTUREACCESS_TARGET,
            4,
            4);

    if (!dstTexture)
    {
        fprintf(stderr,
            "CopyBits_SDL FAILED: could not create target texture: %s\n",
            SDL_GetError());

        SDL_DestroyTexture(srcTexture);
        return 0;
    }

    SDL_Rect src = { 0, 0, 4, 4 };
    SDL_Rect dst = { 0, 0, 4, 4 };

    // -------------------------------------------------
    // Test 1: fuente -> textura destino
    // -------------------------------------------------

    int result = CopyBits_SDL(
        renderer,
        srcTexture,
        dstTexture,
        &src,
        &dst);

    if (result != 0)
    {
        fprintf(stderr,
            "CopyBits_SDL FAILED: texture-to-texture: %s\n",
            SDL_GetError());

        SDL_DestroyTexture(dstTexture);
        SDL_DestroyTexture(srcTexture);
        return 0;
    }

    // -------------------------------------------------
    // Test 2: fuente -> pantalla
    // -------------------------------------------------

    result = CopyBits_SDL(
        renderer,
        dstTexture,
        NULL,
        &src,
        &dst);

    if (result != 0)
    {
        fprintf(stderr,
            "CopyBits_SDL FAILED: texture-to-screen: %s\n",
            SDL_GetError());

        SDL_DestroyTexture(dstTexture);
        SDL_DestroyTexture(srcTexture);
        return 0;
    }

    SDL_RenderPresent(renderer);

    // -------------------------------------------------
    // Cleanup
    // -------------------------------------------------

    SDL_DestroyTexture(dstTexture);
    SDL_DestroyTexture(srcTexture);

    printf("CopyBits_SDL PASSED\n");
    return 1;
}

static int DrawTochesTest(void)
{

	

    do						// Here begins the main loop.
    {
        HandleEvent();		// Check for events.
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 1);


        if ((playing) && (!pausing))
            printf("Play");//PlayGame();		// If user began game, drop in game loop. (play mode)
        else				// If no game, animate the screen. (idle mode)
        {

            tickWait = TickCount() + 2L;
            evenFrame = !evenFrame;
            DrawTorches();	// Flicker torches.

            CopyAllRects();	// Refresh screen.
            LogNextTick(50);
            WaitForNextTick();
            do				// Wait for 2 Ticks to pass to keep fast Macs at bay.
            {
            } while (TickCount() < tickWait);

        }

    } while (!quitting);

    //KillSound();			// Dispose of sound channels.
    ShutItDown();			// Dispose of other structures.
    //WriteOutPrefs();		// Save preferences to disk.
    return 0;
    printf("DrawTorches PASSED\n");
    return 1;
}

static int TestLoadTextureAndDraw(void)
{
    const char* filename = "Img/130.bmp";

    printf("Loading texture: %s\n", filename);

    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 1);
    /*
     * Esta es exactamente la operación que queremos probar.
     */
    Texture* backSrcMap = loadTexture((char*)filename);

    if (!backSrcMap)
    {
        fprintf(stderr,
            "loadTexture FAILED for: %s\n",
            filename);

        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        IMG_Quit();
        SDL_Quit();

        return 0;
    }

    printf("loadTexture PASSED\n");
    printf("Drawing texture...\n");

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    /*
     * NULL como srcRect = textura completa.
     * NULL como dstRect = toda la ventana.
     */
    if (SDL_RenderCopy(renderer,
        backSrcMap,
        NULL,
        NULL) != 0)
    {
        fprintf(stderr,
            "SDL_RenderCopy FAILED: %s\n",
            SDL_GetError());

        SDL_DestroyTexture(backSrcMap);
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        IMG_Quit();
        SDL_Quit();

        return 0;
    }

    SDL_RenderPresent(renderer);

    printf("Texture drawn successfully.\n");
    printf("Keeping window open for 5 seconds...\n");

    SDL_Delay(5000);

    SDL_DestroyTexture(backSrcMap);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    IMG_Quit();
    SDL_Quit();

    return 1;
}


static const struct
{
    const char *name;
    int (*fn)(void);

} tests[] =
{
    { "Random",          TestRandom },
    { "TickCount",       TestTickCount },
    { "LogNextTick",     TestLogNextTick },
    { "WaitForNextTick", TestWaitForNextTick },
    { "NewHandle",       TestNewHandle },
    { "DisposeHandle",   TestDisposeHandle },
    { "SetRect",         TestSetRect },
    { "OffsetRect",      TestOffsetRect },
    { "ZeroRectCorner",  TestZeroRectCorner },
    { "loadTexture",     TestLoadTexture },
    { "CopyBits_SDL",    TestCopyBitsSDL },
    { "DrawToches",    DrawTochesTest },
    { "LoadTextureAndDraw",    TestLoadTextureAndDraw },
};


int RunTest(int argc, char **argv)
{
    if (argc < 2) {
        fprintf(stderr, "Usage: NewCode --test <name>\n");
        return 2;
    }

    for (size_t i = 0;
         i < sizeof(tests) / sizeof(tests[0]);
         ++i)
    {
        if (strcmp(argv[1], tests[i].name) == 0) {

            int result = tests[i].fn();

            return result ? 0 : 1;
        }
    }

    fprintf(stderr, "Unknown test: %s\n", argv[1]);

    return 2;
}