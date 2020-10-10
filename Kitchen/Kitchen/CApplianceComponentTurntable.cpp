#include "CApplianceComponentTurntable.h"
#include <iostream>
#include <Windows.h>

CApplianceComponentTurntable::CApplianceComponentTurntable() : m_boolRotating(false), m_intDegTurn(0)
{
}
int CApplianceComponentTurntable::process()
{
	while (m_boolRotating == true)
	{
		//std::cout << "Rotated " << m_intDegTurn << " °" << std::endl;
		if (printDegrees(++m_intDegTurn) == 360)
		{
			m_intDegTurn = 0;
		}
		Sleep(100);
	}
	return 0;
}
int CApplianceComponentTurntable::printDegrees(int degrees)
{
	std::cout << "Rotated " << degrees << " °" << std::endl;
	return degrees;
}