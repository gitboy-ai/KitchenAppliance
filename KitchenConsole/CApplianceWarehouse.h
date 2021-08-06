#pragma once
#include <map>
#include "Queue.h"
#include "CKitchenApplianceMicrowave.h"
#include "CKitchenApplianceRefrigerator.h"
#include "Structs.h"
#include "IObserver.h"

class IObserver;
class CApplianceWarehouse : public IObserver
{
	public:
		CApplianceWarehouse();
		bool inboundShipment(CKitchenApplianceMicrowave*);
		bool inboundShipment(CKitchenApplianceRefrigerator*);
		struct microwaveShipment shipmentOrderMicrowave(struct order order);
		struct refrigeratorShipment shipmentOrderRefrigerator(struct order order);
		// inline std::map<std::string, std::map<std::string, refrigeratorQueue>> getR() { return wh_refrigerator; };
		// inline std::map<std::string, std::map<std::string, microwaveQueue>> getM() { return wh_microwave; };
		bool valid(struct order);
	protected:
		struct microwaveShipment outboundShipmentMicrowave(std::string model, std::string make, int);
		struct refrigeratorShipment outboundShipmentRefrigerator(std::string model, std::string make, int);
		std::map<std::string, std::map<std::string, refrigeratorQueue>> wh_refrigerator;
		std::map<std::string, std::map<std::string, microwaveQueue>> wh_microwave;
};