#include "CApplianceComponentDoor.h"
#include <iostream>

CApplianceComponentDoor::CApplianceComponentDoor() : m_boolDoorOpen(true) 
{
}
bool CApplianceComponentDoor::isDoorOpen() 
{
	return m_boolDoorOpen;
}
void CApplianceComponentDoor::doorOpen() 
{
	m_boolDoorOpen = true;
	std::cout << "Door is open" << std::endl;
}
void CApplianceComponentDoor::doorClose() 
{
	m_boolDoorOpen = false;
	std::cout << "Door is closed" << std::endl;
}
int CApplianceComponentDoor::process() 
{
	return 0;
}

CApplianceComponentDoor& CApplianceComponentDoor::operator=(CApplianceComponentDoor& obj)
{
	if (!obj.isNULL())
	{
		imNULL = false;
		this->m_boolDoorOpen = obj.m_boolDoorOpen;
	}
	else
	{
		imNULL = true;
	}
	return *this;
}

bool CApplianceComponentDoor::operator!=(CApplianceComponentDoor& obj)
{
	return !(this->operator==(obj));
}

bool CApplianceComponentDoor::operator==(CApplianceComponentDoor& obj)
{
	if (obj.isNULL())
	{
		return (obj.isNULL() && this->isNULL());
	}
	return (this->m_boolDoorOpen == obj.m_boolDoorOpen);
}