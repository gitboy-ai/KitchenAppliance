#include "CApplianceComponentTurntable.h"
#include <iostream>
#include <Windows.h>

CApplianceComponentTurntable::CApplianceComponentTurntable() : m_boolRotating(false), m_intDegTurn(0)//, m_intNumTurns(0)
{
}
int CApplianceComponentTurntable::process()
{
	if ((m_boolRotating == true) ) 
	{
		if (++m_intDegTurn == 360)
		{
			m_intDegTurn = 0;
		}
		Sleep(100);
	}
	return 0;
}
int CApplianceComponentTurntable::printDegrees(int degrees)
{
	return degrees;
}
void CApplianceComponentTurntable::startStopRotating(bool rotating)
{
	m_boolRotating = rotating;
}
int CApplianceComponentTurntable::switchOn(int inputVoltage)
{
	int voltageSet = CApplianceComponentWithPower::switchOn(inputVoltage);
	std::cout << "Turntable ready to go" << std::endl;
	return voltageSet;
}
int CApplianceComponentTurntable::switchOff()
{
	int voltageSet = CApplianceComponentWithPower::switchOff();
	std::cout << "Turntable powered off" << std::endl;
	return voltageSet;
}