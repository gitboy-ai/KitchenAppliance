#pragma once
#include "CApplianceComponentWithPower.h"

class CApplianceComponentTurntable : public CApplianceComponentWithPower
{
	public:
		CApplianceComponentTurntable();
		int virtual process();

	private:
		int printDegrees(int degrees);

	protected:
		bool m_boolRotating;
		int m_intDegTurn;
};