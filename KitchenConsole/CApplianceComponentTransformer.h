#pragma once
#include "CApplianceComponentWithPower.h"

class CApplianceComponentTransformer : public CKitchenApplianceComponent
{
	public:
		CApplianceComponentTransformer();
		int virtual process(int inputVoltage);
		int virtual process();
		int getOutputVoltage();
		int switchOn();
		int switchOff();
		CApplianceComponentTransformer& operator = (CApplianceComponentTransformer&);
		bool operator != (CApplianceComponentTransformer&);
		bool operator == (CApplianceComponentTransformer&);

	protected:
		int m_intInputV;
		int m_intOutputV;
};