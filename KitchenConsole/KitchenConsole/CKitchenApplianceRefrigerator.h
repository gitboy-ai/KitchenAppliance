#pragma once
#include <iostream>
#include "CKitchenAppliance.h"
#include "CApplianceComponentCasing.h"
#include "CApplianceComponentCooler.h"
#include "CApplianceComponentDoor.h"
#include "CApplianceComponentTransformer.h"

class CKitchenApplianceRefrigerator: public CKitchenAppliance
{
	public:
		CKitchenApplianceRefrigerator();
		void placeItem(std::string contents[], std::string item);
		void takeItem(std::string contents[], std::string item);
		std::string getListCurrentItems(std::string contents[]);
		int virtual switchOn();
		int virtual switchOff();
		int virtual process();

	protected:
		std::string m_strAllItems;
		CApplianceComponentCasing m_objRefrigeratorCasing;
		CApplianceComponentCooler m_objRefrigeratorCooler;
		CApplianceComponentDoor m_objRefrigeratorDoor;
		CApplianceComponentTransformer m_objRefrigeratorTransformer;
};

