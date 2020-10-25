#pragma once
#include "CKitchenApplianceComponent.h"
class CApplianceComponentWithPower: public CKitchenApplianceComponent
{
	public:
		CApplianceComponentWithPower();
		int virtual switchOn(int inputVoltage) = 0;
		int virtual switchOff() = 0;
	protected:
		int m_intVoltage;
};