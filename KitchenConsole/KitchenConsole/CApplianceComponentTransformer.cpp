#include "CApplianceComponentTransformer.h"
#include <iostream>

CApplianceComponentTransformer::CApplianceComponentTransformer() : m_intInputV(0), m_intOutputV(0) 
{
}
int CApplianceComponentTransformer::process(int input) 
{
	m_intInputV = input;
	m_intOutputV = m_intInputV / 11;
	return m_intOutputV;
}
int CApplianceComponentTransformer::process() //not in use
{
	return 0;
}
int CApplianceComponentTransformer::getOutputVoltage() 
{
	return m_intOutputV;
}
int CApplianceComponentTransformer::switchOn()
{
	std::cout << "Transformer powered on" << std::endl;
	return m_intOutputV;
}
int CApplianceComponentTransformer::switchOff()
{
	std::cout << "Transformer switched off" << std::endl;
	return m_intOutputV;
}