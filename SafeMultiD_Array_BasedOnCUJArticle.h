#pragma once
#include <stdexcept>
#include <string>
#include <cstddef>

// ===============================================================
// RangeException
// ===============================================================
struct RangeException : public std::out_of_range {
    std::size_t dim;
    std::size_t low;
    std::size_t high;
    std::size_t index;

    static std::string build_message(std::size_t d,
                                     std::size_t l,
                                     std::size_t h,
                                     std::size_t i)
    {
        return "Index " + std::to_string(i) +
               " out of range [" + std::to_string(l) +
               "," + std::to_string(h) +
               "] for dim=" + std::to_string(d);
    }

    RangeException(std::size_t d,
                   std::size_t l,
                   std::size_t h,
                   std::size_t i)
        : std::out_of_range(build_message(d, l, h, i)),
          dim(d), low(l), high(h), index(i)
    {}
};

// ===============================================================
// A1D — Base 1D array with dimension index D
// ===============================================================
template <typename Type, std::size_t Size, int D = 1>
class A1D {
public:
    using value_type = Type;
    using reference = Type&;
    using const_reference = const Type&;

    static constexpr std::size_t size() noexcept { return Size; }
    static constexpr int dim() noexcept { return D; }

    constexpr std::size_t first_index() const noexcept { return 0; }
    constexpr std::size_t last_index() const noexcept { return (Size == 0 ? 0 : Size - 1); }

    reference operator[](std::size_t i) {
        if (i >= Size)
            throw RangeException(D, 0, Size - 1, i);
        return element[i];
    }

    const_reference operator[](std::size_t i) const {
        if (i >= Size)
            throw RangeException(D, 0, Size - 1, i);
        return element[i];
    }

private:
    Type element[Size];
};

// ===============================================================
// A2D — 2D array
// Correct dimension mapping:
//   arr[i]     → dim = 1
//   arr[i][j]  → dim = 2
// ===============================================================
template <typename Type, std::size_t size_1, std::size_t size_2>
class A2D : public A1D<A1D<Type, size_2, 2>, size_1, 1> {
public:
    static constexpr int Dim = 2;
    static constexpr std::size_t Size1 = size_1;
    static constexpr std::size_t Size2 = size_2;
};

// ===============================================================
// A3D — 3D array
// Correct dimension mapping:
//   arr[i]        → dim = 1
//   arr[i][j]     → dim = 2
//   arr[i][j][k]  → dim = 3
// ===============================================================
template <typename Type, std::size_t size_1, std::size_t size_2, std::size_t size_3>
class A3D : public A1D<A2D<Type, size_2, size_3>, size_1, 1> {
public:
    static constexpr int Dim = 3;
    static constexpr std::size_t Size1 = size_1;
    static constexpr std::size_t Size2 = size_2;
    static constexpr std::size_t Size3 = size_3;
};

// ===============================================================
// A4D — 4D array
// Correct dimension mapping:
//   arr[i]           → dim = 1
//   arr[i][j]        → dim = 2
//   arr[i][j][k]     → dim = 3
//   arr[i][j][k][m]  → dim = 4
// ===============================================================
template <typename Type,
          std::size_t s1, std::size_t s2, std::size_t s3, std::size_t s4>
class A4D : public A1D<A3D<Type, s2, s3, s4>, s1, 1> {
public:
    static constexpr int Dim = 4;
    static constexpr std::size_t Size1 = s1;
    static constexpr std::size_t Size2 = s2;
    static constexpr std::size_t Size3 = s3;
    static constexpr std::size_t Size4 = s4;
};

