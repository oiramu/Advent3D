#include "timer.h"

namespace advent { namespace utils { 

	Timer::Timer()
	{
		LARGE_INTEGER frequency;
		QueryPerformanceFrequency(&frequency);
		m_Frequency = 1.0 / frequency.QuadPart;
		QueryPerformanceCounter(&m_Start);
	}

	void Timer::reset()
	{
		QueryPerformanceCounter(&m_Start);
	}

	float Timer::elapsed()
	{
		LARGE_INTEGER current;
		QueryPerformanceCounter(&current);
		unsigned __int64 cycles = current.QuadPart - m_Start.QuadPart;
		return (float)(cycles * m_Frequency);
	}

} }