#include "CApplianceComponentCooler.h"
#include <iostream>

CApplianceComponentCooler::CApplianceComponentCooler() : m_intDeg(0)
{
}
int CApplianceComponentCooler::process()
{
	std::cout << "Refrigerator temperature set to  " << m_intDeg << " F." << std::endl;
	return 0;
}
bool CApplianceComponentCooler::setTemp()
{
	std::cout << "How cold should the refrigerator be?" << std::endl;
	std::cin >> m_intDeg;
	process();
	return true;
}
int CApplianceComponentCooler::displayTemp()
{
	std::cout << "The temperature is set to: " << m_intDeg << "F" << std::endl;
	return m_intDeg;
}
int CApplianceComponentCooler::switchOn(int inputVoltage)
{
	int voltageSet = CApplianceComponentWithPower::switchOn(inputVoltage);
	std::cout << "Cooler ready to go" << std::endl;
	return voltageSet;
}
int CApplianceComponentCooler::switchOff()
{
	int voltageSet = CApplianceComponentWithPower::switchOff();
	std::cout << "Cooler powered off" << std::endl;
	return voltageSet;
}

CApplianceComponentCooler& CApplianceComponentCooler::operator=(CApplianceComponentCooler& obj)
{
	if (!obj.isNULL())
	{
		imNULL = false;
		this->m_intDeg = obj.m_intDeg;
		this->m_intVoltage = obj.m_intVoltage;
	}
	else
	{
		imNULL = true;
	}
	return *this;
}

bool CApplianceComponentCooler::operator!=(CApplianceComponentCooler& obj)
{
	return !(this->operator==(obj));
}

bool CApplianceComponentCooler::operator==(CApplianceComponentCooler& obj)
{
	if (obj.isNULL())
	{
		return (obj.isNULL() && this->isNULL());
	}
	return (this->m_intDeg == obj.m_intDeg) && (this->m_intVoltage == obj.m_intVoltage);
}