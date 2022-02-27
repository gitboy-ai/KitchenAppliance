#include <iostream>
#include <string>
#include "CApplianceStore.h"
#include "CApplianceWarehouse.h"

CApplianceWarehouse::CApplianceWarehouse()
{
}

bool CApplianceWarehouse::inboundShipment(CKitchenApplianceMicrowave* microwave)
{
	if (wh_microwave.find(microwave->getMake()) == wh_microwave.end())
	{
		// When make AND model does not exist (make doesn't exist so model doesn't exist)
		std::map<std::string, std::queue<CKitchenApplianceMicrowave>> make;
		std::queue<CKitchenApplianceMicrowave> mQueue;
		mQueue.push(*microwave);
		make[microwave->getModel()] = mQueue;
		wh_microwave[microwave->getMake()] = make;
		return mQueue.size();
	}
	else
	{
		// make exists

		if (wh_microwave[microwave->getMake()].find(microwave->getModel()) == wh_microwave[microwave->getMake()].end())
		{
			// make exists but model doesn't exist
			std::queue<CKitchenApplianceMicrowave> mQueue;
			mQueue.push(*microwave);
			wh_microwave[microwave->getMake()][microwave->getModel()] = mQueue;
			return mQueue.size();
		}
		else
		{
			// make AND model exist
			wh_microwave[microwave->getMake()][microwave->getModel()].push(*microwave);
			return wh_microwave[microwave->getMake()][microwave->getModel()].size();
		}
	}
	return false;
}

bool CApplianceWarehouse::inboundShipment(CKitchenApplianceRefrigerator* refrigerator)
{
	if (wh_refrigerator.find(refrigerator->getMake()) == wh_refrigerator.end())
	{
		// When make AND model does not exist (make doesn't exist so model doesn't exist)
		std::map<std::string, std::queue<CKitchenApplianceRefrigerator>> make;
		std::queue<CKitchenApplianceRefrigerator> mQueue;
		mQueue.push(*refrigerator);
		make[refrigerator->getModel()] = mQueue;
		wh_refrigerator[refrigerator->getMake()] = make;
		return mQueue.size();
	}
	else
	{
		// make exists

		if (wh_refrigerator[refrigerator->getMake()].find(refrigerator->getModel()) == wh_refrigerator[refrigerator->getMake()].end())
		{
			// make exists but model doesn't exist
			std::queue<CKitchenApplianceRefrigerator> mQueue;
			mQueue.push(*refrigerator);
			wh_refrigerator[refrigerator->getMake()][refrigerator->getModel()] = mQueue;
			return mQueue.size();
		}
		else
		{
			// make AND model exist
			wh_refrigerator[refrigerator->getMake()][refrigerator->getModel()].push(*refrigerator);
			return wh_refrigerator[refrigerator->getMake()][refrigerator->getModel()].size();
		}
	}
	return false;
}

Shipment<CKitchenApplianceMicrowave> CApplianceWarehouse::outboundShipmentMicrowave(std::string make, std::string model, int units)
{
	Shipment<CKitchenApplianceMicrowave> out;
	if ((wh_microwave.find(make) == wh_microwave.end()) || (wh_microwave[make].find(model) == wh_microwave[make].end()))
	{
		// If make doesn't exist OR make exists but model doesn't exist
		return out;
	}

	int mQueueLen = int(wh_microwave[make][model].size());
	int unitsRemoved = 0;
	out.items = new CKitchenApplianceMicrowave * [units];

	if (mQueueLen >= units)
	{
		// If there is sufficient stock to meet order
		while (unitsRemoved < units)
		{
			out.items[unitsRemoved] = &wh_microwave[make][model].front();
			wh_microwave[make][model].pop();
			out.units++;
			unitsRemoved++;
		}
	}
	else
	{
		// If stock is insufficient to meet order, ship all available units
		while (unitsRemoved < mQueueLen)
		{
			out.items[unitsRemoved] = &wh_microwave[make][model].front();
			wh_microwave[make][model].pop();
			out.units++;
			unitsRemoved++;
			mQueueLen = int(wh_microwave[make][model].size());
		}
	}
	return out;
}

Shipment<CKitchenApplianceRefrigerator> CApplianceWarehouse::outboundShipmentRefrigerator(std::string make, std::string model, int units)
{
	Shipment<CKitchenApplianceRefrigerator> out;
	if ((wh_refrigerator.find(make) == wh_refrigerator.end()) || (wh_refrigerator[make].find(model) == wh_refrigerator[make].end()))
	{
		// If make doesn't exist OR make exists but model doesn't exist
		return out;
	}

	int mQueueLen = int(wh_refrigerator[make][model].size());
	int unitsRemoved = 0;
	out.items = new CKitchenApplianceRefrigerator * [units];

	if (mQueueLen >= units)
	{
		// If there is sufficient stock to meet order
		while (unitsRemoved < units)
		{
			out.items[unitsRemoved] = &wh_refrigerator[make][model].front();
			wh_microwave[make][model].pop();
			out.units++;
			unitsRemoved++;
		}
	}
	else
	{
		// If stock is insufficient to meet order, ship all available units
		while (unitsRemoved < mQueueLen)
		{
			out.items[unitsRemoved] = &wh_refrigerator[make][model].front();
			wh_microwave[make][model].pop();
			out.units++;
			unitsRemoved++;
			mQueueLen = int(wh_refrigerator[make][model].size());
		}
	}
	return out;
}

Shipment<CKitchenApplianceMicrowave> CApplianceWarehouse::shipmentOrderMicrowave(struct order order)
{
	return outboundShipmentMicrowave(order.make, order.model, order.units);
}

Shipment<CKitchenApplianceRefrigerator> CApplianceWarehouse::shipmentOrderRefrigerator(struct order order)
{
	return outboundShipmentRefrigerator(order.make, order.model, order.units);
}

bool CApplianceWarehouse::valid(struct order o)
{
	if (o.units < 0) return 0;
	if ((o.appliance == microwave) && wh_microwave.count(o.make) && wh_microwave[o.make].count(o.model)) return 1;
	if ((o.appliance == refrigerator) && wh_refrigerator.count(o.make) && wh_refrigerator[o.make].count(o.model)) return 1;
	return 0;
}