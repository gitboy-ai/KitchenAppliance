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
		//When make AND model does not exist (make doesn't exist so model doesn't exist)
		std::map<std::string, microwaveQueue> make;
		microwaveQueue mQueue;
		mQueue.add(microwave);
		make[microwave->getModel()] = mQueue;
		wh_microwave[microwave->getMake()] = make;
		return mQueue.length();
	}
	else
	{
		//make exists

		if (wh_microwave[microwave->getMake()].find(microwave->getModel()) == wh_microwave[microwave->getMake()].end())
		{
			//make exists but model doesn't exist
			microwaveQueue mQueue;
			mQueue.add(microwave);
			wh_microwave[microwave->getMake()][microwave->getModel()] = mQueue;
			return mQueue.length();
		}
		else
		{
			//make AND model exist
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
		//When make AND model does not exist (make doesn't exist so model doesn't exist)
		std::map<std::string, refrigeratorQueue> make;
		refrigeratorQueue mQueue;
		mQueue.add(refrigerator);
		make[refrigerator->getModel()] = mQueue;
		wh_refrigerator[refrigerator->getMake()] = make;
		return mQueue.length();
	}
	else
	{
		//make exists

		if (wh_refrigerator[refrigerator->getMake()].find(refrigerator->getModel()) == wh_refrigerator[refrigerator->getMake()].end())
		{
			//make exists but model doesn't exist
			refrigeratorQueue mQueue;
			mQueue.add(refrigerator);
			wh_refrigerator[refrigerator->getMake()][refrigerator->getModel()] = mQueue;
			return mQueue.length();
		}
		else
		{
			//make AND model exist
			wh_refrigerator[refrigerator->getMake()][refrigerator->getModel()].add(refrigerator);
			return wh_refrigerator[refrigerator->getMake()][refrigerator->getModel()].length();
		}
	}
	return false;
}

CKitchenApplianceMicrowave** CApplianceWarehouse::outboundShipmentMicrowave(std::string make, std::string model, int units)
{
	if ((wh_microwave.find(make) == wh_microwave.end()) || (wh_microwave[make].find(model) == wh_microwave[make].end()))
	{
		//If make doesn't exist OR make exists but model doesn't exist
		return nullptr;
	}
	
	int mQueueLen = wh_microwave[make][model].length();
	int unitsRemoved = 0;
	CKitchenApplianceMicrowave** outboundMicrowaves = new CKitchenApplianceMicrowave* [units];

	if (mQueueLen >= units)
	{
		//If there is sufficient stock to meet order
		while (unitsRemoved < units)
		{
			outboundMicrowaves[unitsRemoved] = wh_microwave[make][model].remove();
			unitsRemoved++;
		}
	}
	else
	{
		//If stock is insufficient to meet order, ship all available units
		while (unitsRemoved < mQueueLen)
		{
			outboundMicrowaves[unitsRemoved] = wh_microwave[make][model].remove();
			unitsRemoved++;
			mQueueLen = wh_microwave[make][model].length();
		}
	}
	return outboundMicrowaves;
}

CKitchenApplianceRefrigerator** CApplianceWarehouse::outboundShipmentRefrigerator(std::string make, std::string model, int units)
{
	if ((wh_refrigerator.find(make) == wh_refrigerator.end()) || (wh_refrigerator[make].find(model) == wh_refrigerator[make].end()))
	{
		//If make doesn't exist OR make exists but model doesn't exist
		return nullptr;
	}

	int mQueueLen = wh_refrigerator[make][model].length();
	int unitsRemoved = 0;
	CKitchenApplianceRefrigerator** outboundRefrigerators = new CKitchenApplianceRefrigerator* [units];

	if (mQueueLen >= units)
	{
		//If there is sufficient stock to meet order
		while (unitsRemoved < units)
		{
			outboundRefrigerators[unitsRemoved] = wh_refrigerator[make][model].remove();
			unitsRemoved++;
		}
	}
	else
	{
		//If stock is insufficient to meet order, ship all available units
		while (unitsRemoved < mQueueLen)
		{
			outboundRefrigerators[unitsRemoved] = wh_refrigerator[make][model].remove();
			unitsRemoved++;
			mQueueLen = wh_refrigerator[make][model].length();
		}
	}
	return outboundRefrigerators;
}

CKitchenApplianceMicrowave** CApplianceWarehouse::shipmentOrderMicrowave(struct order order)
{
	return outboundShipmentMicrowave(order.make, order.model, order.units);
}

CKitchenApplianceRefrigerator** CApplianceWarehouse::shipmentOrderRefrigerator(struct order order)
{
	return outboundShipmentRefrigerator(order.make, order.model, order.units);
}