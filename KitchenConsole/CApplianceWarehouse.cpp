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
<<<<<<< Updated upstream
		std::map<std::string, microwaveQueue> make;
		microwaveQueue mQueue;
		mQueue.add(microwave);
=======
		std::map<std::string, std::queue<CKitchenApplianceMicrowave>> make;
		std::queue<CKitchenApplianceMicrowave> mQueue;
		mQueue.push(*microwave);
>>>>>>> Stashed changes
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
<<<<<<< Updated upstream
			microwaveQueue mQueue;
			mQueue.add(microwave);
=======
			std::queue<CKitchenApplianceMicrowave> mQueue;
			mQueue.push(*microwave);
>>>>>>> Stashed changes
			wh_microwave[microwave->getMake()][microwave->getModel()] = mQueue;
			return mQueue.size();
		}
		else
		{
			// make AND model exist
<<<<<<< Updated upstream
			wh_microwave[microwave->getMake()][microwave->getModel()].add(microwave);
			return wh_microwave[microwave->getMake()][microwave->getModel()].length();
=======
			wh_microwave[microwave->getMake()][microwave->getModel()].push(*microwave);
			return wh_microwave[microwave->getMake()][microwave->getModel()].size();
>>>>>>> Stashed changes
		}
	}
	return false;
}

bool CApplianceWarehouse::inboundShipment(CKitchenApplianceRefrigerator* refrigerator)
{
	if (wh_refrigerator.find(refrigerator->getMake()) == wh_refrigerator.end())
	{
		// When make AND model does not exist (make doesn't exist so model doesn't exist)
<<<<<<< Updated upstream
		std::map<std::string, refrigeratorQueue> make;
		refrigeratorQueue mQueue;
		mQueue.add(refrigerator);
=======
		std::map<std::string, std::queue<CKitchenApplianceRefrigerator>> make;
		std::queue<CKitchenApplianceRefrigerator> mQueue;
		mQueue.push(*refrigerator);
>>>>>>> Stashed changes
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
<<<<<<< Updated upstream
			refrigeratorQueue mQueue;
			mQueue.add(refrigerator);
=======
			std::queue<CKitchenApplianceRefrigerator> mQueue;
			mQueue.push(*refrigerator);
>>>>>>> Stashed changes
			wh_refrigerator[refrigerator->getMake()][refrigerator->getModel()] = mQueue;
			return mQueue.size();
		}
		else
		{
			// make AND model exist
<<<<<<< Updated upstream
			wh_refrigerator[refrigerator->getMake()][refrigerator->getModel()].add(refrigerator);
			return wh_refrigerator[refrigerator->getMake()][refrigerator->getModel()].length();
=======
			wh_refrigerator[refrigerator->getMake()][refrigerator->getModel()].push(*refrigerator);
			return wh_refrigerator[refrigerator->getMake()][refrigerator->getModel()].size();
>>>>>>> Stashed changes
		}
	}
	return false;
}

<<<<<<< Updated upstream
struct microwaveShipment CApplianceWarehouse::outboundShipmentMicrowave(std::string make, std::string model, int units)
{
	struct microwaveShipment out;
=======
Shipment<CKitchenApplianceMicrowave> CApplianceWarehouse::outboundShipmentMicrowave(std::string make, std::string model, int units)
{
	Shipment<CKitchenApplianceMicrowave> out;
>>>>>>> Stashed changes
	if ((wh_microwave.find(make) == wh_microwave.end()) || (wh_microwave[make].find(model) == wh_microwave[make].end()))
	{
		// If make doesn't exist OR make exists but model doesn't exist
		return out;
	}

	int mQueueLen = int(wh_microwave[make][model].size());
	int unitsRemoved = 0;
<<<<<<< Updated upstream
	out.items = new CKitchenApplianceMicrowave* [units];
=======
	out.items = new CKitchenApplianceMicrowave * [units];
>>>>>>> Stashed changes

	if (mQueueLen >= units)
	{
		// If there is sufficient stock to meet order
		while (unitsRemoved < units)
		{
<<<<<<< Updated upstream
			out.items[unitsRemoved] = wh_microwave[make][model].remove();
=======
			out.items[unitsRemoved] = &wh_microwave[make][model].front();
			wh_microwave[make][model].pop();
>>>>>>> Stashed changes
			out.units++;
			unitsRemoved++;
		}
	}
	else
	{
		// If stock is insufficient to meet order, ship all available units
		while (unitsRemoved < mQueueLen)
		{
<<<<<<< Updated upstream
			out.items[unitsRemoved] = wh_microwave[make][model].remove();
=======
			out.items[unitsRemoved] = &wh_microwave[make][model].front();
			wh_microwave[make][model].pop();
>>>>>>> Stashed changes
			out.units++;
			unitsRemoved++;
			mQueueLen = int(wh_microwave[make][model].size());
		}
	}
	return out;
}

<<<<<<< Updated upstream
struct refrigeratorShipment CApplianceWarehouse::outboundShipmentRefrigerator(std::string make, std::string model, int units)
{	
	struct refrigeratorShipment out;
=======
Shipment<CKitchenApplianceRefrigerator> CApplianceWarehouse::outboundShipmentRefrigerator(std::string make, std::string model, int units)
{
	Shipment<CKitchenApplianceRefrigerator> out;
>>>>>>> Stashed changes
	if ((wh_refrigerator.find(make) == wh_refrigerator.end()) || (wh_refrigerator[make].find(model) == wh_refrigerator[make].end()))
	{
		// If make doesn't exist OR make exists but model doesn't exist
		return out;
	}

	int mQueueLen = int(wh_refrigerator[make][model].size());
	int unitsRemoved = 0;
<<<<<<< Updated upstream
	out.items = new CKitchenApplianceRefrigerator* [units];
=======
	out.items = new CKitchenApplianceRefrigerator * [units];
>>>>>>> Stashed changes

	if (mQueueLen >= units)
	{
		// If there is sufficient stock to meet order
		while (unitsRemoved < units)
		{
<<<<<<< Updated upstream
			out.items[unitsRemoved] = wh_refrigerator[make][model].remove();
=======
			out.items[unitsRemoved] = &wh_refrigerator[make][model].front();
			wh_microwave[make][model].pop();
>>>>>>> Stashed changes
			out.units++;
			unitsRemoved++;
		}
	}
	else
	{
		// If stock is insufficient to meet order, ship all available units
		while (unitsRemoved < mQueueLen)
		{
<<<<<<< Updated upstream
			out.items[unitsRemoved] = wh_refrigerator[make][model].remove();
=======
			out.items[unitsRemoved] = &wh_refrigerator[make][model].front();
			wh_microwave[make][model].pop();
>>>>>>> Stashed changes
			out.units++;
			unitsRemoved++;
			mQueueLen = int(wh_refrigerator[make][model].size());
		}
	}
	return out;
}

<<<<<<< Updated upstream
struct microwaveShipment CApplianceWarehouse::shipmentOrderMicrowave(struct order order)
=======
Shipment<CKitchenApplianceMicrowave> CApplianceWarehouse::shipmentOrderMicrowave(struct order order)
>>>>>>> Stashed changes
{
	return outboundShipmentMicrowave(order.make, order.model, order.units);
}

<<<<<<< Updated upstream
struct refrigeratorShipment CApplianceWarehouse::shipmentOrderRefrigerator(struct order order)
=======
Shipment<CKitchenApplianceRefrigerator> CApplianceWarehouse::shipmentOrderRefrigerator(struct order order)
>>>>>>> Stashed changes
{
	return outboundShipmentRefrigerator(order.make, order.model, order.units);
}

bool CApplianceWarehouse::valid(struct order o)
{
<<<<<<< Updated upstream
	if (o.units < 0)
		return 0;
	if ((o.appliance == microwave) && wh_microwave.count(o.make) && wh_microwave[o.make].count(o.model) && (wh_microwave[o.make][o.model].length() >= o.units))
		return 1;
	if ((o.appliance == refrigerator) && wh_refrigerator.count(o.make) && wh_refrigerator[o.make].count(o.model) && (wh_refrigerator[o.make][o.model].length() >= o.units))
		return 1;
=======
	if (o.units < 0) return 0;
	if ((o.appliance == microwave) && wh_microwave.count(o.make) && wh_microwave[o.make].count(o.model)) return 1;
	if ((o.appliance == refrigerator) && wh_refrigerator.count(o.make) && wh_refrigerator[o.make].count(o.model)) return 1;
>>>>>>> Stashed changes
	return 0;
}