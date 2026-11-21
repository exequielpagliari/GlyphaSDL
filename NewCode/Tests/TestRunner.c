#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "SDL.h"
#include "SDL_image.h"

#include "TestRunner.h"

extern long tickNext;

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