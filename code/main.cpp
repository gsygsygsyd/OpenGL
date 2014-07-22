#define GLEW_STATIC
#include <GLEW/glew.h>
#include <GLFW/glfw3.h>
#include <cstdio>

#include "fbo_test.h"
#include "vao_test.h"

typedef void(*FUNC_INIT)();
typedef void(*FUNC_DRAW)(double);

FUNC_INIT opengl_init_array[100];
FUNC_DRAW opengl_draw_array[100];
int last_flag = 0;
void opengl_init()
{
	for (int i = 0; i < last_flag; i++)
	{
		(*opengl_init_array[i])();
	}
}

void opengl_draw(double t)
{
	for (int i = 0; i < last_flag; i++)
	{
		(*opengl_draw_array[i])(t);
	}
}

void register_func(FUNC_INIT init_func, FUNC_DRAW draw_func)
{
	if (last_flag > 99)
	{
		return;
	}
	opengl_init_array[last_flag] = init_func;
	opengl_draw_array[last_flag] = draw_func;
	last_flag++;
}

int main(void)
{

//	register_func(fbo_init, fbo_draw);
	register_func(vao_init, vao_draw);
	GLFWwindow* window;
	if (!glfwInit())
		return -1;

	window = glfwCreateWindow(800, 800, "Simple example", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	GLenum glew_err = glewInit();
	if (glew_err != GLEW_OK)
	{
		printf("%s\n", glewGetErrorString(glew_err));
		return -1;
	}

	opengl_init();

	while (!glfwWindowShouldClose(window))
	{
		opengl_draw(1);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);

	glfwTerminate();
	return 1;
}