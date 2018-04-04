#pragma once

#include <GL\gl3w.h>
#include "renderable2D.h"

namespace advent { namespace graphics {

#define RENDERER_MAX_SPRITES 10000
#define RENDERER_VERTEX_SIZE sizeof(VertexData)
#define RENDERER_SPRITE_SIZE RENDERER_VERTEX_SIZE * 4
#define RENDERER_BUFFER_SIZE RENDERER_SPRITE_SIZE * RENDERER_MAX_SPRITES
#define RENDERER_INDICES_SIZE RENDERER_MAX_SPRITES * 6

#define SHADER_VERTEX_INDEX 0
#define SHADER_COLOR_INDEX 1

	class BatchRenderer2D
	{

		private:

			GLuint m_VertexArray;
			GLuint m_IndexBuffer;
			GLuint m_Buffer;

			VertexData* m_VertexData;

			GLsizei m_IndexCount;

			void Init();

		public:

			BatchRenderer2D();
			~BatchRenderer2D();

			void begin();
			void submit (const Renderable2D* renderable);
			void end();
			void flush();

	};

} }