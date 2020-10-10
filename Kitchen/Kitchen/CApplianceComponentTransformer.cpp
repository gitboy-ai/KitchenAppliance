#include "CApplianceComponentTransformer.h"

CApplianceComponentTransformer::CApplianceComponentTransformer() : m_intInputV(0), m_intOutputV(0) 
{
}
int CApplianceComponentTransformer::process(int input) 
{
	m_intInputV = input;
	m_intOutputV = m_intInputV / 24;
	return m_intOutputV;
}
int CApplianceComponentTransformer::getOutputVoltage() 
{
	return m_intOutputV;
}