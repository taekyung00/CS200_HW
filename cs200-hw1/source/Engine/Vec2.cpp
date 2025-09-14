/**
 * \file
 * \author Jonathan Holmes
 * \author Taekyung Ho
 * \date 2025 Fall
 * \par CS200 Computer Graphics I
 * \copyright DigiPen Institute of Technology
 */

#include "Vec2.hpp"
#include <cmath>

namespace Math
{
    ivec2::ivec2(const vec2& v) noexcept : x(static_cast<int>(v.x)), y(static_cast<int>(v.y))
    {
    }

    constexpr ivec2& ivec2::operator+=(const ivec2& rhs) noexcept
    {
        x += rhs.x;
        y += rhs.y;
        return *this;
    }

    constexpr ivec2& ivec2::operator-=(const ivec2& rhs) noexcept
    {
        x -= rhs.x;
        y -= rhs.y;
        return *this;
    }

    constexpr ivec2& ivec2::operator*=(int scalar) noexcept
    {
        x *= scalar;
        y *= scalar;
        return *this;
    }

    constexpr ivec2& ivec2::operator/=(int scalar) noexcept
    {
        x /= scalar;
        y /= scalar;
        return *this;
    }

    constexpr ivec2 ivec2::operator+() const noexcept
    {
        ivec2 new_vec{ this->x, this->y };
        return new_vec;
    }

    constexpr ivec2 ivec2::operator-() const noexcept
    {
        ivec2 new_vec{ -this->x, -this->y };
        return new_vec;
    }

    constexpr ivec2 operator+(const ivec2& lhs, const ivec2& rhs) noexcept
    {
        ivec2 new_vec{ lhs.x + rhs.x, lhs.y + rhs.y };
        return new_vec;
    }

    constexpr ivec2 operator-(const ivec2& lhs, const ivec2& rhs) noexcept
    {
        ivec2 new_vec{ lhs.x - rhs.x, lhs.y - rhs.y };
        return new_vec;
    }

    constexpr ivec2 operator*(const ivec2& v, int scalar) noexcept
    {
        ivec2 new_vec{ v.x * scalar, v.y * scalar };
        return new_vec;
    }

    constexpr ivec2 operator*(int scalar, const ivec2& v) noexcept
    {
        ivec2 new_vec{ v.x * scalar, v.y * scalar };
        return new_vec;
    }

    constexpr ivec2 operator/(const ivec2& v, int scalar) noexcept
    {
        ivec2 new_vec{ v.x / scalar, v.y / scalar };
        return new_vec;
    }

    constexpr bool operator==(const ivec2& lhs, const ivec2& rhs) noexcept
    {
        return (lhs.x == rhs.x) && (lhs.y == rhs.y);
    }

    constexpr bool operator!=(const ivec2& lhs, const ivec2& rhs) noexcept
    {
        return !(lhs == rhs);
    }

    std::ostream& operator<<(std::ostream& os, const ivec2& v)
    {
        os << v.x << ", " << v.y << "\n";
        return os;
    }

    std::istream& operator>>(std::istream& is, ivec2& v)
    {
        is >> v.x >> v.y;
        return is;
    }

    /*===============================ivec3==================================*/

    ivec3::ivec3(const vec3& v) noexcept : x(static_cast<int>(v.x)), y(static_cast<int>(v.y)), z(static_cast<int>(v.z))
    {
    }

    constexpr ivec3& ivec3::operator+=(const ivec3& rhs) noexcept
    {
        x += rhs.x;
        y += rhs.y;
        z += rhs.z;
        return *this;
    }

    constexpr ivec3& ivec3::operator-=(const ivec3& rhs) noexcept
    {
        x -= rhs.x;
        y -= rhs.y;
        z -= rhs.z;
        return *this;
    }

    constexpr ivec3& ivec3::operator*=(int scalar) noexcept
    {
        x *= scalar;
        y *= scalar;
        z *= scalar;
        return *this;
    }

    constexpr ivec3& ivec3::operator/=(int scalar) noexcept
    {
        x /= scalar;
        y /= scalar;
        z /= scalar;
        return *this;
    }

    constexpr ivec3 ivec3::operator+() const noexcept
    {
        ivec3 new_vec{ this->x, this->y, this->z };
        return new_vec;
    }

    constexpr ivec3 ivec3::operator-() const noexcept
    {
        ivec3 new_vec{ -this->x, -this->y, -this->z };
        return new_vec;
    }

    constexpr ivec3 operator+(const ivec3& lhs, const ivec3& rhs) noexcept
    {
        ivec3 new_vec{ lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z };
        return new_vec;
    }

    constexpr ivec3 operator-(const ivec3& lhs, const ivec3& rhs) noexcept
    {
        ivec3 new_vec{ lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z };
        return new_vec;
    }

    constexpr ivec3 operator*(const ivec3& v, int scalar) noexcept
    {
        ivec3 new_vec{ v.x * scalar, v.y * scalar, v.z * scalar };
        return new_vec;
    }

    constexpr ivec3 operator*(int scalar, const ivec3& v) noexcept
    {
        ivec3 new_vec{ v.x * scalar, v.y * scalar, v.z * scalar };
        return new_vec;
    }

    constexpr ivec3 operator/(const ivec3& v, int scalar) noexcept
    {
        ivec3 new_vec{ v.x / scalar, v.y / scalar, v.z / scalar };
        return new_vec;
    }

    constexpr bool operator==(const ivec3& lhs, const ivec3& rhs) noexcept
    {
        return (lhs.x == rhs.x) && (lhs.y == rhs.y) && (lhs.z == rhs.z);
    }

    constexpr bool operator!=(const ivec3& lhs, const ivec3& rhs) noexcept
    {
        return !(lhs == rhs);
    }

    std::ostream& operator<<(std::ostream& os, const ivec3& v)
    {
        os << v.x << ", " << v.y << v.z << "\n";
        return os;
    }

    std::istream& operator>>(std::istream& is, ivec3& v)
    {
        is >> v.x >> v.y >> v.z;
        return is;
    }

    /*===========================vec2=================================================*/
    constexpr vec2& vec2::operator+=(const vec2& rhs) noexcept
    {
        x += rhs.x;
        y += rhs.y;
        return *this;
    }

    constexpr vec2& vec2::operator-=(const vec2& rhs) noexcept
    {
        x -= rhs.x;
        y -= rhs.y;
        return *this;
    }

    constexpr vec2& vec2::operator*=(int scalar) noexcept
    {
        x *= scalar;
        y *= scalar;
        return *this;
    }

    constexpr vec2& vec2::operator/=(int scalar) noexcept
    {
        x /= scalar;
        y /= scalar;
        return *this;
    }

    constexpr vec2 vec2::operator+() const noexcept
    {
        vec2 new_vec{ this->x, this->y };
        return new_vec;
    }

    constexpr vec2 vec2::operator-() const noexcept
    {
        vec2 new_vec{ -this->x, -this->y };
        return new_vec;
    }

    constexpr vec2 operator+(const vec2& lhs, const vec2& rhs) noexcept
    {
        vec2 new_vec{ lhs.x + rhs.x, lhs.y + rhs.y };
        return new_vec;
    }

    constexpr vec2 operator-(const vec2& lhs, const vec2& rhs) noexcept
    {
        vec2 new_vec{ lhs.x - rhs.x, lhs.y - rhs.y };
        return new_vec;
    }

    constexpr vec2 operator*(const vec2& v, int scalar) noexcept
    {
        vec2 new_vec{ v.x * scalar, v.y * scalar };
        return new_vec;
    }

    constexpr vec2 operator*(int scalar, const vec2& v) noexcept
    {
        vec2 new_vec{ v.x * scalar, v.y * scalar };
        return new_vec;
    }

    constexpr vec2 operator/(const vec2& v, int scalar) noexcept
    {
        vec2 new_vec{ v.x / scalar, v.y / scalar };
        return new_vec;
    }

    constexpr bool operator==(const vec2& lhs, const vec2& rhs) noexcept
    {
        return (lhs.x == rhs.x) && (lhs.y == rhs.y);
    }

    constexpr bool operator!=(const vec2& lhs, const vec2& rhs) noexcept
    {
        return !(lhs == rhs);
    }

    std::ostream& operator<<(std::ostream& os, const vec2& v)
    {
        os << v.x << ", " << v.y << "\n";
        return os;
    }

    std::istream& operator>>(std::istream& is, vec2& v)
    {
        is >> v.x >> v.y;
        return is;
    }

    /*===============================vec3==================================*/
    constexpr vec3& vec3::operator+=(const vec3& rhs) noexcept
    {
        x += rhs.x;
        y += rhs.y;
        z += rhs.z;
        return *this;
    }

    constexpr vec3& vec3::operator-=(const vec3& rhs) noexcept
    {
        x -= rhs.x;
        y -= rhs.y;
        z -= rhs.z;
        return *this;
    }

    constexpr vec3& vec3::operator*=(int scalar) noexcept
    {
        x *= scalar;
        y *= scalar;
        z *= scalar;
        return *this;
    }

    constexpr vec3& vec3::operator/=(int scalar) noexcept
    {
        x /= scalar;
        y /= scalar;
        z /= scalar;
        return *this;
    }

    constexpr vec3 vec3::operator+() const noexcept
    {
        vec3 new_vec{ this->x, this->y, this->z };
        return new_vec;
    }

    constexpr vec3 vec3::operator-() const noexcept
    {
        vec3 new_vec{ -this->x, -this->y, -this->z };
        return new_vec;
    }

    constexpr vec3 operator+(const vec3& lhs, const vec3& rhs) noexcept
    {
        vec3 new_vec{ lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z };
        return new_vec;
    }

    constexpr vec3 operator-(const vec3& lhs, const vec3& rhs) noexcept
    {
        vec3 new_vec{ lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z };
        return new_vec;
    }

    constexpr vec3 operator*(const vec3& v, int scalar) noexcept
    {
        vec3 new_vec{ v.x * scalar, v.y * scalar, v.z * scalar };
        return new_vec;
    }

    constexpr vec3 operator*(int scalar, const vec3& v) noexcept
    {
        vec3 new_vec{ v.x * scalar, v.y * scalar, v.z * scalar };
        return new_vec;
    }

    constexpr vec3 operator/(const vec3& v, int scalar) noexcept
    {
        vec3 new_vec{ v.x / scalar, v.y / scalar, v.z / scalar };
        return new_vec;
    }

    constexpr bool operator==(const vec3& lhs, const vec3& rhs) noexcept
    {
        return (lhs.x == rhs.x) && (lhs.y == rhs.y) && (lhs.z == rhs.z);
    }

    constexpr bool operator!=(const vec3& lhs, const vec3& rhs) noexcept
    {
        return !(lhs == rhs);
    }

    std::ostream& operator<<(std::ostream& os, const vec3& v)
    {
        os << v.x << ", " << v.y << v.z << "\n";
        return os;
    }

    std::istream& operator>>(std::istream& is, vec3& v)
    {
        is >> v.x >> v.y >> v.z;
        return is;
    }
}
