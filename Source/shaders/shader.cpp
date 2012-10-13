// Copyright 2012 The Ephenation Authors
//
// This file is part of Ephenation.
//
// Ephenation is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, version 3.
//
// Ephenation is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with Ephenation.  If not, see <http://www.gnu.org/licenses/>.
//

//
// This is a generic source for a shader. It must be inherited.
//
// TODO: dealloate using glDeleteProgram() and glDeleteShader()
//
#include <GL/glew.h>
#include <stdlib.h>
#include <stdio.h>

#include "shader.h"
#include "../uniformbuffer.h"
#include "../ui/Error.h"

void ShaderBase::Init(const char *debug, int vertexShaderLines, const char **vertexShaderSource, int fragmentShaderLines, const char **fragmentShaderSource) {
	GLuint vertexShader = compileShaderSource (GL_VERTEX_SHADER, vertexShaderLines, vertexShaderSource);
	GLuint fragmentShader = compileShaderSource (GL_FRAGMENT_SHADER, fragmentShaderLines, fragmentShaderSource);

	fProgram = createProgram(debug, vertexShader, fragmentShader);
	// TODO: glDeleteShader() could probably be called here.
	glUseProgram(fProgram);

#if 0
	// Enable this to show the list of attrib parameters
	GLint numAttrib;
	glGetProgramiv(fProgram, GL_ACTIVE_ATTRIBUTES, &numAttrib);
	for (int i=0; i< numAttrib; i++) {
		char buff[100];
		GLsizei len;
		GLint size;
		GLenum type;
		glGetActiveAttrib(fProgram, i, sizeof buff, &len, &size, &type, buff);
		printf("ShaderBase::Init Attribute %d: '%s', len %d, size %d, type %d\n", i, buff, len, size, type);
	}
#endif

	auto UBOidx = this->GetUniformBlockIndex("GlobalData");
	if (UBOidx != GL_INVALID_INDEX) {
		gUniformBuffer.UniformBlockBinding(fProgram, UBOidx);
	}

	this->GetLocations();
	glUseProgram(0);
}

GLint ShaderBase::GetUniformLocation(const char *name) const {
	return glGetUniformLocation(fProgram, name);
}

GLint ShaderBase::GetAttribLocation(const char *name) const {
	return glGetAttribLocation(fProgram, name);
}

GLuint ShaderBase::GetUniformBlockIndex(const char *name) const {
	return glGetUniformBlockIndex(fProgram, name);
}

ShaderBase::ShaderBase() : fProgram(0) {
}

void ShaderBase::compileAndCheck(GLuint shader) {
	GLint status;
	glCompileShader (shader);
	glGetShaderiv (shader, GL_COMPILE_STATUS, &status);
	if (status == GL_FALSE) {
		GLint infoLogLength;
		GLchar *infoLog;
		glGetShaderiv (shader, GL_INFO_LOG_LENGTH, &infoLogLength);
		infoLog = (GLchar*) malloc (infoLogLength);
		glGetShaderInfoLog (shader, infoLogLength, NULL, infoLog);
		fprintf (stderr, "compile log: %s\n", infoLog);
		free (infoLog);
	}
}

GLuint ShaderBase::compileShaderSource(GLenum type, GLsizei count, const GLchar **string) {
	GLuint shader = glCreateShader (type);
	glShaderSource (shader, count, string, NULL);
	compileAndCheck (shader);
	return shader;
}

void ShaderBase::linkAndCheck(const char *debug, GLuint program) {
	GLint status;
	glLinkProgram (program);
	glGetProgramiv (program, GL_LINK_STATUS, &status);
	if (status == GL_FALSE) {
		GLint infoLogLength;
		GLchar *infoLog;
		glGetProgramiv (program, GL_INFO_LOG_LENGTH, &infoLogLength);
		infoLog = (GLchar*) malloc (infoLogLength);
		glGetProgramInfoLog (program, infoLogLength, NULL, infoLog);
		fprintf (stderr, "link log %s: %s\n", debug, infoLog);
		ErrorDialog ("link log %s: %s\n", debug, infoLog);
		free (infoLog);
		exit(1);
	}
}

GLuint ShaderBase::createProgram(const char *debug, GLuint vertexShader, GLuint fragmentShader) {
	GLuint program = glCreateProgram ();
	if (vertexShader != 0) {
		glAttachShader (program, vertexShader);
	}
	if (fragmentShader != 0) {
		glAttachShader (program, fragmentShader);
	}
	this->PreLinkCallback(program);
	linkAndCheck(debug, program);
	return program;
}