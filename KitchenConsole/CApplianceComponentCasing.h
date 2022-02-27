#pragma once
#include <string>
#include "CKitchenApplianceComponent.h"

class CApplianceComponentCasing : public CKitchenApplianceComponent
{
	public:
		CApplianceComponentCasing();
		void setColor(std::string);
		inline std::string getColor() { return color; };
		int virtual process();
		CApplianceComponentCasing& operator = (CApplianceComponentCasing&);
		CApplianceComponentCasing& operator = (const CApplianceComponentCasing&);
		bool operator != (CApplianceComponentCasing&);
		bool operator == (CApplianceComponentCasing&);

	protected:
		std::string color;
};