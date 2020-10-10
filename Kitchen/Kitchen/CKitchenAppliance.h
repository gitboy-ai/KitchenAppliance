#pragma once

class CKitchenAppliance {
	public:
		CKitchenAppliance();
		int virtual switchOn() = 0;
		int virtual switchOff() = 0;
		int virtual process() = 0;
};