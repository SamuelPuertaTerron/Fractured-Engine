#pragma once

namespace FracturedInternal::Render
{
	class FTexture
	{
	public:
		FTexture() = default;

		void Generate(int width, int height, unsigned char* data);
		void Bind() const;
	public:
		fint32 textureId;
		fint32 width, height;
	};
}


