#pragma once
#include "CKitchenApplianceMicrowave.h"
#include "CKitchenApplianceRefrigerator.h"

enum applianceType { microwave, refrigerator, null };
struct order
{
	applianceType appliance = null;
	std::string make;
	std::string model;
	int units = 0;
};

template<class T> class Shipment
{
public:
	Shipment() {};
	int units;
	T** items;
};