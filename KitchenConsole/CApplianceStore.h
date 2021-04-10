#pragma once
#include <map>
#include "Queue.h"
#include "CKitchenApplianceMicrowave.h"
#include "CKitchenApplianceRefrigerator.h"

class CApplianceStore
{
	public:
		CApplianceStore();
		bool needRestock(std::string);
		struct order skuToOrder(std::string);
	protected:
		int restock(struct order);
		void addToShelf(std::string, CKitchenApplianceMicrowave**);
		void addToShelf(std::string, CKitchenApplianceRefrigerator**);
		CKitchenApplianceMicrowave** orderMicrowave(std::string, int);
		CKitchenApplianceRefrigerator** orderRefrigerator(std::string, int);
		double bill();
		std::map<std::string, refrigeratorQueue> store_refrigerator;
		std::map<std::string, microwaveQueue> store_microwave;
};

enum applianceType { microwave, refrigerator, null};
struct order
{
	applianceType appliance = null;
	std::string make;
	std::string model;
	int units = 0;
};

/*
- Map with key values such as APPLIANCETYPE_MAKE_MODEL (SKU CODE), value will be shelf (queue)
- When item removed from queue, at that time it should check and call for new shipment
- search(sku): customer will come to store and decide on unit(s)
- order(sku, units): if the #units are available in store, give directly from there
	- Bulk orders allowed, will be shipped directly from warehouse
- restock(sku, units): for requesting restock from warehouse
- fromWH(inbound[][], numPackages): "truck" shipment coming into store (array of pointer -> pointer -> arrays), numPackages = #times outboundShipment() called
- addToShelf(sku): unit by unit, places appliances on appropriate shelf using make and model
- bill(): prompts user infinitely (while items in stock) for items until user selects 'Check Out' or something, returns total amount to pay
*/