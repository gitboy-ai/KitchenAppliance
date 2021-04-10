#pragma once
#include <string>
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
		CKitchenApplianceMicrowave() { imNULL = false; price = 0.00; };
		CKitchenApplianceMicrowave(std::string, std::string, std::string, double);
		CKitchenApplianceMicrowave(CKitchenApplianceMicrowave&);
		int virtual switchOn();
		int virtual switchOff();
		int virtual process();
		CKitchenApplianceMicrowave& operator = (CKitchenApplianceMicrowave&);
		bool operator != (CKitchenApplianceMicrowave&);
		bool operator == (CKitchenApplianceMicrowave&);
		inline bool isNULL() { return imNULL; };
		inline std::string getColor() { return m_objMicrowaveCasing.getColor(); };

	protected:
		CApplianceComponentCasing m_objMicrowaveCasing;
		CApplianceComponentDoor m_objMicrowaveDoor;
		CApplianceComponentHeater m_objMicrowaveHeater;
		CApplianceComponentTransformer m_objMicrowaveTransformer;
		CApplianceComponentTurntable m_objMicrowaveTurntable;
		CApplianceComponentTimer m_objMicrowaveTimer;
		CApplianceComponentKeypad m_objMicrowaveKeypad;

	private:
		bool imNULL;
};