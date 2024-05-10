/*
 * GFS. Bitmap renderer.
 * 
 * Keeps one global backbuffer.
 *
 * FILE    gfs_bmr.hpp
 * AUTHOR  Ilya Akkuzin <gr3yknigh1@gmail.com>
 * LICENSE Copyright (c) 2024 Ilya Akkuzin
 * */

#ifndef GFS_BMR_HPP_INCLUDED
#define GFS_BMR_HPP_INCLUDED

#include <Windows.h>

#include "gfs_types.hpp"
#include "gfs_color.hpp"
#include "gfs_linalg.hpp"
#include "gfs_geometry.hpp"

// TODO(ilya.a): Parametrize it, if will be neccesery to change bytes per pixel
#define BMR_BPP 4

namespace BMR 
{
    /*
     * Actuall BitMap Renderer Renderer.
     */
    struct Renderer 
    {
        Color4 ClearColor;

        struct 
        {
            U8 *Begin;
            U8 *End;
        } CommandQueue;

        U64 CommandCount;

        U8 BPP;
        U64 XOffset;
        U64 YOffset;

        struct {
            void *Buffer;
            U64 Width;
            U64 Height;
        } Pixels;

        BITMAPINFO Info;
        HWND Window;
    };

	enum class RenderCommandType 
    {
	    NOP      = 00,
	    CLEAR    = 01,

	    LINE     = 10,
	    RECT     = 11,
	    GRADIENT = 20,
	};


	template<typename T>
	struct RenderCommand
    {
	    RenderCommandType Type;
	    T Payload;

	    constexpr 
	    RenderCommand(RenderCommandType type, 
	                  T                 payload) noexcept
	        : Type(type), Payload(payload)
	    { }
	};


	Renderer Init(Color4 clearColor = COLOR_BLACK) noexcept;
	void DeInit(Renderer *r) noexcept;

	void Update(Renderer *r, HWND window) noexcept;
	void Resize(Renderer *r, S32 w, S32 h) noexcept;

    void BeginDrawing(Renderer *r, HWND window) noexcept;
	void EndDrawing(Renderer *r) noexcept;

    void Clear(Renderer *r) noexcept;

    void DrawLine(Renderer *r, U32 x1, U32 y1, U32 x2, U32 y2) noexcept;
    void DrawLine(Renderer *r, V2U p1, V2U p2) noexcept;

	void DrawRect(Renderer *r, Rect r_, Color4 c) noexcept;
	void DrawRect(Renderer *r, U32 x, U32 y, U32 w, U32 h, Color4 c) noexcept;

	void DrawGrad(Renderer *r, U32 xOffset, U32 yOffset) noexcept;
	void DrawGrad(Renderer *r, V2U offset) noexcept;

};  // namespace BMR

#endif  // GFS_BMR_HPP_INCLUDED

