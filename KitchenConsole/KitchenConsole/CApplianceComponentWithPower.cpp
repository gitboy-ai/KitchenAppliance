#include "CApplianceComponentWithPower.h"

CApplianceComponentWithPower::CApplianceComponentWithPower(): m_intVoltage(0) 
{
}

int CApplianceComponentWithPower::switchOn(int inputVoltage)
{
	m_intVoltage = inputVoltage;
	return m_intVoltage;
}

int CApplianceComponentWithPower::switchOff()
{
	m_intVoltage = 0;
	return m_intVoltage;
}