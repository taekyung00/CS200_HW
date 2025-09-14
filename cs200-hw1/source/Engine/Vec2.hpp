/**
 * \file
 * \author Jonathan Holmes
 * \author Taekyung Ho
 * \date 2025 Fall
 * \par CS200 Computer Graphics I
 * \copyright DigiPen Institute of Technology
 */

#pragma once
#include <iostream>
#include <limits>

namespace Math
{


    struct vec2;
    struct vec3;

    struct [[nodiscard]] ivec2
    {
        int x{ 0 };
        int y{ 0 };

        // Constructors
        constexpr ivec2() noexcept = default;
        constexpr ivec2(int _x, int _y) noexcept : x(_x), y(_y) { };
        // ivec2(const ivec2& rhs) = default;
        // constexpr ivec2(int xy) noexcept;

        // Conversion
        ivec2(const vec2& v) noexcept;

        // Arithmetic operators
        constexpr ivec2& operator+=(const ivec2& rhs) noexcept;
        constexpr ivec2& operator-=(const ivec2& rhs) noexcept;
        constexpr ivec2& operator*=(int scalar) noexcept;
        constexpr ivec2& operator/=(int scalar) noexcept;

        // Unary operators
        constexpr ivec2 operator+() const noexcept;
        constexpr ivec2 operator-() const noexcept;
    };

    // Non-member operators
    constexpr ivec2 operator+(const ivec2& lhs, const ivec2& rhs) noexcept;
    constexpr ivec2 operator-(const ivec2& lhs, const ivec2& rhs) noexcept;
    constexpr ivec2 operator*(const ivec2& v, int scalar) noexcept;
    constexpr ivec2 operator*(int scalar, const ivec2& v) noexcept;
    constexpr ivec2 operator/(const ivec2& v, int scalar) noexcept;

    // Comparison operators
    constexpr bool operator==(const ivec2& lhs, const ivec2& rhs) noexcept;
    constexpr bool operator!=(const ivec2& lhs, const ivec2& rhs) noexcept;

    // Stream operators
    std::ostream& operator<<(std::ostream& os, const ivec2& v);
    std::istream& operator>>(std::istream& is, ivec2& v);

    struct ivec3
    {
        int x{ 0 };
        int y{ 0 };
        int z{ 0 };

        // Constructors
        constexpr ivec3() noexcept = default;
        constexpr ivec3(int _x, int _y, int _z) noexcept : x(_x), y(_y), z(_z) { };
        ivec3(const ivec3& rhs) = default;
        // constexpr ivec3(int xy) noexcept;

        // Conversion
        ivec3(const vec3& v) noexcept;

        // Arithmetic operators
        constexpr ivec3& operator+=(const ivec3& rhs) noexcept;
        constexpr ivec3& operator-=(const ivec3& rhs) noexcept;
        constexpr ivec3& operator*=(int scalar) noexcept;
        constexpr ivec3& operator/=(int scalar) noexcept;

        // Unary operators
        constexpr ivec3 operator+() const noexcept;
        constexpr ivec3 operator-() const noexcept;
    };

    // Non-member operators
    constexpr ivec3 operator+(const ivec3& lhs, const ivec3& rhs) noexcept;
    constexpr ivec3 operator-(const ivec3& lhs, const ivec3& rhs) noexcept;
    constexpr ivec3 operator*(const ivec3& v, int scalar) noexcept;
    constexpr ivec3 operator*(int scalar, const ivec3& v) noexcept;
    constexpr ivec3 operator/(const ivec3& v, int scalar) noexcept;

    // Comparison operators
    constexpr bool operator==(const ivec3& lhs, const ivec3& rhs) noexcept;
    constexpr bool operator!=(const ivec3& lhs, const ivec3& rhs) noexcept;

    // Stream operators
    std::ostream& operator<<(std::ostream& os, const ivec3& v);
    std::istream& operator>>(std::istream& is, ivec3& v);

    struct vec2
    {
        double x{ 0 };
        double y{ 0 };

        // Constructors
        constexpr vec2() noexcept = default;
        constexpr vec2(double _x, double _y) noexcept : x(_x), y(_y) { };
        // constexpr vec2(const vec2& v) noexcept = default;
        vec2(const vec2& rhs) = default;
        // constexpr vec2(int xy) noexcept;

        // Conversion
        vec2(const ivec2& v) noexcept : x(static_cast<double>(v.x)), y(static_cast<double>(v.y)) { };

        // Arithmetic operators
        constexpr vec2& operator+=(const vec2& rhs) noexcept;
        constexpr vec2& operator-=(const vec2& rhs) noexcept;
        constexpr vec2& operator*=(int scalar) noexcept;
        constexpr vec2& operator/=(int scalar) noexcept;

        // Unary operators
        constexpr vec2 operator+() const noexcept;
        constexpr vec2 operator-() const noexcept;
    };

    // Non-member operators
    constexpr vec2 operator+(const vec2& lhs, const vec2& rhs) noexcept;
    constexpr vec2 operator-(const vec2& lhs, const vec2& rhs) noexcept;
    constexpr vec2 operator*(const vec2& v, int scalar) noexcept;
    constexpr vec2 operator*(int scalar, const vec2& v) noexcept;
    constexpr vec2 operator/(const vec2& v, int scalar) noexcept;

    // Comparison operators
    constexpr bool operator==(const vec2& lhs, const vec2& rhs) noexcept;
    constexpr bool operator!=(const vec2& lhs, const vec2& rhs) noexcept;

    // Stream operators
    std::ostream& operator<<(std::ostream& os, const vec2& v);
    std::istream& operator>>(std::istream& is, vec2& v);

    struct vec3
    {
        double x{ 0 };
        double y{ 0 };
        double z{ 0 };

        // Constructors
        constexpr vec3() noexcept = default;
        constexpr vec3(double _x, double _y, double _z) noexcept : x(_x), y(_y), z(_z) { };
        vec3(const vec3& rhs) = default;
        // constexpr vec3(int xy) noexcept;

        // Conversion
        vec3(const ivec3& v) noexcept : x(static_cast<double>(v.x)), y(static_cast<double>(v.y)), z(static_cast<double>(v.z)) { };

        // Arithmetic operators
        constexpr vec3& operator+=(const vec3& rhs) noexcept;
        constexpr vec3& operator-=(const vec3& rhs) noexcept;
        constexpr vec3& operator*=(int scalar) noexcept;
        constexpr vec3& operator/=(int scalar) noexcept;

        // Unary operators
        constexpr vec3 operator+() const noexcept;
        constexpr vec3 operator-() const noexcept;
    };

    // Non-member operators
    constexpr vec3 operator+(const vec3& lhs, const vec3& rhs) noexcept;
    constexpr vec3 operator-(const vec3& lhs, const vec3& rhs) noexcept;
    constexpr vec3 operator*(const vec3& v, int scalar) noexcept;
    constexpr vec3 operator*(int scalar, const vec3& v) noexcept;
    constexpr vec3 operator/(const vec3& v, int scalar) noexcept;

    // Comparison operators
    constexpr bool operator==(const vec3& lhs, const vec3& rhs) noexcept;
    constexpr bool operator!=(const vec3& lhs, const vec3& rhs) noexcept;

    // Stream operators
    std::ostream& operator<<(std::ostream& os, const vec3& v);
    std::istream& operator>>(std::istream& is, vec3& v);
}
