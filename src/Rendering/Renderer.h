#pragma once

#include "../config.h"
#include "Objects/Mesh.h"

class Renderer
{
public:
    Renderer();
    ~Renderer();

    void start_frame();
    void end_frame(GLFWwindow *window) const;

    void draw(const Mesh &mesh) const;
    
    void wireframe_on() const;
    void wireframe_off() const;
    void set_arguments(int argc, char** argv);
};