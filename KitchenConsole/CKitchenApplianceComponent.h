#pragma once

class CKitchenApplianceComponent
{
	public:
		CKitchenApplianceComponent();
		int virtual process() = 0;
	protected:
		inline bool isNULL() { return imNULL; }
		inline bool isNULL() const { return imNULL; }
		bool imNULL;
};