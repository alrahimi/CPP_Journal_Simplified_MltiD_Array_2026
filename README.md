# CPP_Journal_Simplified_MultiD_Array_2026

## Overview
This project implements **safe multidimensional arrays** based on a C++ Journal article. It provides compile-time fixed-size arrays with bounds checking and modern C++ practices.

## Key Features
1. Instead of specifying type and low and high for the arrays, only type and size are specified
2. Overwrote `dim()` in base classes to return the correct dimension (for example, for A3D it returns dim = 3)
3. Exception handling with detailed error messages for out-of-bounds access
4. Modern C++ template-based design (C++11 and later)

## Array Classes
- **A1D** - One-dimensional array
- **A2D** - Two-dimensional array  
- **A3D** - Three-dimensional array
- **A4D** - Four-dimensional array

## Quick Start

### Building and Running
```bash
# Compile the main program
g++ -std=c++11 -Wall -Wextra -o safe_array SafeMultiD_Array_BasedOnCUJArticle.cpp

# Run the program
./safe_array
```

### Using Coding Agents
For detailed instructions on using GitHub Copilot and other coding agents with this repository, see:

📖 **[CODING_AGENT_GUIDE.md](CODING_AGENT_GUIDE.md)** - Comprehensive guide on how to use coding agents

### Quick Coding Agent Usage
1. Open any C++ file in VS Code
2. Click on the cloud icon dropdown (next to the bug icon)
3. Type: `Compile and run C++`
4. The agent will handle compilation and execution automatically

See also: [HowToCompileAndRunCppUsingAgent](HowToCompileAndRunCppUsingAgent) for a brief overview.

## Documentation
- **[CODING_AGENT_GUIDE.md](CODING_AGENT_GUIDE.md)** - How to use coding agents with this project
- **[GithubReviewOfThisArrayCode](GithubReviewOfThisArrayCode)** - Detailed code review and analysis
- **[ReviewByGithubCopilot](ReviewByGithubCopilot)** - Copilot's review and suggestions

## Files
- `SafeMultiD_Array_BasedOnCUJArticle.h` - Template class definitions
- `SafeMultiD_Array_BasedOnCUJArticle.cpp` - Main program with example usage and tests
- `UnitTests.cpp` - Unit test suite
- `OuPutFromCompileAndRun.txt` - Sample program output

## Example Usage
```cpp
#include "SafeMultiD_Array_BasedOnCUJArticle.h"

// Create a 3D array: 4 x 3 x 2
A3D<int, 4, 3, 2> my_array;

// Access elements (with bounds checking)
my_array[2][1][0] = 42;

// Get dimensions
int dimension = my_array.dim();  // Returns 3
```

## Error Handling
The arrays throw `RangeException` (derived from `std::out_of_range`) when accessing out-of-bounds indices, providing detailed error messages:
```
Index 5 out of range [0,3] for dim=2
```

## Requirements
- C++11 or later
- Standard C++ compiler (g++, clang++, MSVC)

## Contributing
Feel free to open issues or submit pull requests for improvements.

## License
Based on C++ Journal article implementation.
