#pragma once
#include "CApplianceComponentWithPower.h"

class CApplianceComponentTurntable : public CApplianceComponentWithPower
{
	public:
		CApplianceComponentTurntable();
		int virtual process();
		int switchOn(int inputVoltage);
		int switchOff();
		int printDegrees(int degrees);
		void startStopRotating(bool rotating);
		CApplianceComponentTurntable& operator = (CApplianceComponentTurntable&);
		bool operator != (CApplianceComponentTurntable&);
		bool operator == (CApplianceComponentTurntable&);

	protected:
		bool m_boolRotating;
		int m_intDegTurn;
};