#include "frpch.h"

#include "FTexture.h"
#include "glad/glad.h"

namespace FracturedInternal::Render
{
	void FTexture::Generate(int width, int height, unsigned char* data)
	{
		if (data)
		{
			glEnable(GL_TEXTURE_2D);
			glGenTextures(1, &this->textureId);

			glBindTexture(GL_TEXTURE_2D, this->textureId);

			this->width = width;
			this->height = height;

			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);

			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);


			glBindTexture(GL_TEXTURE_2D, 0);
		}
	}

	void FTexture::Bind() const
	{
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, this->textureId);
	}
}
