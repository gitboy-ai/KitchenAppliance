#pragma once
#include <map>
#include "Queue.h"
#include "CKitchenApplianceMicrowave.h"
#include "CKitchenApplianceRefrigerator.h"

class CApplianceWarehouse
{
	public:
		CApplianceWarehouse();
		bool inboundShipment(CKitchenApplianceMicrowave*);
		bool inboundShipment(CKitchenApplianceRefrigerator*);
		CKitchenApplianceMicrowave** shipmentOrderMicrowave(struct order order);
		CKitchenApplianceRefrigerator** shipmentOrderRefrigerator(struct order order);
		inline std::map<std::string, std::map<std::string, refrigeratorQueue>> getR() { return wh_refrigerator; };
		inline std::map<std::string, std::map<std::string, microwaveQueue>> getM() { return wh_microwave; };

	protected:
		CKitchenApplianceMicrowave** outboundShipmentMicrowave(std::string model, std::string make, int);
		CKitchenApplianceRefrigerator** outboundShipmentRefrigerator(std::string model, std::string make, int);
		std::map<std::string, std::map<std::string, refrigeratorQueue>> wh_refrigerator;
		std::map<std::string, std::map<std::string, microwaveQueue>> wh_microwave;
};