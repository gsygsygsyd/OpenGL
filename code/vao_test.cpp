#include "vao_test.h"

#include <GLEW/glew.h>
#include "openglTools.h"

GLuint shader;
GLuint VAO;
GLuint VBO;

void vao_init()
{
	static GLfloat vVerts[] = { -0.5f, 0.0f, 0.0f,
		0.5f, 0.0f, 0.0f,
		0.0f, 0.5f, 0.0f };
	
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
	
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)* 9, vVerts, GL_DYNAMIC_DRAW);
	
	shader = gltLoadShaderPairWithAttributes("Identity.vp", "Identity.fp", 1, 0, "vVertex");
	GLuint pos = glGetAttribLocation(shader, "vVertex");
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void vao_draw(double t)
{
	glClearColor(0, 1, 1, 1);
	glUseProgram(shader);

	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, 3);

	glUseProgram(0);
}