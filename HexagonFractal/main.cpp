// Include standard headers
#include <stdio.h>
#include <stdlib.h>
#include <vector>

// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <GLFW/glfw3.h>
GLFWwindow* window;

// GLM header file
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
using namespace glm;

// shaders header file
#include "shader.hpp"
#include <iostream>

// Vertex array object (VAO)
GLuint VertexArrayID;
GLuint VertexArrayID2;
GLuint VertexArrayID3;
GLuint VertexArrayID4;
GLuint VertexArrayID5;
GLuint VertexArrayID6;

// Vertex buffer object (VBO)
GLuint vertexbuffer;
GLuint vertexbuffer2;
GLuint vertexbuffer3;
GLuint vertexbuffer4;
GLuint vertexbuffer5;
GLuint vertexbuffer6;

// color buffer object (CBO)
GLuint colorbuffer;

// GLSL program from the shaders
GLuint programID;


GLint WindowWidth = 800;
GLint WindowHeight = 800;


//--------------------------------------------------------------------------------


float lerp(float v0, float v1, float t) {
    return (1 - t) * v0 + t * v1;
}


void fractal(GLfloat buffer[]) {
    for (int i = 0; i < 60; i++) {
        float x0 = buffer[3 * i];
        float x1 = buffer[3 * (i + 1)];
        buffer[3 * (i + 3)] = lerp(x0, x1, 0.1);
        float y0 = buffer[3 * i + 1];
        float y1 = buffer[3 * (i + 1) + 1];
        buffer[3 * (i + 3) + 1] = lerp(y0, y1, 0.1);
    }
}



void transferDataToGPUMemory(void)
{
    // VAO
    glGenVertexArrays(1, &VertexArrayID);
    glBindVertexArray(VertexArrayID);

    glGenVertexArrays(1, &VertexArrayID2);
    glBindVertexArray(VertexArrayID2);

    glGenVertexArrays(1, &VertexArrayID3);
    glBindVertexArray(VertexArrayID3);

    glGenVertexArrays(1, &VertexArrayID4);
    glBindVertexArray(VertexArrayID4);

    glGenVertexArrays(1, &VertexArrayID5);
    glBindVertexArray(VertexArrayID5);

    glGenVertexArrays(1, &VertexArrayID6);
    glBindVertexArray(VertexArrayID6);

    // Create and compile our GLSL program from the shaders
    programID = LoadShaders("SimpleVertexShader.vertexshader", "SimpleFragmentShader.fragmentshader");



    GLfloat g_vertex_buffer_data_cima[198] = {
         -16.0f, 0.0f, 0.0f,
         -8.0f, 16.0f, 0.0f,
          0.0f, 0.0f, 0.0f,
         -16.0f, 0.0f, 0.0f
    };

    fractal(g_vertex_buffer_data_cima);


    GLfloat g_vertex_buffer_data_cimaDir[198] = {
        -8.0f, 16.0f, 0.0f,
        8.0f, 16.0f, 0.0f,
        0.0f,0.0f,0.0f,
        -8.0f, 16.0f, 0.0f
    };

    fractal(g_vertex_buffer_data_cimaDir);

    GLfloat g_vertex_buffer_data_baixoDir[198] = {
         16.0f, 0.0f, 0.0f,
         8.0f, -16.0f, 0.0f,
         0.0f,0.0f,0.0f,
         16.0f, 0.0f, 0.0f
    };

    fractal(g_vertex_buffer_data_baixoDir);


    GLfloat g_vertex_buffer_data_baixo[198] = {
         8.0f, -16.0f, 0.0f,
         -8.0f, -16.0f, 0.0f,
         0.0f, 0.0f, 0.0f,
         8.0f, -16.0f,0.0f
    };

    fractal(g_vertex_buffer_data_baixo);

    GLfloat g_vertex_buffer_data_baixoEsq[198] = {
         -8.0f,-16.0f,0.0f,
         -16.0f, -0.0f, 0.0f,
         0.0f, 0.0f, 0.0f,
         -8.0f, -16.0f, 0.0f
    };

    fractal(g_vertex_buffer_data_baixoEsq);

    GLfloat g_vertex_buffer_data_cimaEsq[198] = {
        8.0f, 16.0f, 0.0f,
        16.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 0.0f,
        8.0f, 16.0f, 0.0f
    };

    fractal(g_vertex_buffer_data_cimaEsq);

    // One color for each vertex. They were generated randomly.
    static const GLfloat g_color_buffer_data[] = {
        0.0f,  0.0f,  0.0f,

    };


    // Move vertex data to video memory; specifically to VBO called vertexbuffer

    glGenBuffers(1, &vertexbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data_cima), g_vertex_buffer_data_cima, GL_STATIC_DRAW);


    glGenBuffers(1, &vertexbuffer2);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer2);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data_cimaDir), g_vertex_buffer_data_cimaDir, GL_STATIC_DRAW);


    glGenBuffers(1, &vertexbuffer3);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer3);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data_baixoDir), g_vertex_buffer_data_baixoDir, GL_STATIC_DRAW);


    glGenBuffers(1, &vertexbuffer4);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer4);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data_baixo), g_vertex_buffer_data_baixo, GL_STATIC_DRAW);


    glGenBuffers(1, &vertexbuffer5);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer5);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data_baixoEsq), g_vertex_buffer_data_baixoEsq, GL_STATIC_DRAW);


    glGenBuffers(1, &vertexbuffer6);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer6);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data_cimaEsq), g_vertex_buffer_data_cimaEsq, GL_STATIC_DRAW);


    // Move color data to video memory; specifically to CBO called colorbuffer
    glGenBuffers(1, &colorbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_color_buffer_data), g_color_buffer_data, GL_STATIC_DRAW);

}

//--------------------------------------------------------------------------------
void cleanupDataFromGPU()
{
    glDeleteBuffers(1, &vertexbuffer);
    glDeleteBuffers(1, &vertexbuffer2);
    glDeleteBuffers(1, &vertexbuffer3);
    glDeleteBuffers(1, &vertexbuffer4);
    glDeleteBuffers(1, &vertexbuffer5);
    glDeleteBuffers(1, &vertexbuffer6);
    glDeleteBuffers(1, &colorbuffer);
    glDeleteVertexArrays(1, &VertexArrayID);
    glDeleteVertexArrays(1, &VertexArrayID2);
    glDeleteVertexArrays(1, &VertexArrayID3);
    glDeleteVertexArrays(1, &VertexArrayID4);
    glDeleteVertexArrays(1, &VertexArrayID5);
    glDeleteVertexArrays(1, &VertexArrayID6);
    glDeleteProgram(programID);
}

//--------------------------------------------------------------------------------
void draw(void)
{
    // Clear the screen
    glClear(GL_COLOR_BUFFER_BIT);

    // Use our shader
    glUseProgram(programID);

    // define domain in R^2
    glm::mat4 mvp = glm::ortho(-40.0f, 40.0f, -40.0f, 40.0f);
    unsigned int matrix = glGetUniformLocation(programID, "mvp");
    glUniformMatrix4fv(matrix, 1, GL_FALSE, &mvp[0][0]);

    // 1rst attribute buffer : vertices
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    glVertexAttribPointer(
        0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
        3,                  // size
        GL_FLOAT,           // type
        GL_FALSE,           // normalized?
        0,                  // stride
        (void*)0            // array buffer offset
    );
    // 2nd attribute buffer : colors
    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
    glVertexAttribPointer(
        1,                                // attribute. No particular reason for 1, but must match the layout in the shader.
        3,                                // size
        GL_FLOAT,                         // type
        GL_FALSE,                         // normalized?
        0,                                // stride
        (void*)0                          // array buffer offset
    );

    // Draw the triangle !
    glDrawArrays(GL_LINE_LOOP, 0, 198); 
    
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);


    // 1rst attribute buffer : vertices
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer2);
    glVertexAttribPointer(
        0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
        3,                  // size
        GL_FLOAT,           // type
        GL_FALSE,           // normalized?
        0,                  // stride
        (void*)0            // array buffer offset
    );

    // 2nd attribute buffer : colors
    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
    glVertexAttribPointer(
        1,                                // attribute. No particular reason for 1, but must match the layout in the shader.
        3,                                // size
        GL_FLOAT,                         // type
        GL_FALSE,                         // normalized?
        0,                                // stride
        (void*)0                          // array buffer offset
    );



    glDrawArrays(GL_LINE_LOOP, 0, 198); // 3 indices starting at 0 -> 1 triangle
    //glDrawArrays(GL_POINTS, 0, 9); // 3 indices starting at 0 -> 1 triangle

    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);

    // 1rst attribute buffer : vertices
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer3);
    glVertexAttribPointer(
        0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
        3,                  // size
        GL_FLOAT,           // type
        GL_FALSE,           // normalized?
        0,                  // stride
        (void*)0            // array buffer offset
    );

    // 2nd attribute buffer : colors
    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
    glVertexAttribPointer(
        1,                                // attribute. No particular reason for 1, but must match the layout in the shader.
        3,                                // size
        GL_FLOAT,                         // type
        GL_FALSE,                         // normalized?
        0,                                // stride
        (void*)0                          // array buffer offset
    );



    glDrawArrays(GL_LINE_LOOP, 0, 198); // 3 indices starting at 0 -> 1 triangle
    //glDrawArrays(GL_POINTS, 0, 9); // 3 indices starting at 0 -> 1 triangle

    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);

    // 1rst attribute buffer : vertices
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer4);
    glVertexAttribPointer(
        0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
        3,                  // size
        GL_FLOAT,           // type
        GL_FALSE,           // normalized?
        0,                  // stride
        (void*)0            // array buffer offset
    );

    // 2nd attribute buffer : colors
    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
    glVertexAttribPointer(
        1,                                // attribute. No particular reason for 1, but must match the layout in the shader.
        3,                                // size
        GL_FLOAT,                         // type
        GL_FALSE,                         // normalized?
        0,                                // stride
        (void*)0                          // array buffer offset
    );



    glDrawArrays(GL_LINE_LOOP, 0, 198); // 3 indices starting at 0 -> 1 triangle
    //glDrawArrays(GL_POINTS, 0, 9); // 3 indices starting at 0 -> 1 triangle

    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);

    // 1rst attribute buffer : vertices
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer5);
    glVertexAttribPointer(
        0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
        3,                  // size
        GL_FLOAT,           // type
        GL_FALSE,           // normalized?
        0,                  // stride
        (void*)0            // array buffer offset
    );

    // 2nd attribute buffer : colors
    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
    glVertexAttribPointer(
        1,                                // attribute. No particular reason for 1, but must match the layout in the shader.
        3,                                // size
        GL_FLOAT,                         // type
        GL_FALSE,                         // normalized?
        0,                                // stride
        (void*)0                          // array buffer offset
    );



    glDrawArrays(GL_LINE_LOOP, 0, 198); // 3 indices starting at 0 -> 1 triangle
    //glDrawArrays(GL_POINTS, 0, 9); // 3 indices starting at 0 -> 1 triangle

    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);

    // 1rst attribute buffer : vertices
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer6);
    glVertexAttribPointer(
        0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
        3,                  // size
        GL_FLOAT,           // type
        GL_FALSE,           // normalized?
        0,                  // stride
        (void*)0            // array buffer offset
    );

    // 2nd attribute buffer : colors
    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
    glVertexAttribPointer(
        1,                                // attribute. No particular reason for 1, but must match the layout in the shader.
        3,                                // size
        GL_FLOAT,                         // type
        GL_FALSE,                         // normalized?
        0,                                // stride
        (void*)0                          // array buffer offset
    );



    glDrawArrays(GL_LINE_LOOP, 0, 198); // 3 indices starting at 0 -> 1 triangle
    //glDrawArrays(GL_POINTS, 0, 9); // 3 indices starting at 0 -> 1 triangle

    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
}
//--------------------------------------------------------------------------------



int main(void)
{
    // Initialise GLFW
    glfwInit();

    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Open a window
    window = glfwCreateWindow(WindowWidth, WindowHeight, "Hexagon fractal (base convex figure is the triangle)", NULL, NULL);

    // Create window context
    glfwMakeContextCurrent(window);

    // Initialize GLEW
    glewExperimental = true; // Needed for core profile
    glewInit();

    // Ensure we can capture the escape key being pressed below
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

    // White background
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);

    // transfer my data (vertices, colors, and shaders) to GPU side
    transferDataToGPUMemory();

    // render scene for each frame
    do {
        // drawing callback
        draw();


        // Swap buffers
        glfwSwapBuffers(window);

        // looking for events
        glfwPollEvents();

    } // Check if the ESC key was pressed or the window was closed
    while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
        glfwWindowShouldClose(window) == 0);


    // Cleanup VAO, VBOs, and shaders from GPU
    cleanupDataFromGPU();

    // Close OpenGL window and terminate GLFW
    glfwTerminate();

    return 0;
}

