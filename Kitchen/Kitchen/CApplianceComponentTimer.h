#pragma once
#include "CApplianceComponentWithPower.h"

class CApplianceComponentTimer: public CApplianceComponentWithPower
{
	public:
		CApplianceComponentTimer();
		int virtual process();
		void setTimer(int seconds);
		int getTimer();

	protected:
		int m_intTimer;
};