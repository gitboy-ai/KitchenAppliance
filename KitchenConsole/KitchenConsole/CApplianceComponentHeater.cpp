#include "CApplianceComponentHeater.h"
#include <iostream>

CApplianceComponentHeater::CApplianceComponentHeater() : m_intDegHeat(0) 
{
}
int CApplianceComponentHeater::process() 
{
	std::cout << "Heating food to " << m_intDegHeat << " F." << std::endl;
	return 0;
}
bool CApplianceComponentHeater::setHeat(int deg_heat) 
{
	m_intDegHeat = deg_heat;
	process();
	return true;
}
int CApplianceComponentHeater::switchOn(int inputVoltage)
{
	int voltageSet = CApplianceComponentWithPower::switchOn(inputVoltage);
	std::cout << "Heater ready to go" << std::endl;
	return voltageSet;
}
int CApplianceComponentHeater::switchOff()
{
	int voltageSet = CApplianceComponentWithPower::switchOff();
	std::cout << "Heater powered off" << std::endl;
	return voltageSet;
}