#pragma once
#include <map>
#include "Queue.h"
#include "CKitchenApplianceMicrowave.h"
#include "CKitchenApplianceRefrigerator.h"
#include "Structs.h"
#include "IObservable.h"
#include "IObserver.h"

class CApplianceStore : public IObservable
{
	public:
		CApplianceStore();
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
};