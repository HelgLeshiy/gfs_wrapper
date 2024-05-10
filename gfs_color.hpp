/*
 * GFS. Color lib.
 *
 * FILE    gfs_color.hpp
 * AUTHOR  Ilya Akkuzin <gr3yknigh1@gmail.com>
 * COPYRIGHT Copyright (c) 2024 Ilya Akkuzin
 * */


#ifndef GFS_COLOR_HPP_INCLUDED
#define GFS_COLOR_HPP_INCLUDED

#include "gfs_types.hpp"
#include "gfs_macros.hpp"

struct Color4
{
    U8 B;
    U8 G;
    U8 R;
    U8 A;

    constexpr Color4(U8 r = 0, U8 g = 0, U8 b = 0, U8 a = 0) noexcept
        : R(r), G(g), B(b), A(a)
    { }

    constexpr Color4 operator+(const Color4 &other) const noexcept
    {
        return Color4(R+other.R, 
                      G+other.G, 
                      B+other.B, 
                      A+other.A);
    }
};


static_assert(sizeof(Color4) == sizeof(U32));

global_var constexpr Color4 COLOR_WHITE = Color4(MAX_U8, MAX_U8, MAX_U8, MAX_U8);
global_var constexpr Color4 COLOR_RED   = Color4(MAX_U8, 0, 0, 0);
global_var constexpr Color4 COLOR_GREEN = Color4(0, MAX_U8, 0, 0);
global_var constexpr Color4 COLOR_BLUE  = Color4(0, 0, MAX_U8, 0);
global_var constexpr Color4 COLOR_BLACK = Color4(0, 0, 0, 0);

global_var constexpr Color4 COLOR_YELLOW = COLOR_GREEN + COLOR_RED;


#endif // GFS_COLOR_HPP_INCLUDED

