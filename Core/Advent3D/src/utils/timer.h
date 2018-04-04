#pragma once

#include <Windows.h>

namespace advent { namespace utils {

	//Windows only timer class
	class Timer
	{
	private:
	
		LARGE_INTEGER m_Start;
		double m_Frequency;	

	public:

		Timer();

		void reset();

		float elapsed();
	};

} }