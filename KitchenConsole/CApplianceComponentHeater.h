#pragma once
#include "CApplianceComponentWithPower.h"

class CApplianceComponentHeater : public CApplianceComponentWithPower
{
	public:
		CApplianceComponentHeater();
		int virtual process();
		bool setHeat(int deg_heat);
		int switchOn(int inputVoltage);
		int switchOff();
		CApplianceComponentHeater& operator = (CApplianceComponentHeater&);
		bool operator != (CApplianceComponentHeater&);
		bool operator == (CApplianceComponentHeater&);

	protected:
		int m_intDegHeat;
};