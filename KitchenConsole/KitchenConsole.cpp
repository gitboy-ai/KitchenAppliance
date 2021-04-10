// KitchenConsole.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "CKitchenApplianceMicrowave.h"
#include "CKitchenApplianceRefrigerator.h"
#include "CApplianceWarehouse.h"
#include "CApplianceStore.h"
using namespace std;

int main()
{
    /*
    std::string l_appChoice;
    while (true)
    {
        std::cout << "\nWhat appliance do you want to test?" << std::endl;
        std::cout << "Microwave (M)\nRefrigerator (R)" << std::endl;
        std::cin >> l_appChoice;
        if ((l_appChoice == "M") || (l_appChoice == "m"))
        {
            //Run the microwave
             CKitchenApplianceMicrowave l_objMicrowave;
             l_objMicrowave.switchOn();
             l_objMicrowave.process();
        }
        else if ((l_appChoice == "R") || (l_appChoice == "r"))
        {
            //Run the refrigerator
            CKitchenApplianceRefrigerator l_objRefrigerator;
            l_objRefrigerator.switchOn();
            l_objRefrigerator.process();

        }
        else
        {
            std::cout << "Thank you for visiting aCreativeStoreName." << std::endl;
            break;
        }
    }*/

    /*
    //Warehouse Testing
    CApplianceWarehouse warehouse;
    warehouse.inboundShipment(new CKitchenApplianceMicrowave("GEM001", "GE", "White", 699.99));
    warehouse.inboundShipment(new CKitchenApplianceMicrowave("SAM003", "Samsung", "Pink", 789.99));
    warehouse.inboundShipment(new CKitchenApplianceMicrowave("SAM002", "Samsung", "Blue", 599.99));
    warehouse.inboundShipment(new CKitchenApplianceMicrowave("GEM001", "GE", "White", 699.99));
    warehouse.inboundShipment(new CKitchenApplianceMicrowave("GEM001", "GE", "White", 699.99));
    warehouse.inboundShipment(new CKitchenApplianceMicrowave("GEM001", "GE", "White", 699.99));
    warehouse.inboundShipment(new CKitchenApplianceMicrowave("GEM001", "GE", "White", 699.99));
    warehouse.inboundShipment(new CKitchenApplianceMicrowave("GEM004", "GE", "Black", 569.99));
    warehouse.inboundShipment(new CKitchenApplianceMicrowave("SAM003", "Samsung", "Gray", 789.99));
    warehouse.inboundShipment(new CKitchenApplianceRefrigerator("GEM001", "GE", "White", 699.99));
    warehouse.inboundShipment(new CKitchenApplianceRefrigerator("SAM003", "Samsung", "Pink", 789.99));
    warehouse.inboundShipment(new CKitchenApplianceRefrigerator("SAM002", "Samsung", "Blue", 599.99));
    warehouse.inboundShipment(new CKitchenApplianceRefrigerator("GEM001", "GE", "White", 699.99));
    warehouse.inboundShipment(new CKitchenApplianceRefrigerator("GEM001", "GE", "White", 699.99));
    warehouse.inboundShipment(new CKitchenApplianceRefrigerator("GEM001", "GE", "White", 699.99));
    warehouse.inboundShipment(new CKitchenApplianceRefrigerator("GEM001", "GE", "White", 699.99));
    warehouse.inboundShipment(new CKitchenApplianceRefrigerator("GEM004", "GE", "Black", 569.99));
    warehouse.inboundShipment(new CKitchenApplianceRefrigerator("SAM003", "Samsung", "Gray", 789.99));

    int order;
    string model, make;
    cout << "ENTER YOUR ORDER: ";
    cin >> make >> model >> order;
    CKitchenApplianceMicrowave** shipped = warehouse.outboundShipmentMicrowave(make, model, order);
    for (int i = 0; i < order; i++)
    {
        cout << &shipped[i] << '\t' << shipped[i]->getMake() << '\t' << shipped[i]->getModel() << '\t' << shipped[i]->getId() << '\t' << shipped[i]->getPrice() << endl;
    }
    cout << "ENTER YOUR ORDER: ";
    cin >> make >> model >> order;
    CKitchenApplianceRefrigerator** shipped2 = warehouse.outboundShipmentRefrigerator(make, model, order);
    for (int i = 0; i < order; i++)
    {
        cout << &shipped2[i] << '\t' << shipped2[i]->getMake() << '\t' << shipped2[i]->getModel() << '\t' << shipped2[i]->getId() << '\t' << shipped2[i]->getPrice() << endl;
    }
    */

    /*
    CApplianceStore store;
    string sku = "M_GE_GEM001";
    struct order order = store.skuToOrder(sku);
    order.units = 69420;
    //cout << order.appliance << ''
    */
   
    return 0;
}