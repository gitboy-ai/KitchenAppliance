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
		CApplianceComponentTimer& operator = (CApplianceComponentTimer&);
		bool operator != (CApplianceComponentTimer&);
		bool operator == (CApplianceComponentTimer&);

	protected:
		int m_intTimer;
};