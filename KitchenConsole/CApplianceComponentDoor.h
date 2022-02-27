#pragma once
#include "CKitchenApplianceComponent.h"

class CApplianceComponentDoor: public CKitchenApplianceComponent
{
	public:
		CApplianceComponentDoor();
		int virtual process();
		bool isDoorOpen();
		void doorOpen();
		void doorClose();
		CApplianceComponentDoor& operator = (CApplianceComponentDoor&);
		CApplianceComponentDoor& operator = (const CApplianceComponentDoor&);
		bool operator != (CApplianceComponentDoor&);
		bool operator == (CApplianceComponentDoor&);

	protected: 
		bool m_boolDoorOpen;
};