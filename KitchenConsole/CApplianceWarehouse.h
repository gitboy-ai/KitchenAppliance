#pragma once
#include <map>
#include <queue>
#include "Structs.h"
#include "CKitchenApplianceMicrowave.h"
#include "CKitchenApplianceRefrigerator.h"

class CApplianceWarehouse
{
	public:
		CApplianceWarehouse();
		bool inboundShipment(CKitchenApplianceMicrowave*);
		bool inboundShipment(CKitchenApplianceRefrigerator*);
		Shipment<CKitchenApplianceMicrowave> shipmentOrderMicrowave(struct order);
		Shipment<CKitchenApplianceRefrigerator> shipmentOrderRefrigerator(struct order);
		inline std::map<std::string, std::map<std::string, std::queue<CKitchenApplianceRefrigerator>>> getR() { return wh_refrigerator; };
		inline std::map<std::string, std::map<std::string, std::queue<CKitchenApplianceMicrowave>>> getM() { return wh_microwave; };
		bool valid(struct order);

	protected:
		Shipment<CKitchenApplianceMicrowave> outboundShipmentMicrowave(std::string model, std::string make, int);
		Shipment<CKitchenApplianceRefrigerator> outboundShipmentRefrigerator(std::string model, std::string make, int);
		std::map<std::string, std::map<std::string, std::queue<CKitchenApplianceRefrigerator>>> wh_refrigerator;
		std::map<std::string, std::map<std::string, std::queue<CKitchenApplianceMicrowave>>> wh_microwave;
};