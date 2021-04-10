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

CApplianceComponentTransformer& CApplianceComponentTransformer::operator=(CApplianceComponentTransformer& obj)
{
	if (!obj.isNULL())
	{
		imNULL = false;
		this->m_intInputV = obj.m_intInputV;
		this->m_intOutputV = obj.m_intOutputV;
	}
	else
	{
		imNULL = true;
	}
	return *this;
}

bool CApplianceComponentTransformer::operator!=(CApplianceComponentTransformer& obj)
{
	return !(this->operator==(obj));
}

bool CApplianceComponentTransformer::operator==(CApplianceComponentTransformer& obj)
{
	if (obj.isNULL())
	{
		return (obj.isNULL() && this->isNULL());
	}
	return (this->m_intInputV == obj.m_intInputV) && (this->m_intOutputV == obj.m_intOutputV);
}