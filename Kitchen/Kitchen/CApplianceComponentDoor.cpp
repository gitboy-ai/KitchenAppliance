#include "CApplianceComponentDoor.h"
#include <iostream>

CApplianceComponentDoor::CApplianceComponentDoor() : m_boolDoorOpen(true) 
{
}
bool CApplianceComponentDoor::isDoorOpen() {
	return m_boolDoorOpen;
}
void CApplianceComponentDoor::doorOpen() {
	m_boolDoorOpen = true;
	std::cout << "Door is open" << std::endl;
}
void CApplianceComponentDoor::doorClose() {
	m_boolDoorOpen = false;
	std::cout << "Door is closed" << std::endl;
}