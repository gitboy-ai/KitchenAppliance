#pragma once
#include "CApplianceComponentWithPower.h"

class CApplianceComponentTransformer : public CKitchenApplianceComponent
{
	public:
		CApplianceComponentTransformer();
		int virtual process(int inputVoltage);
		int getOutputVoltage();

	protected:
		int m_intInputV;
		int m_intOutputV;
};