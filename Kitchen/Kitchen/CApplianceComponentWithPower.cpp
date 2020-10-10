#include "CApplianceComponentWithPower.h"

CApplianceComponentWithPower::CApplianceComponentWithPower(): m_intVoltage(0) 
{
}

void CApplianceComponentWithPower::setVoltage(int inputVoltage)
{
	m_intVoltage = inputVoltage;
};