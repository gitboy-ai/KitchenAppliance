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

CApplianceComponentWithPower& CApplianceComponentWithPower::operator=(CApplianceComponentWithPower& obj)
{
    if (!obj.isNULL())
    {
        imNULL = false;
        this->m_intVoltage = obj.m_intVoltage;
    }
    else
    {
        imNULL = true;
    }
    return *this;
}

bool CApplianceComponentWithPower::operator!=(CApplianceComponentWithPower& obj)
{
    return !(this->operator==(obj));
}

bool CApplianceComponentWithPower::operator==(CApplianceComponentWithPower& obj)
{
    if (obj.isNULL())
    {
        return (obj.isNULL() && this->isNULL());
    }
    return (this->m_intVoltage == obj.m_intVoltage);
}