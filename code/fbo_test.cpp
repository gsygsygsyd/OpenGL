#include "fbo_test.h"

#include <GLEW/glew.h>
#include <cstdio>

GLuint FBO;
GLuint Tex;
GLuint Depth;

void target_render()
{
	static float rquad = 0.0;
	glClearColor(1, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glViewport(0, 0, 256, 256);
	glLoadIdentity();							
	glScalef(0.4, 0.4, 0.4);
	glRotatef(rquad, 1.0f, 1.0f, 1.0f);			
	glBegin(GL_QUADS);							
	glColor3f(0.9f, 1.0f, 0.5f);				
	glVertex3f(1.0f, 1.0f, -1.0f);				
	glVertex3f(-1.0f, 1.0f, -1.0f);				
	glVertex3f(-1.0f, 1.0f, 1.0f);				
	glVertex3f(1.0f, 1.0f, 1.0f);

	glColor3f(0.8f, 0.8f, 0.8f);				
	glVertex3f(1.0f, -1.0f, 1.0f);				
	glVertex3f(-1.0f, -1.0f, 1.0f);				
	glVertex3f(-1.0f, -1.0f, -1.0f);			
	glVertex3f(1.0f, -1.0f, -1.0f);	

	glColor3f(0.2f, 0.2f, 0.2f);				
	glVertex3f(1.0f, 1.0f, 1.0f);				
	glVertex3f(-1.0f, 1.0f, 1.0f);				
	glVertex3f(-1.0f, -1.0f, 1.0f);				
	glVertex3f(1.0f, -1.0f, 1.0f);	

	glColor3f(0.5f, 0.5f, 0.5f);				
	glVertex3f(1.0f, -1.0f, -1.0f);				
	glVertex3f(-1.0f, -1.0f, -1.0f);			
	glVertex3f(-1.0f, 1.0f, -1.0f);				
	glVertex3f(1.0f, 1.0f, -1.0f);	

	glColor3f(0.0f, 0.0f, 0.0f);				
	glVertex3f(-1.0f, 1.0f, 1.0f);				
	glVertex3f(-1.0f, 1.0f, -1.0f);				
	glVertex3f(-1.0f, -1.0f, -1.0f);			
	glVertex3f(-1.0f, -1.0f, 1.0f);	

	glColor3f(1.0f, 1.0f, 1.0f);				
	glVertex3f(1.0f, 1.0f, -1.0f);				
	glVertex3f(1.0f, 1.0f, 1.0f);				
	glVertex3f(1.0f, -1.0f, 1.0f);				
	glVertex3f(1.0f, -1.0f, -1.0f);				
	glEnd();			

	rquad += 0.5f;
}

void render()
{
	glBindTexture(GL_TEXTURE_2D, Tex);
	glClearColor(0, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clear The Screen And The Depth Buffer
	glLoadIdentity();		
	glViewport(0, 0, 800, 800);
	glScalef(0.4, 0.4, 0.4);

	static float xrot = 0.0;
	static float yrot = 0.0;
	static float zrot = 0.0;
	glRotatef(xrot, 1.0f, 0.0f, 0.0f);
	glRotatef(yrot, 0.0f, 1.0f, 0.0f);
	glRotatef(zrot, 0.0f, 0.0f, 1.0f);


	glBegin(GL_QUADS);
	// Front Face
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, 1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
	// Back Face
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, -1.0f);
	// Top Face
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, 1.0f, 1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f);
	// Bottom Face
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, -1.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
	// Right face
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -1.0f, -1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, 1.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);
	// Left Face
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
	glEnd();

	xrot += 0.3f;
	yrot += 0.2f;
	zrot += 0.4f;

	glBindTexture(GL_TEXTURE_2D, 0);
}

void fbo_init()
{
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);

	glGenFramebuffers(1, &FBO);
	glBindFramebuffer(GL_DRAW_FRAMEBUFFER, FBO);

	glGenTextures(1, &Tex);
	glBindTexture(GL_TEXTURE_2D, Tex);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, 256, 256, 0, GL_RGBA, GL_FLOAT, 0);
	

	glGenRenderbuffers(1, &Depth);
	glBindRenderbuffer(GL_RENDERBUFFER, Depth);
	
	glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT32, 256, 256);

	glFramebufferTexture2D(GL_DRAW_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, Tex, 0);
	glFramebufferRenderbuffer(GL_DRAW_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, Depth);

	glBindTexture(GL_TEXTURE_2D, 0);
	glBindRenderbuffer(GL_RENDERBUFFER, 0);
	glBindFramebuffer(GL_DRAW_FRAMEBUFFER, 0);

	GLenum fbo_state = glCheckFramebufferStatus(GL_DRAW_FRAMEBUFFER);
	if (fbo_state != GL_FRAMEBUFFER_COMPLETE)
	{
		printf("fbo error\n");
	}

}

void fbo_draw(double t)
{
	glBindFramebuffer(GL_DRAW_FRAMEBUFFER, FBO);
	target_render();
	glBindFramebuffer(GL_DRAW_FRAMEBUFFER, 0);
	render();
}