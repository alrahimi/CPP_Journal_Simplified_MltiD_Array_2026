#pragma once

#include <cstddef>
#include <stdexcept>
#include <string>

// RangeException: stores the dimension, valid low/high range and the offending index.
// Inherits from std::out_of_range so it integrates with standard exception handling.
struct RangeException : std::out_of_range {
    std::size_t dim;
    std::size_t low;
    std::size_t high;
    std::size_t index;

    RangeException(std::size_t d, std::size_t l, std::size_t h, std::size_t i)
        : std::out_of_range(build_message(d, l, h, i)), dim(d), low(l), high(h), index(i) {}

private:
    static std::string build_message(std::size_t d, std::size_t l, std::size_t h, std::size_t i) {
        return "Dimension " + std::to_string(d) + ": subscript " + std::to_string(i) +
               " is out of range [" + std::to_string(l) + ":" + std::to_string(h) + "]";
    }
};

// 1D array template with checked access.
template <typename Type, std::size_t Size, int D = 1>
class A1D {
public:
    static constexpr int Dim = D;
    using value_type = Type;
    using reference = Type&;
    using const_reference = const Type&;
    static constexpr std::size_t size = Size;

    A1D() = default;

    reference operator[](std::size_t i) {
        if (i >= Size) throw RangeException(D, 0, Size - 1, i);
        return element[i];
    }

    const_reference operator[](std::size_t i) const {
        if (i >= Size) throw RangeException(D, 0, Size - 1, i);
        return element[i];
    }

    constexpr std::size_t begin() const noexcept { return 0; }
    constexpr std::size_t end()   const noexcept { return (Size == 0) ? 0 : (Size - 1); }
    static constexpr int dim() noexcept { return D; }

private:
    Type element[Size];
};

// 2D array: outer dimension size_1, inner dimension size_2
template <typename Type, std::size_t size_1, std::size_t size_2>
class A2D : public A1D<A1D<Type, size_2, 1>, size_1, 2> {
public:
    static constexpr int Dim = 2;
    static constexpr std::size_t Size1 = size_1;
    static constexpr std::size_t Size2 = size_2;
    using base = A1D<A1D<Type, size_2, 1>, size_1, 2>;
    using typename base::reference;
    static constexpr int dim() noexcept { return Dim; }
};

// 3D array: outer size_1, middle size_2, inner size_3
template <typename Type, std::size_t size_1, std::size_t size_2, std::size_t size_3>
class A3D : public A1D<A2D<Type, size_2, size_3>, size_1, 3> {
public:
    static constexpr int Dim = 3;
    static constexpr std::size_t Size1 = size_1;
    static constexpr std::size_t Size2 = size_2;
    static constexpr std::size_t Size3 = size_3;
    using base = A1D<A2D<Type, size_2, size_3>, size_1, 3>;
    static constexpr int dim() noexcept { return Dim; }
};

// 4D array: outer size_1, then size_2, size_3, size_4
template <typename Type, std::size_t size_1, std::size_t size_2, std::size_t size_3, std::size_t size_4>
class A4D : public A1D<A3D<Type, size_2, size_3, size_4>, size_1, 4> {
public:
    static constexpr int Dim = 4;
    using base = A1D<A3D<Type, size_2, size_3, size_4>, size_1, 4>;
    static constexpr int dim() noexcept { return Dim; }
};
