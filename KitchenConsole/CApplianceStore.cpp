#include <iostream>
#include <string>
#include "CApplianceStore.h"

#define MIN_STOCK 10

CApplianceStore::CApplianceStore()
{
}

struct order CApplianceStore::skuToOrder(std::string sku)
{
	struct order order;
	switch (toupper(sku[0]))
	{
		case 'M': order.appliance = microwave; break;
		case 'R': order.appliance = refrigerator; break;
	}
	int make_(sku.find_first_of('_')), model_(sku.find_last_of('_'));
	order.make = sku.substr(++make_, model_ - make_);
	order.model = sku.substr(++model_, sku.npos);		//npos expands to -1
	return order;
}

bool CApplianceStore::needRestock(std::string sku)
{
	switch (toupper(sku[0]))
	{
		case 'M':
			if (store_microwave[sku].length() < MIN_STOCK)
			{
				struct order order = skuToOrder(sku);
				order.units = MIN_STOCK - store_microwave[sku].length();
				return restock(order);
			}
			else
			{
				return false;
			}
			break;
		case 'R':
			if (store_refrigerator[sku].length() < MIN_STOCK)
			{
				struct order order = skuToOrder(sku);
				order.units = MIN_STOCK - store_refrigerator[sku].length();
				return restock(order);
			}
			else
			{
				return false;
			}
			break;
	}
	return false;
}

int CApplianceStore::restock(struct order need)
{
	return 0;
}

void CApplianceStore::addToShelf(std::string sku, CKitchenApplianceMicrowave** shipment)
{
	int units = sizeof(**shipment) / sizeof(CKitchenApplianceMicrowave);
}

void CApplianceStore::addToShelf(std::string sku, CKitchenApplianceRefrigerator** shipment)
{
	int units = sizeof(**shipment) / sizeof(CKitchenApplianceRefrigerator);
}