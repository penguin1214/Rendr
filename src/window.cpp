//
// Created by Jinglei Yang on 4/25/17.
//

#include <iostream>
#include <sstream>
#include <GL/glew.h>
#include "window.h"

namespace Rendr {

    Renderer *Window::renderer_;
    GLFWwindow *Window::window_;
    size_t Window::width_;
    size_t Window::height_;
    int Window::buffer_width_;
    int Window::buffer_height_;

    Window::Window() {}

    Window::Window(const size_t w, const size_t h) {
        width_ = w;
        height_ = h;
    }

    Window::~Window() {
        glfwDestroyWindow(window_);
        glfwTerminate();
        delete (renderer_);
    }

    void Window::init() {
        glfwSetErrorCallback(err_callback);
        if (!glfwInit()) exit(EXIT_FAILURE);

        window_ = glfwCreateWindow(width_, height_, "Rendr", NULL, NULL);
        if (!window_) {
            glfwTerminate();
            exit(1);
        }

        glfwMakeContextCurrent(window_);

        glfwSetFramebufferSizeCallback(window_, resize_callback);
        glfwSetKeyCallback(window_, key_callback);
        glfwSetCursorPosCallback(window_, cursor_callback);
        glfwSetScrollCallback(window_, scroll_callback);
        glfwSetMouseButtonCallback(window_, mouse_button_callback);

        if (glewInit() != GLEW_OK) {
            std::cout << "Error: could not initialize GLEW!" << std::endl;
            glfwTerminate();
            exit( 1 );
        }

        // enable alpha blending
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        glfwSwapInterval(1);

        resize_callback(window_, buffer_width_, buffer_height_);
    }

    void Window::start() {
        while(!glfwWindowShouldClose(window_)){
            update();
        }
    }

    void Window::update() {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        if (renderer_) {
            renderer_->render();
        }
        glfwSwapBuffers(window_);

        glfwPollEvents();
    }

    void Window::set_renderer(Renderer *renderer) {
        this->renderer_ = renderer;
    }

    void Window::err_callback(int error, const char *description) {
        std::cout << "GLFW Error: " << description;
    }

    void Window::key_callback(GLFWwindow *window, int key, int scancode, int action, int mods) {
        if (action == GLFW_PRESS) {
            if( key == GLFW_KEY_ESCAPE ) {
                glfwSetWindowShouldClose( window, true );
            }
        }
    }

    void Window::resize_callback(GLFWwindow *window, int width, int height) {
        glfwGetFramebufferSize(window_, &width, &height);
        glViewport(0, 0, buffer_width_, buffer_height_);
        if (renderer_) renderer_->resize(buffer_width_, buffer_height_);
    }

    void Window::cursor_callback(GLFWwindow *window, double xpos, double ypos) {}

    void Window::scroll_callback(GLFWwindow *window, double xoffset, double yoffset) {}

    void Window::mouse_button_callback(GLFWwindow *window, int button, int action, int mods) {}

}