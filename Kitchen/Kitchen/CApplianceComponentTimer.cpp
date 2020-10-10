#include "CApplianceComponentTimer.h"
#include <iostream>

CApplianceComponentTimer::CApplianceComponentTimer() : m_intTimer(0) 
{
}

int CApplianceComponentTimer::process() 
{
	std::cout << "Timer has been set for %d seconds" << m_intTimer << std::endl;
	return 0;
}
void CApplianceComponentTimer::setTimer(int seconds) 
{
	m_intTimer = seconds;
	process();
}
int CApplianceComponentTimer::getTimer() 
{
	return m_intTimer;
}