#pragma once
#include "CApplianceComponentWithPower.h"

class CApplianceComponentTurntable : public CApplianceComponentWithPower
{
	public:
		CApplianceComponentTurntable();
		int virtual process();
		//int virtual process(int numTurns);
		int switchOn(int inputVoltage);
		int switchOff();
		int printDegrees(int degrees);
		void startStopRotating(bool rotating);

	protected:
		bool m_boolRotating;
		int m_intDegTurn;
		//int m_intNumTurns;
};