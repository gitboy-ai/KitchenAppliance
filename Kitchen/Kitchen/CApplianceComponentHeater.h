#pragma once
#include "CApplianceComponentWithPower.h"

class CApplianceComponentHeater : public CApplianceComponentWithPower
{
	public:
		CApplianceComponentHeater();
		int virtual process();
		bool setHeat(int deg_heat);

	protected:
		int m_intDegHeat;
};