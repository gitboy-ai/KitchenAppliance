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

	protected:
		int m_intDegHeat;
};