#pragma once
#include <map>
#include <queue>
#include "CKitchenApplianceMicrowave.h"
#include "CKitchenApplianceRefrigerator.h"
<<<<<<< Updated upstream
#include "Structs.h"
#include "IObservable.h"
#include "IObserver.h"
=======
#include "CApplianceWarehouse.h"
>>>>>>> Stashed changes

class CApplianceStore : public IObservable
{
	public:
		CApplianceStore();
<<<<<<< Updated upstream
		bool Register(IObserver* observer);
		bool checkout();
	protected:
		bool needRestock(std::string);
		struct order skuToOrder(std::string, int);
		std::string orderToSku(struct order);
		int restock(struct order);
		int addToShelf(std::string, struct microwaveShipment);
		int addToShelf(std::string, struct refrigeratorShipment);
		struct microwaveShipment orderMicrowave(std::string, int);
		struct refrigeratorShipment orderRefrigerator(std::string, int);
	private:
		std::map<std::string, refrigeratorQueue> store_refrigerator;
		std::map<std::string, microwaveQueue> store_microwave;
		IObserver* m_pObserver;
=======
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
>>>>>>> Stashed changes
};