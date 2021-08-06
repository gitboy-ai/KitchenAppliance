#pragma once
#include "CKitchenApplianceMicrowave.h"
#include "CKitchenApplianceRefrigerator.h"
#include "Structs.h"
// #include "CApplianceStore.h"
// #include "CApplianceWarehouse.h"

class CApplianceWarehouse;
class IObserver			// warehouse
{
	public:
		virtual struct refrigeratorShipment shipmentOrderRefrigerator(struct order) = 0;
		virtual struct microwaveShipment shipmentOrderMicrowave(struct order) = 0;
		virtual bool valid(struct order) = 0;
};