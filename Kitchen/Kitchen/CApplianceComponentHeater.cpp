#include "CApplianceComponentHeater.h"
#include <iostream>

CApplianceComponentHeater::CApplianceComponentHeater() : m_intDegHeat(0) 
{
}
int CApplianceComponentHeater::process() 
{
	std::cout << "Heating food to " << m_intDegHeat << " °F." << std::endl;
	return 0;
}
bool CApplianceComponentHeater::setHeat(int deg_heat) 
{
	m_intDegHeat = deg_heat;
	return true;
}