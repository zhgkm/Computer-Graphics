#ifndef GRID_HPP
#define GRID_HPP

#include <glad/glad.h>

#include "diffuse_lighter.hpp"
#include "mesh3d.hpp"

// Draw a 2D grid, useful for debugging.

class Grid {
public:
    // Default constructor, to keep compiler happy.
    Grid();

    // Constructor.  Specifies the bottom-left corner
    // of the grid, its width and height, and the
    // spacing of its major and minor lines.
    // Also specifies a Flat_Lighter object that contains
    // a shader program to used by Mesh3d to draw the lines.
    Grid(float BLx, float BLy,
         float width, float height,
         float major_spacing,
         float minor_spacing,
         Diffuse_Lighter& shader);

    // Draw the grid
    void draw();

private:
    /////////////////////////
    // Meshes for drawing the vertical and horizontal lines
    ////////////////////////
    Mesh3d *h_line, *v_line;

    Diffuse_Lighter *lighter;

    void make_line_meshes();

    float BLx, BLy, width, height;
    float major_spacing, minor_spacing;
};
#endif
