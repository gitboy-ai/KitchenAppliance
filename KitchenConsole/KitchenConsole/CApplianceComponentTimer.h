#pragma once
#include "CApplianceComponentWithPower.h"

class CApplianceComponentTimer: public CApplianceComponentWithPower
{
	public:
		CApplianceComponentTimer();
		int virtual process();
		void setTimer(int seconds);
		int getTimer();
		int switchOn(int inputVoltage);
		int switchOff();

	protected:
		int m_intTimer;
};