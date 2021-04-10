#pragma once
#include "CKitchenAppliance.h"
#include "CApplianceComponentCasing.h"
#include "CApplianceComponentCooler.h"
#include "CApplianceComponentDoor.h"
#include "CApplianceComponentTransformer.h"

class CKitchenApplianceRefrigerator: public CKitchenAppliance
{
	public:
		int virtual switchOn();
		int virtual switchOff();
		int virtual process();
		CKitchenApplianceRefrigerator() { imNULL = false; price = 0.00; };
		CKitchenApplianceRefrigerator(std::string, std::string, std::string, double);
		CKitchenApplianceRefrigerator(CKitchenApplianceRefrigerator&);
		void placeItem(std::string contents[], std::string item);
		void takeItem(std::string contents[], std::string item);
		std::string getListCurrentItems(std::string contents[]);
		CKitchenApplianceRefrigerator& operator = (CKitchenApplianceRefrigerator&);
		bool operator != (CKitchenApplianceRefrigerator&);
		bool operator == (CKitchenApplianceRefrigerator&);
		inline bool isNULL() { return imNULL; };
		inline std::string getItems() { return m_strAllItems; };
		inline std::string getColor() { return m_objRefrigeratorCasing.getColor(); };
	protected:
		std::string m_strAllItems;
		CApplianceComponentCasing m_objRefrigeratorCasing;
		CApplianceComponentCooler m_objRefrigeratorCooler;
		CApplianceComponentDoor m_objRefrigeratorDoor;
		CApplianceComponentTransformer m_objRefrigeratorTransformer;
	private:
		bool imNULL;
};

