#include <iostream>
#include <string>
#include "CApplianceStore.h"
#include "CApplianceWarehouse.h"
// #include "IObserver.h"

CApplianceWarehouse::CApplianceWarehouse()
{
}

bool CApplianceWarehouse::inboundShipment(CKitchenApplianceMicrowave* microwave)
{
	if (wh_microwave.find(microwave->getMake()) == wh_microwave.end())
	{
		// When make AND model does not exist (make doesn't exist so model doesn't exist)
		std::map<std::string, microwaveQueue> make;
		microwaveQueue mQueue;
		mQueue.add(microwave);
		make[microwave->getModel()] = mQueue;
		wh_microwave[microwave->getMake()] = make;
		return mQueue.length();
	}
	else
	{
		// make exists

		if (wh_microwave[microwave->getMake()].find(microwave->getModel()) == wh_microwave[microwave->getMake()].end())
		{
			// make exists but model doesn't exist
			microwaveQueue mQueue;
			mQueue.add(microwave);
			wh_microwave[microwave->getMake()][microwave->getModel()] = mQueue;
			return mQueue.length();
		}
		else
		{
			// make AND model exist
			wh_microwave[microwave->getMake()][microwave->getModel()].add(microwave);
			return wh_microwave[microwave->getMake()][microwave->getModel()].length();
		}
	}
	return false;
}

bool CApplianceWarehouse::inboundShipment(CKitchenApplianceRefrigerator* refrigerator)
{
	if (wh_refrigerator.find(refrigerator->getMake()) == wh_refrigerator.end())
	{
		// When make AND model does not exist (make doesn't exist so model doesn't exist)
		std::map<std::string, refrigeratorQueue> make;
		refrigeratorQueue mQueue;
		mQueue.add(refrigerator);
		make[refrigerator->getModel()] = mQueue;
		wh_refrigerator[refrigerator->getMake()] = make;
		return mQueue.length();
	}
	else
	{
		// make exists

		if (wh_refrigerator[refrigerator->getMake()].find(refrigerator->getModel()) == wh_refrigerator[refrigerator->getMake()].end())
		{
			// make exists but model doesn't exist
			refrigeratorQueue mQueue;
			mQueue.add(refrigerator);
			wh_refrigerator[refrigerator->getMake()][refrigerator->getModel()] = mQueue;
			return mQueue.length();
		}
		else
		{
			// make AND model exist
			wh_refrigerator[refrigerator->getMake()][refrigerator->getModel()].add(refrigerator);
			return wh_refrigerator[refrigerator->getMake()][refrigerator->getModel()].length();
		}
	}
	return false;
}

struct microwaveShipment CApplianceWarehouse::outboundShipmentMicrowave(std::string make, std::string model, int units)
{
	struct microwaveShipment out;
	if ((wh_microwave.find(make) == wh_microwave.end()) || (wh_microwave[make].find(model) == wh_microwave[make].end()))
	{
		// If make doesn't exist OR make exists but model doesn't exist
		return out;
	}
	
	int mQueueLen = wh_microwave[make][model].length();
	int unitsRemoved = 0;
	out.items = new CKitchenApplianceMicrowave* [units];

	if (mQueueLen >= units)
	{
		// If there is sufficient stock to meet order
		while (unitsRemoved < units)
		{
			out.items[unitsRemoved] = wh_microwave[make][model].remove();
			out.units++;
			unitsRemoved++;
		}
	}
	else
	{
		// If stock is insufficient to meet order, ship all available units
		while (unitsRemoved < mQueueLen)
		{
			out.items[unitsRemoved] = wh_microwave[make][model].remove();
			out.units++;
			unitsRemoved++;
			mQueueLen = wh_microwave[make][model].length();
		}
	}
	return out;
}

struct refrigeratorShipment CApplianceWarehouse::outboundShipmentRefrigerator(std::string make, std::string model, int units)
{	
	struct refrigeratorShipment out;
	if ((wh_refrigerator.find(make) == wh_refrigerator.end()) || (wh_refrigerator[make].find(model) == wh_refrigerator[make].end()))
	{
		// If make doesn't exist OR make exists but model doesn't exist
		return out;
	}

	int mQueueLen = wh_refrigerator[make][model].length();
	int unitsRemoved = 0;
	out.items = new CKitchenApplianceRefrigerator* [units];

	if (mQueueLen >= units)
	{
		// If there is sufficient stock to meet order
		while (unitsRemoved < units)
		{
			out.items[unitsRemoved] = wh_refrigerator[make][model].remove();
			out.units++;
			unitsRemoved++;
		}
	}
	else
	{
		// If stock is insufficient to meet order, ship all available units
		while (unitsRemoved < mQueueLen)
		{
			out.items[unitsRemoved] = wh_refrigerator[make][model].remove();
			out.units++;
			unitsRemoved++;
			mQueueLen = wh_refrigerator[make][model].length();
		}
	}
	return out;
}

struct microwaveShipment CApplianceWarehouse::shipmentOrderMicrowave(struct order order)
{
	return outboundShipmentMicrowave(order.make, order.model, order.units);
}

struct refrigeratorShipment CApplianceWarehouse::shipmentOrderRefrigerator(struct order order)
{
	return outboundShipmentRefrigerator(order.make, order.model, order.units);
}

bool CApplianceWarehouse::valid(struct order o)
{
	if (o.units < 0)
		return 0;
	if ((o.appliance == microwave) && wh_microwave.count(o.make) && wh_microwave[o.make].count(o.model) && (wh_microwave[o.make][o.model].length() >= o.units))
		return 1;
	if ((o.appliance == refrigerator) && wh_refrigerator.count(o.make) && wh_refrigerator[o.make].count(o.model) && (wh_refrigerator[o.make][o.model].length() >= o.units))
		return 1;
	return 0;
}