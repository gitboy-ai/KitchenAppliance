#pragma once
#include <iostream>
class CKitchenAppliance
{
	public:
		int virtual switchOn() = 0;
		int virtual switchOff() = 0;
		int virtual process() = 0;
		inline int getId() { return id; };
		inline std::string getMake() { return make; };
		inline std::string getModel() { return model; };
		inline double getPrice() { return price; }

	protected:
		int id;
		double price;
		std::string make;
		std::string model;
		static int lastId;
};