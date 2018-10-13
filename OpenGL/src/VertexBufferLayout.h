#pragma once

#include "Renderer.h"
#include <vector>

struct VertexBufferElement {
	unsigned int count;
	unsigned int type;
	unsigned char normalized;

	static unsigned int GetSizeOfType(unsigned int type) {
		switch (type)
		{
			case GL_FLOAT:			return 4;
			case GL_UNSIGNED_INT:	return 4;
			case GL_UNSIGNED_BYTE:	return 1;
		}
        ASSERT(false);
		return 0;
	}
};

class VertexBufferLayout
{
private:
	std::vector<VertexBufferElement> m_Elements;
	unsigned int m_Stride;

public:
	VertexBufferLayout();
	~VertexBufferLayout();
	template<typename T> void Push(unsigned int count);
	const std::vector<VertexBufferElement> GetElements() const { return m_Elements; }
	unsigned int GetStride() const { return m_Stride; }
};



