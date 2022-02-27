#pragma once
#include "CKitchenApplianceComponent.h"
class CApplianceComponentWithPower: public CKitchenApplianceComponent
{
	public:
		CApplianceComponentWithPower();
		int virtual switchOn(int inputVoltage) = 0;
		int virtual switchOff() = 0;
		CApplianceComponentWithPower& operator = (CApplianceComponentWithPower&);
		CApplianceComponentWithPower& operator = (const CApplianceComponentWithPower&);
		bool operator != (CApplianceComponentWithPower&);
		bool operator == (CApplianceComponentWithPower&);

	protected:
		int m_intVoltage;
};