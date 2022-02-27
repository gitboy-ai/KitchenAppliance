#pragma once
#include <map>
#include <queue>
#include "CKitchenApplianceMicrowave.h"
#include "CKitchenApplianceRefrigerator.h"
#include "CApplianceWarehouse.h"

class CApplianceStore
{
	public:
		CApplianceStore();
		bool Register(CApplianceWarehouse*);
		bool checkout();
	protected:
		bool needRestock(std::string);
		order skuToOrder(std::string, int);
		std::string orderToSku(order);
		int restock(order);
		int addToShelf(std::string, Shipment<CKitchenApplianceMicrowave>);
		int addToShelf(std::string, Shipment<CKitchenApplianceRefrigerator>);
		Shipment<CKitchenApplianceMicrowave> orderMicrowave(std::string, int);
		Shipment<CKitchenApplianceRefrigerator> orderRefrigerator(std::string, int);
	private:
		std::map<std::string, std::queue<CKitchenApplianceRefrigerator>> store_refrigerator;
		std::map<std::string, std::queue<CKitchenApplianceMicrowave>> store_microwave;
		CApplianceWarehouse* m_pWarehouse;
};