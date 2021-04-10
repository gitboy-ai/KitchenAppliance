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

CApplianceComponentTurntable& CApplianceComponentTurntable::operator=(CApplianceComponentTurntable& obj)
{
	if (!obj.isNULL())
	{
		imNULL = false;
		this->m_boolRotating = obj.m_boolRotating;
		this->m_intDegTurn = obj.m_intDegTurn;
		this->m_intVoltage = obj.m_intVoltage;
	}
	else
	{
		imNULL = true;
	}
	return *this;
}

bool CApplianceComponentTurntable::operator!=(CApplianceComponentTurntable& obj)
{
	return !(this->operator==(obj));
}

bool CApplianceComponentTurntable::operator==(CApplianceComponentTurntable& obj)
{
	if (obj.isNULL())
	{
		return (obj.isNULL() && this->isNULL());
	}
	return (this->m_intDegTurn == obj.m_intDegTurn) && (this->m_boolRotating == obj.m_boolRotating) && (this->m_intVoltage == obj.m_intVoltage);
}