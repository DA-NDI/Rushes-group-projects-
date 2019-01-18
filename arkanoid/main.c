/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolgin <avolgin@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 18:42:48 by avolgin           #+#    #+#             */
/*   Updated: 2019/01/05 18:37:48 by avolgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"
float player[] = {-0.1, -1, -0.1, -0.9, 0.1, -0.9, 0.1, -1};
float ball[] = {-0.05, -0.9, -0.07, -0.85, 0, -0.8, 0.07, -0.85, 0.05, -0.9};

void error_callback(int error, const char* description)
{
    ft_printf("Error: %s\n", description);
	error = 0;
}

void	move_player(int direction)
{
	if (direction == 1)
	{
		player[0] -= 0.1;
		player[2] -= 0.1;
		player[4] -= 0.1;
		player[6] -= 0.1;
	}
	else if (direction == 2)
	{
		player[0] += 0.1;
		player[2] += 0.1;
		player[4] += 0.1;
		player[6] += 0.1;
	}
}

static void key_callback(GLFWwindow* win, int key, \
			__attribute__((unused)) int code, int act, \
			__attribute__((unused)) int mod)
{
    if (key == GLFW_KEY_ESCAPE && act == GLFW_PRESS)
        glfwSetWindowShouldClose(win, GLFW_TRUE);
    if (key == GLFW_KEY_LEFT && act == GLFW_PRESS)
        move_player(1);
    else if (key == GLFW_KEY_RIGHT && act == GLFW_PRESS)
        move_player(2);
}

void	set_viewport(GLFWwindow *window)
{
	int 	width;
	int		height;

	glfwGetFramebufferSize(window, &width, &height);
	glViewport(0, 0, width, height);
}

void	draw_block(float *vertices)
{
		glBegin(GL_QUADS);
		glVertex3f(vertices[0], vertices[1],0);
		glVertex3f(vertices[2], vertices[3],0);
		glVertex3f(vertices[4], vertices[5],0);
		glVertex3f(vertices[6], vertices[7],0);
		glEnd();
}

void	draw_ball(float *vertices)
{
		glBegin(GL_POLYGON);
		glVertex3f(vertices[0], vertices[1],0);
		glVertex3f(vertices[2], vertices[3],0);
		glVertex3f(vertices[4], vertices[5],0);
		glVertex3f(vertices[6], vertices[7],0);
		glVertex3f(vertices[8], vertices[9],0);
		glEnd();
}

int		main(int argc, char **argv)
{
	GLFWwindow*	window;
	double		time;
	
    if (!glfwInit())
        return -1;
	glfwSetErrorCallback(error_callback);
	glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);
    if (!(window = glfwCreateWindow(640, 480, "Arkanoid", NULL, NULL)))
    {
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
	set_viewport(window);
	time = glfwGetTime();
	glfwSwapInterval(1);
	float block1[] = {0, 0, 0, 0.5, 0.5, 0.5, 0.5, 0};
	float block2[] = {-0.1, 0, -0.1, 0.5, -0.5, 0.5, -0.5, 0};
	float block3[] = {0, 0, 0, 0.5, 0.5, 0.5, 0.5, 0};

    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);
		draw_block(block1);
		draw_block(block2);
		draw_block(block3);
		draw_block(player);
		draw_ball(ball);
        glfwSwapBuffers(window);
        glfwPollEvents();
		glfwSetKeyCallback(window, key_callback);
    }
    glfwTerminate();
	return (0);
}

/* void framebuffer_size_callback(GLFWwindow* window, int width, int height); */
/* void processInput(GLFWwindow *window); */

/* // settings */
/* const unsigned int SCR_WIDTH = 800; */
/* const unsigned int SCR_HEIGHT = 600; */

/* const char *vertexShaderSource = "#version 330 core\n" */
/*     "layout (location = 0) in vec3 aPos;\n" */
/*     "void main()\n" */
/*     "{\n" */
/*     "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n" */
/*     "}\0"; */
/* const char *fragmentShaderSource = "#version 330 core\n" */
/*     "out vec4 FragColor;\n" */
/*     "void main()\n" */
/*     "{\n" */
/*     "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n" */
/*     "}\n\0"; */

/* int main() */
/* { */
/*     // glfw: initialize and configure */
/*     // ------------------------------ */
/*     glfwInit(); */
/*     glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); */
/*     glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); */
/*     glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); */
/*     glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // uncomment this statement to fix compilation on OS X */
/*     // glfw window creation */
/*     // -------------------- */
/*     GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL); */
/*     if (window == NULL) */
/*     { */
/*         glfwTerminate(); */
/*         return -1; */
/*     } */
/*     glfwMakeContextCurrent(window); */
/*     glfwSetFramebufferSizeCallback(window, framebuffer_size_callback); */

/*     // build and compile our shader program */
/*     // ------------------------------------ */
/*     // vertex shader */
/*     int vertexShader = glCreateShader(GL_VERTEX_SHADER); */
/*     glShaderSource(vertexShader, 1, &vertexShaderSource, NULL); */
/*     glCompileShader(vertexShader); */
/*     // check for shader compile errors */
/*     int success; */
/*     char infoLog[512]; */
/*     glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success); */
/*     if (!success) */
/*     { */
/*         glGetShaderInfoLog(vertexShader, 512, NULL, infoLog); */
/*     } */
/*     // fragment shader */
/*     int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER); */
/*     glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL); */
/*     glCompileShader(fragmentShader); */
/*     // check for shader compile errors */
/*     glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success); */
/*     if (!success) */
/*     { */
/*         glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog); */
/*     } */
/*     // link shaders */
/*     int shaderProgram = glCreateProgram(); */
/*     glAttachShader(shaderProgram, vertexShader); */
/*     glAttachShader(shaderProgram, fragmentShader); */
/*     glLinkProgram(shaderProgram); */
/*     // check for linking errors */
/*     glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success); */
/*     if (!success) { */
/*         glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog); */
/*     } */
/*     glDeleteShader(vertexShader); */
/*     glDeleteShader(fragmentShader); */

/*     // set up vertex data (and buffer(s)) and configure vertex attributes */
/*     // ------------------------------------------------------------------ */
/* float vertices[] = { */
/*     // first triangle */
/*      0.2f,  0.2f, 0.0f,  // top right */
/*      0.2f, -0.2f, 0.0f,  // bottom right */
/*     -0.2f,  0.2f, 0.0f,  // top left  */
/*     // second triangle */
/*      0.2f, -0.2f, 0.0f,  // bottom right */
/*     -0.2f, -0.2f, 0.0f,  // bottom left */
/* 	 -0.2f,  0.2f, 0.0f,   // top left */

/*      0.8f,  0.2f, 0.0f,  // top right */
/*      0.8f, -0.2f, 0.0f,  // bottom right */
/*     0.7f,  0.2f, 0.0f,  // top left  */
/*     // second triangle */
/*      0.7f, 0.2f, 0.0f,  // bottom right */
/*     0.7f, -0.2f, 0.0f,  // bottom left */
/*     0.8f,  0.2f, 0.0f   // top left */
/* };  */
/*     unsigned int VBO, VAO; */
/*     glGenVertexArrays(1, &VAO); */
/*     glGenBuffers(1, &VBO); */
/*     // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s). */
/*     glBindVertexArray(VAO); */

/*     glBindBuffer(GL_ARRAY_BUFFER, VBO); */
/*     glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW); */

/*     glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0); */
/*     glEnableVertexAttribArray(0); */

/*     // note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind */
/*     glBindBuffer(GL_ARRAY_BUFFER, 0);  */

/*     // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other */
/*     // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary. */
/*     glBindVertexArray(0);  */


/*     // uncomment this call to draw in wireframe polygons. */
/*     //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); */

/*     while (!glfwWindowShouldClose(window)) */
/*     { */
/*         processInput(window); */
/*         glClearColor(0.2f, 0.3f, 0.3f, 1.0f); */
/*         glClear(GL_COLOR_BUFFER_BIT); */

/*         // draw our first triangle */
/*         glUseProgram(shaderProgram); */
/*         glBindVertexArray(VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized */
/*         glDrawArrays(GL_TRIANGLES, 0, 12); */
/*         glfwSwapBuffers(window); */
		
/*         glfwPollEvents(); */
/*     } */
/*     glDeleteVertexArrays(1, &VAO); */
/*     glDeleteBuffers(1, &VBO); */
/*     glfwTerminate(); */
/*     return 0; */
/* } */

/* void processInput(GLFWwindow *window) */
/* { */
/*     if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) */
/*         glfwSetWindowShouldClose(window, 1); */
/* } */

/* void framebuffer_size_callback(GLFWwindow* window, int width, int height) */
/* { */
/*     // make sure the viewport matches the new window dimensions; note that width and  */
/*     // height will be significantly larger than specified on retina displays. */
/*     glViewport(0, 0, width, height); */
/* } */
