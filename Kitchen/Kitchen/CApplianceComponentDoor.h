#pragma once
#include "CKitchenApplianceComponent.h"

class CApplianceComponentDoor: public CKitchenApplianceComponent
{
	public:
		CApplianceComponentDoor();
		int virtual process() = 0;
		bool isDoorOpen();
		void doorOpen();
		void doorClose();

	protected: 
		bool m_boolDoorOpen;
};