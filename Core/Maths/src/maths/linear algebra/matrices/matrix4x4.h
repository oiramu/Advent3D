#pragma once

namespace Advent3D { namespace Maths {

	struct Matrix4x4
	{
		float elements[4*4];

		Matrix4x4();
		Matrix4x4(float diagonal);

		static Matrix4x4 Identity(); //TODO:


	};


} }