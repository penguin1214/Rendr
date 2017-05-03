//
// Created by Jinglei Yang on 4/25/17.
//

#ifndef RENDR_WINDOW_H
#define RENDR_WINDOW_H

#include <GLFW/glfw3.h>
#include "renderer.h"

namespace Rendr {
    class Window {
    public:
        Window();

        Window(const size_t w, const size_t h);

        ~Window();

        void init();
        void start();
        void set_renderer(Renderer* renderer);

    private:
        static size_t width_;
        static size_t height_;
        static int buffer_width_;
        static int buffer_height_;
        static Renderer* renderer_;    // declaration
        static GLFWwindow* window_;

        static void update();

        static void err_callback( int error, const char* description );
        static void key_callback( GLFWwindow* window, int key, int scancode, int action, int mods );
        static void resize_callback( GLFWwindow* window, int width, int height );
        static void cursor_callback( GLFWwindow* window, double xpos, double ypos );
        static void scroll_callback( GLFWwindow* window, double xoffset, double yoffset);
        static void mouse_button_callback( GLFWwindow* window, int button, int action, int mods );
    };
}

#endif //RENDR_WINDOW_H
