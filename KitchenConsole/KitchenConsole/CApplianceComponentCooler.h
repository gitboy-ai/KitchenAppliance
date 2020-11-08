#pragma once
#include "CApplianceComponentWithPower.h"
class CApplianceComponentCooler: public CApplianceComponentWithPower
{
	public:
		CApplianceComponentCooler();
		int virtual process();
		bool setTemp();
		int displayTemp();
		int switchOn(int inputVoltage);
		int switchOff();
	protected:
		int m_intDeg;
};

