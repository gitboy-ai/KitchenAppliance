#pragma once
#include "CKitchenAppliance.h"
#include "CApplianceComponentCasing.h"
#include "CApplianceComponentHeater.h"
#include "CApplianceComponentDoor.h"
#include "CApplianceComponentKeypad.h"
#include "CApplianceComponentTimer.h"
#include "CApplianceComponentTransformer.h"
#include "CApplianceComponentTurntable.h"

class CKitchenApplianceMicrowave: public CKitchenAppliance
{
	public:
		CKitchenApplianceMicrowave();
		int virtual switchOn();
		int virtual switchOff();
		int virtual process();

	protected:
		CApplianceComponentCasing m_objMicrowaveCasing;
		CApplianceComponentDoor m_objMicrowaveDoor;
		CApplianceComponentHeater m_objMicrowaveHeater;
		CApplianceComponentTransformer m_objMicrowaveTransformer;
		CApplianceComponentTurntable m_objMicrowaveTurntable;
		CApplianceComponentTimer m_objMicrowaveTimer;
		CApplianceComponentKeypad m_objMicrowaveKeypad;
};