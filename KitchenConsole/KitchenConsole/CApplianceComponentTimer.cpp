#include "CApplianceComponentTimer.h"
#include <iostream>

CApplianceComponentTimer::CApplianceComponentTimer() : m_intTimer(0) 
{
}

int CApplianceComponentTimer::process() 
{
	std::cout << "Timer has been set for " << m_intTimer << " seconds" << std::endl;
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
int CApplianceComponentTimer::switchOn(int inputVoltage)
{
	int voltageSet = CApplianceComponentWithPower::switchOn(inputVoltage);
	std::cout << "Timer ready to go" << std::endl;
	return voltageSet;
}
int CApplianceComponentTimer::switchOff()
{
	int voltageSet = CApplianceComponentWithPower::switchOff();
	std::cout << "Timer powered off" << std::endl;
	return voltageSet;
}