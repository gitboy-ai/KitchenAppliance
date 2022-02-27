#include <iostream>
#include <string>
#include <tuple>
#include "CApplianceStore.h"

#define MIN_STOCK 3
#define MAX_STOCK 5
#define ORDER_MAX MAX_STOCK-MIN_STOCK

<<<<<<< Updated upstream
CApplianceStore::CApplianceStore() : m_pObserver(nullptr)
{
}

bool CApplianceStore::Register(IObserver* observer)
{
	m_pObserver = observer;
=======
CApplianceStore::CApplianceStore() : m_pWarehouse(nullptr)
{
}

bool CApplianceStore::Register(CApplianceWarehouse* wh)
{
	m_pWarehouse = wh;
>>>>>>> Stashed changes
	return 1;
}

struct order CApplianceStore::skuToOrder(std::string sku, int units)
{
	struct order order;
	switch (toupper(sku[0]))
	{
		case 'M': order.appliance = microwave; break;
		case 'R': order.appliance = refrigerator; break;
	}
	int make_(int(sku.find_first_of('_'))), model_(int(sku.find_last_of('_')));
	order.make = sku.substr(++make_, model_ - make_);
<<<<<<< Updated upstream
	order.model = sku.substr(++model_, sku.npos);					// npos expands to -1
=======
	order.model = sku.substr(++model_, sku.npos);		//npos expands to -1
>>>>>>> Stashed changes
	order.units = units;
	return order;
}

std::string CApplianceStore::orderToSku(struct order order)
{
	if (order.appliance == microwave)
		return ("M_" + order.make + "_" + order.model);
	else if (order.appliance == refrigerator)
		return ("R_" + order.make + "_" + order.model);
	return "";
}

bool CApplianceStore::needRestock(std::string sku)
{
	if (toupper(sku[0]) == 'M')
	{
<<<<<<< Updated upstream
		if (store_microwave[sku].length() < MIN_STOCK)
		{
			struct order order = skuToOrder(sku, MIN_STOCK - store_microwave[sku].length());
			return restock(order);
		}
		else
		{
			return false;
		}
	}
	else if (toupper(sku[0]) == 'R')
	{
		if (store_refrigerator[sku].length() < MIN_STOCK)
		{
			struct order order = skuToOrder(sku, MIN_STOCK - store_refrigerator[sku].length());
			return restock(order);
		}
		else
		{
			return false;
		}
=======
		case 'M':
			if (store_microwave[sku].size() < MIN_STOCK)
			{
				struct order order = skuToOrder(sku, MIN_STOCK - int(store_microwave[sku].size()));
				return restock(order);
			}
			else
			{
				return false;
			}
			break;
		case 'R':
			if (store_refrigerator[sku].size() < MIN_STOCK)
			{
				struct order order = skuToOrder(sku, MIN_STOCK - int(store_refrigerator[sku].size()));
				return restock(order);
			}
			else
			{
				return false;
			}
			break;
>>>>>>> Stashed changes
	}
	return false;
}

int CApplianceStore::addToShelf(std::string sku, Shipment<CKitchenApplianceMicrowave> in)
{
	for (int i = 0; i < in.units; i++)
		store_microwave[sku].push(*in.items[i]);
	return in.units;
}

int CApplianceStore::addToShelf(std::string sku, Shipment<CKitchenApplianceRefrigerator> in)
{
	for (int i = 0; i < in.units; i++)
		store_refrigerator[sku].push(*in.items[i]);
	return in.units;
}

int CApplianceStore::restock(struct order need)
{
	if (need.appliance == microwave)
<<<<<<< Updated upstream
		return addToShelf(orderToSku(need), m_pObserver->shipmentOrderMicrowave(need));
	else if (need.appliance == refrigerator)
		return addToShelf(orderToSku(need), m_pObserver->shipmentOrderRefrigerator(need));
	return 0;
}

int CApplianceStore::addToShelf(std::string sku, struct microwaveShipment in)
{
	for (int i = 0; i < in.units; i++)
		store_microwave[sku].add(in.items[i]);
	return in.units;
}

int CApplianceStore::addToShelf(std::string sku, struct refrigeratorShipment in)
{
	for (int i = 0; i < in.units; i++)
		store_refrigerator[sku].add(in.items[i]);
	return in.units;
}

struct microwaveShipment CApplianceStore::orderMicrowave(std::string sku, int units)
{
	if (units > ORDER_MAX)
	{
		// send outbound shipment directly from warehouse
		return m_pObserver->shipmentOrderMicrowave(skuToOrder(sku, units));
	}
	else
	{
		// send directly from store and call needRestock(sku)
		struct microwaveShipment order;
		order.items = new CKitchenApplianceMicrowave* [units];
		order.units = units;
		for (int i = 0; i < units; i++)
			order.items[i] = store_microwave[sku].remove();
		needRestock(sku);
		return order;
	}
}

struct refrigeratorShipment CApplianceStore::orderRefrigerator(std::string sku, int units)
{
	if (units > ORDER_MAX)
	{
		//  send outbound shipment directly from warehouse
		return m_pObserver->shipmentOrderRefrigerator(skuToOrder(sku, units));
	}
	else
	{
		//  send directly from store and call needRestock(sku)
		struct refrigeratorShipment order;
		order.items = new CKitchenApplianceRefrigerator* [units];
		order.units = units;
		for (int i = 0; i < units; i++)
			order.items[i] = store_refrigerator[sku].remove();
		needRestock(sku);
		return order;
	}
}

bool CApplianceStore::checkout()
{
	double total(0.00);
=======
		return addToShelf(orderToSku(need), m_pWarehouse->shipmentOrderMicrowave(need));
	else if (need.appliance == refrigerator)
		return addToShelf(orderToSku(need), m_pWarehouse->shipmentOrderRefrigerator(need));
	return 0;
}

Shipment<CKitchenApplianceMicrowave> CApplianceStore::orderMicrowave(std::string sku, int units)
{
	if (units > ORDER_MAX)
	{
		// send outbound shipment directly from warehouse
		return m_pWarehouse->shipmentOrderMicrowave(skuToOrder(sku, units));
	}
	else
	{
		// send directly from store and call needRestock(sku)
		Shipment<CKitchenApplianceMicrowave> shipment;
		shipment.items = new CKitchenApplianceMicrowave * [units];
		shipment.units = units;
		for (int i = 0; i < units; i++)
		{
			shipment.items[i] = &store_microwave[sku].front();
			store_microwave[sku].pop();
		}
		needRestock(sku);
		return shipment;
	}
}

Shipment<CKitchenApplianceRefrigerator> CApplianceStore::orderRefrigerator(std::string sku, int units)
{
	if (units > ORDER_MAX)
	{
		// send outbound shipment directly from warehouse
		return m_pWarehouse->shipmentOrderRefrigerator(skuToOrder(sku, units));
	}
	else
	{
		// send directly from store and call needRestock(sku)
		Shipment<CKitchenApplianceRefrigerator> shipment;
		shipment.items = new CKitchenApplianceRefrigerator * [units];
		shipment.units = units;
		for (int i = 0; i < units; i++)
		{
			shipment.items[i] = &store_refrigerator[sku].front();
			store_microwave[sku].pop();
		}
		needRestock(sku);
		return shipment;
	}
}

bool CApplianceStore::checkout()
{
	std::queue<std::tuple<std::string, int, double>> total;
>>>>>>> Stashed changes
	std::string input;
	while (1)
	{
		std::cout << "\nWhat would you like to do?" << std::endl;
		std::cout << "(1) Continue shopping\n(2) Checkout" << std::endl;
		std::cin >> input;
		std::cout << "\n-----------------------------------------------------------------\n";

		if (input == "1")
		{
<<<<<<< Updated upstream
			double subtotal(0.00);
			// Get item info
=======
			//Get item info
>>>>>>> Stashed changes
			std::string sku;
			int units;
			std::cout << "Please enter the item details below" << std::endl;
			std::cout << "Appliance: ";
			std::cin >> input;
			sku += toupper(input[0]);
<<<<<<< Updated upstream
			if (sku[0] == 'M' || sku[0] == 'R')
			{
				std::cout << "\nMake: ";
				std::cin >> input;
				sku += ("_" + input);
				std::cout << "\nModel: ";
				std::cin >> input;
				sku += ("_" + input);
				std::cout << "\n# units: ";
				std::cin >> units;
				if (m_pObserver->valid(skuToOrder(sku, units))) // Checks to make sure these items exist in warehouse - if not, invalid item
				{
					// Get items
					if (sku[0] == 'M')
					{
						// Microwave order
						struct microwaveShipment microwaves = orderMicrowave(sku, units);
						subtotal += microwaves.units * microwaves.items[0]->getPrice();
						total += subtotal;
					}
					else if (sku[0] == 'R')
					{
						// Refrigerator order
						struct refrigeratorShipment refrigerators = orderRefrigerator(sku, units);
						subtotal += refrigerators.units * refrigerators.items[0]->getPrice();
						total += subtotal;
					}
					std::cout << "\nSubtotal: $" << subtotal << "\tTotal: $" << total << std::endl;
				}
				else
				{
					std::cout << "\nInvalid input. Please try again." << std::endl;
=======
			std::cout << "\nMake: ";
			std::cin >> input;
			sku += ("_" + input);
			std::cout << "\nModel: ";
			std::cin >> input;
			sku += ("_" + input);
			std::cout << "\n# units: ";
			std::cin >> units;

			//Defensive Programming
			if (m_pWarehouse->valid(skuToOrder(sku, units))) //Checks to make sure these items exist in warehouse - if not, invalid item
			{
				//Get items
				if (sku[0] == 'M')
				{
					//Microwave order
					Shipment<CKitchenApplianceMicrowave> microwaves = orderMicrowave(sku, units);
					std::tuple<std::string, int, double> item(sku, microwaves.units, microwaves.items[0]->getPrice());
					total.push(item);
				}
				else if (sku[0] == 'R')
				{
					//Refrigerator order
					Shipment<CKitchenApplianceRefrigerator> refrigerators = orderRefrigerator(sku, units);
					std::tuple<std::string, int, double> item(sku, refrigerators.units, refrigerators.items[0]->getPrice());
					total.push(item);
>>>>>>> Stashed changes
				}
			}
			else
			{
				std::cout << "\nInvalid input. Please try again." << std::endl;
			}
		}
		else if (input == "2")
		{
<<<<<<< Updated upstream
			if (total)
			{
				std::cout << "\nYour total is: $" << total << ". Would you like to pay? (Y / N)" << std::endl;
				std::cin >> input;
				if (input == "Y")
				{
					std::cout << "\nPayment was successful. Thank you for shopping!" << std::endl;
					return 1;
				}
				else
				{
					std::cout << "\nPayment was unsuccessful. Please visit again!" << std::endl;
					return 0;
				}
			}
			else
			{
				std::cout << "\nPlease visit again!" << std::endl;
			}
			break;
=======
			std::string receipt;
			double sum(0.00);
			std::cout << "\n\t\t\t\tBILL\n-----------------------------------------------------------------\n";
			while (total.size())
			{
				receipt += '\n' + std::to_string(std::get<1>(total.front())) + '\t' + std::get<0>(total.front()) + "\t@\t" + std::to_string(std::get<2>(total.front())) + "\t=\t" + std::to_string(std::get<2>(total.front()) * std::get<1>(total.front()));
				sum += std::get<1>(total.front()) * std::get<2>(total.front());;
				total.pop();
			}
			receipt += "\nTotal: $" + std::to_string(sum);
			std::cout << receipt << std::endl;
			std::cout << "Would you like to pay? (Y / N)" << std::endl;
			std::cin >> input;
			if (input == "Y" || sum == 0.00)
			{
				std::cout << "\nPayment was successful. Thank you for shopping!" << std::endl;
				return 1;
			}
			else
			{
				std::cout << "\nPayment was unsuccessful. Please visit again!" << std::endl;
				return 0;
			}
>>>>>>> Stashed changes
		}
	}
	return 0;
}