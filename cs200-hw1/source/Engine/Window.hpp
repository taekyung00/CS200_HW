/**
 * \file
 * \author Rudy Castan
 * \author Jonathan Holmes
 * \author Taekyung Ho
 * \date 2025 Fall
 * \par CS200 Computer Graphics I
 * \copyright DigiPen Institute of Technology
 */

#pragma once
#include "CS200/RGBA.hpp"
#include "Vec2.hpp"
#include <functional>
#include <gsl/gsl>
#include <string_view>

struct SDL_Window;
typedef void*           SDL_GLContext;
typedef union SDL_Event SDL_Event;

namespace CS230
{
    class Window
    {
    public:
        void Start(std::string_view title); // Initialize SDL, window, and OpenGL
        void Update();                      // Swap buffers and process events
        bool IsClosed() const;              // Check if window should close

        Math::ivec2 GetSize() const noexcept
        {
            return size;
        }; // Return current window dimensions

        void          Clear(CS200::RGBA color);                           // Clear screen with specified color
        void          ForceResize(int desired_width, int desired_height); // Force window resize (web compatibility)
        SDL_Window*   GetSDLWindow() const;
        SDL_GLContext GetGLContext() const;

        using WindowEventCallback = std::function<void(const SDL_Event&)>;
        void SetEventCallback(WindowEventCallback callback); // Register event callback for Input

        Window() = default;
        ~Window();

        Window(const Window&)                = delete;
        Window& operator=(const Window&)     = delete;
        Window(Window&&) noexcept            = delete;
        Window& operator=(Window&&) noexcept = delete;
        void    Stop() noexcept;

        // void SetBackgroundColor(Math::vec3 color) noexcept;
    private:
        void setupSDLWindow(std::string_view title);
        void setupOpenGL();

        // Platform-specific members
        gsl::owner<SDL_Window*>   sdlWindow = nullptr;
        gsl::owner<SDL_GLContext> glContext = nullptr;
        Math::ivec2               size{ 800, 600 };
        WindowEventCallback       eventCallback;
        bool                      is_closed = false;

        // Constants
        static constexpr int         default_width  = 800;
        static constexpr int         default_height = 600;
        static constexpr CS200::RGBA default_background{ CS200::WHITE };
    };
}
