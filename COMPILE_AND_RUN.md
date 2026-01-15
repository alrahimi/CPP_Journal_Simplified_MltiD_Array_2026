# Compilation and Execution Instructions

## Prerequisites
- g++ compiler with C++11 support or later
- Linux/Unix environment (or WSL on Windows)

## Compilation

To compile `SafeMultiD_Array_BasedOnCUJArticle.cpp`, use the following command:

```bash
g++ -std=c++11 -Wall -Wextra -o SafeMultiD_Array_Program SafeMultiD_Array_BasedOnCUJArticle.cpp
```

### Compilation Flags Explanation:
- `-std=c++11`: Use C++11 standard
- `-Wall`: Enable all common warnings
- `-Wextra`: Enable extra warnings
- `-o SafeMultiD_Array_Program`: Specify output executable name

## Execution

After successful compilation, run the program with:

```bash
./SafeMultiD_Array_Program
```

## Expected Output

```
dim1=1 dim2=1 dim3=2
dim: 1X1X2

end of existing tests

Starting out-of-range test...
Caught RangeException:
  what(): Index 5 out of range [0,3] for dim=2
  dim=2 index=5 range=[0:3]
```

## What the Program Does

1. **Tests 1D, 2D, and 3D arrays**: Creates and manipulates arrays of different dimensions
2. **Demonstrates dimension and bounds retrieval**: Gets dimension info using `dim()`, `begin()`, and `end()` methods
3. **Fill and validate arrays**: Populates 3D array with calculated values and verifies them
4. **Tests exception handling**: Intentionally triggers an out-of-range exception to demonstrate safe array access

## Exit Code

The program exits with code 1 (due to the intentional exception test), which is expected behavior.

## Changes Made

Added `begin()` and `end()` methods to the `A1D` class in `SafeMultiD_Array_BasedOnCUJArticle.h` to support the array iteration pattern used in the main program.
