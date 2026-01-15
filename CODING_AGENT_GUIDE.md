# Coding Agent User Guide

## What is a Coding Agent?

A **coding agent** is an AI-powered assistant integrated into your development environment (like GitHub Copilot) that can help you with various coding tasks such as:
- Compiling and running code
- Writing and debugging code
- Running tests
- Refactoring code
- Reviewing code
- Explaining code functionality
- Generating documentation

## How to Access the Coding Agent

### In Visual Studio Code with GitHub Copilot

1. **Install GitHub Copilot Extension**
   - Open VS Code
   - Go to Extensions (Ctrl+Shift+X or Cmd+Shift+X on Mac)
   - Search for "GitHub Copilot"
   - Install both "GitHub Copilot" and "GitHub Copilot Chat" extensions

2. **Activate the Coding Agent**
   - Look for the chat icon in the left sidebar or activity bar
   - Or use the keyboard shortcut: `Ctrl+I` (Windows/Linux) or `Cmd+I` (Mac)
   - Or click the cloud icon dropdown next to the debug icon in the top toolbar

3. **Start Interacting**
   - Type your request in natural language
   - The agent will understand and help you accomplish your task

## Using the Coding Agent with This Repository

### Compiling and Running C++ Code

**Method 1: Using the Chat Interface**
1. Open any C++ file in the repository (e.g., `SafeMultiD_Array_BasedOnCUJArticle.cpp`)
2. Click on the cloud icon dropdown (next to the bug icon in the toolbar)
3. Type: `Compile and run C++`
4. Press Enter
5. The agent will automatically compile and run your code

**Method 2: Using Inline Chat**
1. Open the C++ file you want to compile
2. Press `Ctrl+I` (or `Cmd+I` on Mac)
3. Type your request, for example:
   - "Compile this file"
   - "Build and run this code"
   - "Compile with g++ and run"

### Common Coding Agent Tasks for This Project

#### 1. **Build the Project**
```
Request: "Compile SafeMultiD_Array_BasedOnCUJArticle.cpp with g++"
```
The agent will run:
```bash
g++ -std=c++11 -o program SafeMultiD_Array_BasedOnCUJArticle.cpp
```

#### 2. **Run the Compiled Program**
```
Request: "Run the compiled program"
```
The agent will execute the binary and show you the output.

#### 3. **Compile and Run in One Step**
```
Request: "Compile and run the C++ code"
```
The agent will compile and execute the program automatically.

#### 4. **Run Unit Tests**
```
Request: "Compile and run UnitTests.cpp"
```

#### 5. **Explain Code**
```
Request: "Explain how the A3D template class works"
```

#### 6. **Debug Issues**
```
Request: "Why is my code throwing a RangeException?"
```

#### 7. **Refactor Code**
```
Request: "Add const correctness to the operator[] methods"
```

#### 8. **Generate Documentation**
```
Request: "Generate documentation comments for the A1D class"
```

## Expected Output

When you compile and run the main program, you should see output similar to:

```
dim1=1 dim2=1 dim3=2
dim: 1X1X2

end of existing tests

Starting out-of-range test...
Caught RangeException:
  what(): Index 5 out of range [0,3] for dim=2
  dim=2 index=5 range=[0:3]
```

## Tips for Effective Coding Agent Use

### 1. **Be Specific**
Instead of: "Fix this"
Try: "Fix the range exception in the A3D array access"

### 2. **Provide Context**
Instead of: "Compile"
Try: "Compile this C++ file with C++11 standard and optimization level O2"

### 3. **Ask for Explanations**
- "Explain the difference between A2D and A3D"
- "How does bounds checking work in this array implementation?"
- "What's the purpose of the RangeException class?"

### 4. **Request Step-by-Step Help**
- "Walk me through adding a new test case"
- "Show me how to create a 4D array"

### 5. **Use for Code Review**
- "Review this code for potential bugs"
- "Check if this follows C++ best practices"
- "Are there any memory safety issues?"

## Common Commands for This Repository

### Building
```bash
# Compile the main program
g++ -std=c++11 -Wall -Wextra -o safe_array SafeMultiD_Array_BasedOnCUJArticle.cpp

# Compile with debug symbols
g++ -std=c++11 -g -o safe_array_debug SafeMultiD_Array_BasedOnCUJArticle.cpp

# Compile unit tests
g++ -std=c++11 -Wall -Wextra -o unit_tests UnitTests.cpp
```

### Running
```bash
# Run the main program
./safe_array

# Run unit tests
./unit_tests
```

## Troubleshooting

### Issue: Agent doesn't respond
**Solution**: 
- Check your GitHub Copilot subscription is active
- Restart VS Code
- Check your internet connection

### Issue: Compilation fails
**Solution**:
- Ask the agent: "Why did compilation fail?"
- Ensure you have a C++ compiler installed (g++, clang++, or MSVC)
- Check that C++11 or later is supported

### Issue: Agent gives incorrect advice
**Solution**:
- Provide more context about your specific problem
- Show the agent the error messages you're seeing
- Be more specific about what you want to achieve

## Advanced Features

### 1. **Multi-File Operations**
```
Request: "Refactor the RangeException class into a separate header file"
```

### 2. **Testing Assistance**
```
Request: "Generate comprehensive unit tests for the A2D class"
```

### 3. **Performance Optimization**
```
Request: "Suggest performance improvements for the array access operators"
```

### 4. **Code Generation**
```
Request: "Generate a 5D array class following the same pattern as A4D"
```

## Project-Specific Information

### About This Project
This repository implements **safe multidimensional arrays** based on a C++ Journal article. The key features are:
- Compile-time fixed-size arrays (A1D, A2D, A3D, A4D)
- Bounds checking with detailed exception messages
- Modern C++ practices (C++11 and later)
- Type-safe array access

### Key Files
- `SafeMultiD_Array_BasedOnCUJArticle.h` - Header with template classes
- `SafeMultiD_Array_BasedOnCUJArticle.cpp` - Main program with tests
- `UnitTests.cpp` - Unit test suite
- `README.md` - Project overview
- `CODING_AGENT_GUIDE.md` - This guide

### Design Patterns Used
- Template metaprogramming for compile-time array dimensions
- Exception handling for runtime bounds checking
- Nested template inheritance (A2D contains nested A1D instances, A3D contains A2D, etc.)

## Additional Resources

### GitHub Copilot Documentation
- [Official GitHub Copilot Docs](https://docs.github.com/en/copilot)
- [VS Code Copilot Extension](https://marketplace.visualstudio.com/items?itemName=GitHub.copilot)
- [Copilot Chat Guide](https://docs.github.com/en/copilot/github-copilot-chat/using-github-copilot-chat)

### C++ Resources
- [C++ Reference](https://en.cppreference.com/)
- [Modern C++ Features](https://github.com/AnthonyCalandra/modern-cpp-features)

## Quick Reference Card

| Task | Command |
|------|---------|
| Compile & Run | "Compile and run C++" |
| Build Only | "Compile this C++ file" |
| Explain Code | "Explain how [class/function] works" |
| Fix Bug | "Fix the [specific issue]" |
| Add Feature | "Add [feature description]" |
| Run Tests | "Run the unit tests" |
| Review Code | "Review this code for issues" |
| Generate Docs | "Add documentation to [class/function]" |

---

**Last Updated**: January 2026

For questions or issues with this guide, please open an issue in the repository.
