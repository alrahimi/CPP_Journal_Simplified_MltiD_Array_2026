#include <iostream>
#include <cassert>
#include "SafeMultiD_Array_BasedOnCUJArticle.h"

int main() {
    try {
        // Test A1D
        A1D<int,3> a1;
        a1[0] = 10; a1[1] = 20; a1[2] = 30;
        const A1D<int,3>& ca1 = a1;
        assert(ca1[0] == 10 && ca1[1] == 20 && ca1[2] == 30);

        bool caught = false;
        try { a1[3] = 0; } catch (const RangeException&) { caught = true; }
        assert(caught && "Out-of-range access should throw RangeException");

        // Test A2D
        A2D<int,2,2> a2;
        a2[0][0] = 1; a2[0][1] = 2; a2[1][0] = 3; a2[1][1] = 4;
        assert(a2[1][1] == 4);

        // Test A3D
        A3D<int,2,2,2> a3;
        for (std::size_t i = a3.begin(); i <= a3.end(); ++i)
            for (std::size_t j = a3[i].begin(); j <= a3[i].end(); ++j)
                for (std::size_t k = a3[i][j].begin(); k <= a3[i][j].end(); ++k)
                    a3[i][j][k] = static_cast<int>(i * 100 + j * 10 + k);

        for (std::size_t i = a3.begin(); i <= a3.end(); ++i)
            for (std::size_t j = a3[i].begin(); j <= a3[i].end(); ++j)
                for (std::size_t k = a3[i][j].begin(); k <= a3[i][j].end(); ++k)
                    assert(a3[i][j][k] == static_cast<int>(i * 100 + j * 10 + k));

        std::cout << "All UnitTests passed\n";
        return 0;
    }
    catch (const std::exception& e) {
        std::cerr << "Test failed with exception: " << e.what() << '\n';
        return 1;
    }
}
