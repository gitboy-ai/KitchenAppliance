#include "CApplianceComponentCasing.h"
#include <iostream>

CApplianceComponentCasing::CApplianceComponentCasing()
{
}

void CApplianceComponentCasing::setColor(std::string rgb)
{
	color = rgb;
}

int CApplianceComponentCasing::process()
{
	std::cout << "Case color is " << color << std::endl;
	return 0;
}

CApplianceComponentCasing& CApplianceComponentCasing::operator=(CApplianceComponentCasing& obj)
{
	if (!obj.isNULL())
	{
		imNULL = false;
		this->color = obj.color;
	}
	else
	{
		imNULL = true;
	}
	return *this;
}

bool CApplianceComponentCasing::operator!=(CApplianceComponentCasing& obj)
{
	return !(this->operator==(obj));
}

bool CApplianceComponentCasing::operator==(CApplianceComponentCasing& obj)
{
	if (obj.isNULL())
	{
		return (obj.isNULL() && this->isNULL());
	}
	return (this->color == obj.color);
}