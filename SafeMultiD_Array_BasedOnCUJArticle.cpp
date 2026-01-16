#include <iostream>
#include <cstdio>
#include "SafeMultiD_Array_BasedOnCUJArticle.h"

int main() {
    try {
        // ---------------------------------------------------------
        // Existing tests (unchanged)
        // ---------------------------------------------------------
        A1D<int,10> va1d;
        va1d[2] = 20;

        A2D<int,10,5> va2d;
        va2d[2][3] = 23;

        A3D<int,4,3,2> va3d;
        va3d[2][2][1] = 231;

        // get dims and bounds
        int dim1 = va3d.dim();
        std::size_t low1  = va3d.begin();
        std::size_t high1 = va3d.end();

        int dim2 = va3d[low1].dim();
        std::size_t low2  = va3d[low1].begin();
        std::size_t high2 = va3d[low1].end();

        int dim3 = va3d[low1][low2].dim();
        std::size_t low3  = va3d[low1][low2].begin();
        std::size_t high3 = va3d[low1][low2].end();

        std::printf("dim1=%d dim2=%d dim3=%d\n", dim1, dim2, dim3);
        std::printf("dim: %dX%dX%d\n", dim1, dim2, dim3);

        // ---------------------------------------------------------
        // Fill values
        // ---------------------------------------------------------
        for (std::size_t i = low1; i < high1; ++i)
            for (std::size_t j = low2; j < high2; ++j)
                for (std::size_t k = low3; k < high3; ++k)
                    va3d[i][j][k] = static_cast<int>((i * 100 + j) * 100 + k);

        // ---------------------------------------------------------
        // Validate values
        // ---------------------------------------------------------
        for (std::size_t i = low1; i < high1; ++i)
            for (std::size_t j = low2; j < high2; ++j)
                for (std::size_t k = low3; k < high3; ++k) {
                    int expected = static_cast<int>((i * 100 + j) * 100 + k);
                    if (va3d[i][j][k] != expected)
                        std::printf("%zu %zu %zu != %d\n",
                                    i, j, k, va3d[i][j][k]);
                }

        std::puts("\nend of existing tests");

        // ---------------------------------------------------------
        // NEW TEST: Out-of-range exception test
        // ---------------------------------------------------------
        std::puts("\nStarting out-of-range test...");

        A3D<int, 2, 3, 4> test3d;

        // This will be caught by the *outer* catch below
        test3d[0][0][5] = 123;

        return 0;
    }
    catch (const RangeException& RE) {
        std::printf("Caught RangeException:\n");
        std::printf("  what(): %s\n", RE.what());
        std::printf("  dim=%zu index=%zu range=[%zu:%zu]\n",
                    RE.dim, RE.index, RE.low, RE.high);
        return 1;
    }
}
