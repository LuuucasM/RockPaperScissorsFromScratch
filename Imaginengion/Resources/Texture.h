#pragma once

#include <GLFW/glfw3.h>

class Texture2D {
public:
	unsigned int ID;
	unsigned int Width, Height;
	unsigned int Internal_Format;
	unsigned int Image_Format;
	unsigned int Wrap_S;
	unsigned int Wrap_T;
	unsigned int Filter_Min;
	unsigned int Filter_Max;
	Texture2D()
		: Width(0), Height(0), Internal_Format(GL_RGB), Image_Format(GL_RGB), Wrap_S(GL_REPEAT), Wrap_T(GL_REPEAT), Filter_Min(GL_LINEAR), Filter_Max(GL_LINEAR) {
		glGenTextures(1, &ID);
	}
	void Generate(unsigned int width, unsigned int height, unsigned char* data) {
		Width = width;
		Height = height;

		//create texture
		glBindTexture(GL_TEXTURE_2D, ID);
		glTexImage2D(GL_TEXTURE_2D, 0, Internal_Format, width, height, 0, Image_Format, GL_UNSIGNED_BYTE, data);

		//set texture parameters
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, Wrap_S);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, Wrap_S);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, Filter_Min);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, Filter_Max);

		//unbined texture
		glBindTexture(GL_TEXTURE_2D, 0);

	}
	void Bind() const {
		glBindTexture(GL_TEXTURE_2D, ID);
	}
};