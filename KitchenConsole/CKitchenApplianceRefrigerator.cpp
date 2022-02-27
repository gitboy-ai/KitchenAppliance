#include "CKitchenApplianceRefrigerator.h"
#include <iostream>

CKitchenApplianceRefrigerator::CKitchenApplianceRefrigerator(std::string model, std::string make, std::string color, double price): m_strAllItems(""), imNULL(false)
{
	this->model = model;
	this->make = make;
	this->id = ++CKitchenAppliance::lastId;
	this->price = price;
	this->m_objRefrigeratorCasing.setColor(color);
}

CKitchenApplianceRefrigerator::CKitchenApplianceRefrigerator(const CKitchenApplianceRefrigerator& obj) : imNULL(false)
{
	this->m_strAllItems = obj.m_strAllItems;
	this->m_objRefrigeratorCasing = obj.m_objRefrigeratorCasing;
	this->m_objRefrigeratorCooler = obj.m_objRefrigeratorCooler;
	this->m_objRefrigeratorDoor = obj.m_objRefrigeratorDoor;
	this->m_objRefrigeratorTransformer = obj.m_objRefrigeratorTransformer;
	this->make = obj.make;
	this->model = obj.model;
	this->id = obj.id;
	this->price = obj.price;
}

int CKitchenApplianceRefrigerator::switchOn()
{
	m_objRefrigeratorTransformer.process(110);
	m_objRefrigeratorTransformer.switchOn();
	int l_intOutputVoltage = m_objRefrigeratorTransformer.getOutputVoltage();
	m_objRefrigeratorCooler.switchOn(l_intOutputVoltage);
	return 0;
}

int CKitchenApplianceRefrigerator::switchOff()
{
	m_objRefrigeratorTransformer.switchOff();
	m_objRefrigeratorCooler.switchOff();
	return 0;
}

void CKitchenApplianceRefrigerator::placeItem(std::string contents[], std::string item)
{
	std::cout << "What do you want to put inside?" << std::endl;
	std::cin >> item;
	bool l_boolFoundSlot = false;
	for (int i = 0; i < sizeof(contents); i++)
	{
		if (l_boolFoundSlot == false)
		{
			if (contents[i] == "")
			{
				contents[i] = item;
				l_boolFoundSlot = true;
			}
		}
	}
	if (l_boolFoundSlot == false)
	{
		std::cout << "The refrigerator is full! It can only store 5 items." << std::endl;
	}
}

void CKitchenApplianceRefrigerator::takeItem(std::string contents[], std::string item)
{
	std::cout << "What do you want to take out?" << std::endl;
	std::cin >> item;
	for (int i = 0; i < sizeof(contents); i++)
	{
		if (contents[i] == item)
		{
			contents[i] = "";
			std::cout << item << " taken out" << std::endl;
		}
	}
}

std::string CKitchenApplianceRefrigerator::getListCurrentItems(std::string contents[])
{
	m_strAllItems = "";
	for (int i = 0; i < sizeof(contents); i++)
	{
		m_strAllItems += (contents[i] + ", ");
	}
	return m_strAllItems;
}

int CKitchenApplianceRefrigerator::process()
{
	m_objRefrigeratorDoor.doorOpen(); 
	std::string l_strChoice;
	std::string l_lstContents[5] = {};
	std::cout << "The refrigerator is currently empty. Put something in there? Y/N" << std::endl;
	std::cin >> l_strChoice;
	if ((l_strChoice == "Y") || (l_strChoice == "y")) {
		std::string l_strFirstItem;
		placeItem(l_lstContents, l_strFirstItem);
	}
	std::cout << "The temperature needs to be set." << std::endl; 
	m_objRefrigeratorCooler.setTemp();
	while (1)
	{
		std::cout << "Place more items (P) \nTake out items (R) \nStatus (S) \nChange temperature (C) \nLeave refrigerator demo (anything else)?" << std::endl;
		std::cin >> l_strChoice;
		if ((l_strChoice == "P") || (l_strChoice == "p"))
		{
			std::string l_strPlaceItem;
			placeItem(l_lstContents, l_strPlaceItem);
		}
		else if ((l_strChoice == "R") || (l_strChoice == "r"))
		{
			std::string l_strTakeItem;
			takeItem(l_lstContents, l_strTakeItem);
		}
		else if ((l_strChoice == "S") || (l_strChoice == "s"))
		{
			std::cout << "Refrigerator is currently: ON" << std::endl;
			m_objRefrigeratorCooler.displayTemp();
			std::cout << "Currently stored items: " << getListCurrentItems(l_lstContents) << std::endl;
		}
		else if ((l_strChoice == "C") || (l_strChoice == "c"))
		{
			m_objRefrigeratorCooler.setTemp();
		}
		else
		{
			switchOff();
			std::cout << "Refrigerator shut off & items trashed." << std::endl;
			break;
		}
	}
	return 0;
}

CKitchenApplianceRefrigerator& CKitchenApplianceRefrigerator::operator=(CKitchenApplianceRefrigerator& obj)
{
	if (!obj.isNULL())
	{
		imNULL = false;
		this->m_strAllItems = obj.m_strAllItems;
		this->m_objRefrigeratorCasing = obj.m_objRefrigeratorCasing;
		this->m_objRefrigeratorCooler = obj.m_objRefrigeratorCooler;
		this->m_objRefrigeratorDoor = obj.m_objRefrigeratorDoor;
		this->m_objRefrigeratorTransformer = obj.m_objRefrigeratorTransformer;
		this->price = obj.price;
		this->make = obj.model;
		this->model = obj.model;
		this->id = obj.id;
	}
	else
	{
		imNULL = true;
	}
	return *this;
}

CKitchenApplianceRefrigerator& CKitchenApplianceRefrigerator::operator=(const CKitchenApplianceRefrigerator& obj)
{
	if (!obj.isNULL())
	{
		imNULL = false;
		this->m_strAllItems = obj.m_strAllItems;
		this->m_objRefrigeratorCasing = obj.m_objRefrigeratorCasing;
		this->m_objRefrigeratorCooler = obj.m_objRefrigeratorCooler;
		this->m_objRefrigeratorDoor = obj.m_objRefrigeratorDoor;
		this->m_objRefrigeratorTransformer = obj.m_objRefrigeratorTransformer;
		this->price = obj.price;
		this->make = obj.model;
		this->model = obj.model;
		this->id = obj.id;
	}
	else
	{
		imNULL = true;
	}
	return *this;
}

bool CKitchenApplianceRefrigerator::operator!=(CKitchenApplianceRefrigerator& obj)
{
	return !(this->operator==(obj));
}

bool CKitchenApplianceRefrigerator::operator==(CKitchenApplianceRefrigerator& obj)
{
	if (obj.isNULL())
	{
		return (obj.isNULL() && this->isNULL());
	}
	return (this->m_strAllItems == obj.m_strAllItems) && (this->m_objRefrigeratorCasing == obj.m_objRefrigeratorCasing) && (this->m_objRefrigeratorCooler == obj.m_objRefrigeratorCooler) && (this->m_objRefrigeratorDoor == obj.m_objRefrigeratorDoor) && (this->m_objRefrigeratorTransformer == obj.m_objRefrigeratorTransformer) && (this->id == obj.id) && (this->make == obj.make) && (this->model == obj.model) && (this->price == obj.price);
}