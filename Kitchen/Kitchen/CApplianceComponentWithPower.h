#pragma once
#include "CKitchenApplianceComponent.h"
class CApplianceComponentWithPower: public CKitchenApplianceComponent
{
	public:
		CApplianceComponentWithPower();
		void setVoltage(int inputVoltage);
		int virtual switchOn() = 0;
		int virtual switchOff() = 0;
	protected:
		int m_intVoltage;
};