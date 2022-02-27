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

    CApplianceStore store;
    CApplianceWarehouse warehouse;
    store.Register(&warehouse);
    
    ///*
    //GE
        //M_GE_GEM001
            warehouse.inboundShipment(new CKitchenApplianceMicrowave("GEM001", "GE", "White", 699.99));
            warehouse.inboundShipment(new CKitchenApplianceMicrowave("GEM001", "GE", "White", 699.99));
            warehouse.inboundShipment(new CKitchenApplianceMicrowave("GEM001", "GE", "White", 699.99));
            warehouse.inboundShipment(new CKitchenApplianceMicrowave("GEM001", "GE", "White", 699.99));
            warehouse.inboundShipment(new CKitchenApplianceMicrowave("GEM001", "GE", "White", 699.99));
            warehouse.inboundShipment(new CKitchenApplianceMicrowave("GEM001", "GE", "White", 699.99));
            warehouse.inboundShipment(new CKitchenApplianceMicrowave("GEM001", "GE", "White", 699.99));
            warehouse.inboundShipment(new CKitchenApplianceMicrowave("GEM001", "GE", "White", 699.99));
            warehouse.inboundShipment(new CKitchenApplianceMicrowave("GEM001", "GE", "White", 699.99));
            warehouse.inboundShipment(new CKitchenApplianceMicrowave("GEM001", "GE", "White", 699.99));
            warehouse.inboundShipment(new CKitchenApplianceMicrowave("GEM001", "GE", "White", 699.99));
            warehouse.inboundShipment(new CKitchenApplianceMicrowave("GEM001", "GE", "White", 699.99));
            warehouse.inboundShipment(new CKitchenApplianceMicrowave("GEM001", "GE", "White", 699.99));
        //M_GE_GEM002
            warehouse.inboundShipment(new CKitchenApplianceMicrowave("GEM002", "GE", "Red", 420.99));
            warehouse.inboundShipment(new CKitchenApplianceMicrowave("GEM002", "GE", "Red", 420.99));
            warehouse.inboundShipment(new CKitchenApplianceMicrowave("GEM002", "GE", "Red", 420.99));
            warehouse.inboundShipment(new CKitchenApplianceMicrowave("GEM002", "GE", "Purple", 420.99));
            warehouse.inboundShipment(new CKitchenApplianceMicrowave("GEM002", "GE", "Purple", 420.99));
        //M_GE_GEM003
            warehouse.inboundShipment(new CKitchenApplianceMicrowave("GEM003", "GE", "Blue", 999.99));
            warehouse.inboundShipment(new CKitchenApplianceMicrowave("GEM003", "GE", "Blue", 999.99));
            warehouse.inboundShipment(new CKitchenApplianceMicrowave("GEM003", "GE", "Blue", 999.99));
            warehouse.inboundShipment(new CKitchenApplianceMicrowave("GEM003", "GE", "Blue", 999.99));
            warehouse.inboundShipment(new CKitchenApplianceMicrowave("GEM003", "GE", "Blue", 999.99));
            warehouse.inboundShipment(new CKitchenApplianceMicrowave("GEM003", "GE", "Blue", 999.99));
        //M_GE_GEM004
            warehouse.inboundShipment(new CKitchenApplianceMicrowave("GEM004", "GE", "Black", 569.99));
            warehouse.inboundShipment(new CKitchenApplianceMicrowave("GEM004", "GE", "Black", 569.99));
            warehouse.inboundShipment(new CKitchenApplianceMicrowave("GEM004", "GE", "Black", 569.99));
            warehouse.inboundShipment(new CKitchenApplianceMicrowave("GEM004", "GE", "Black", 569.99));
            warehouse.inboundShipment(new CKitchenApplianceMicrowave("GEM004", "GE", "Black", 569.99));

    //SAM
        //M_SAM_SAM001
            warehouse.inboundShipment(new CKitchenApplianceMicrowave("SAM001", "SAM", "Green", 299.99));
            warehouse.inboundShipment(new CKitchenApplianceMicrowave("SAM001", "SAM", "Green", 299.99));
            warehouse.inboundShipment(new CKitchenApplianceMicrowave("SAM001", "SAM", "Green", 299.99));
            warehouse.inboundShipment(new CKitchenApplianceMicrowave("SAM001", "SAM", "Green", 299.99));
            warehouse.inboundShipment(new CKitchenApplianceMicrowave("SAM001", "SAM", "Green", 299.99));
            warehouse.inboundShipment(new CKitchenApplianceMicrowave("SAM001", "SAM", "Green", 299.99));
        //M_SAM_SAM002
            warehouse.inboundShipment(new CKitchenApplianceMicrowave("SAM002", "SAM", "Blue", 599.99));
            warehouse.inboundShipment(new CKitchenApplianceMicrowave("SAM002", "SAM", "Blue", 599.99));
            warehouse.inboundShipment(new CKitchenApplianceMicrowave("SAM002", "SAM", "Blue", 599.99));
            warehouse.inboundShipment(new CKitchenApplianceMicrowave("SAM002", "SAM", "Blue", 599.99));
            warehouse.inboundShipment(new CKitchenApplianceMicrowave("SAM002", "SAM", "Blue", 599.99));
            warehouse.inboundShipment(new CKitchenApplianceMicrowave("SAM002", "SAM", "Blue", 599.99));
            warehouse.inboundShipment(new CKitchenApplianceMicrowave("SAM002", "SAM", "Blue", 599.99));
            warehouse.inboundShipment(new CKitchenApplianceMicrowave("SAM002", "SAM", "Blue", 599.99));
        //M_SAM_SAM003
            warehouse.inboundShipment(new CKitchenApplianceMicrowave("SAM003", "SAM", "Pink", 789.99));
            warehouse.inboundShipment(new CKitchenApplianceMicrowave("SAM003", "SAM", "Gray", 789.99));
            warehouse.inboundShipment(new CKitchenApplianceMicrowave("SAM003", "SAM", "Gray", 789.99));
            warehouse.inboundShipment(new CKitchenApplianceMicrowave("SAM003", "SAM", "Gray", 789.99));
            warehouse.inboundShipment(new CKitchenApplianceMicrowave("SAM003", "SAM", "Gray", 789.99));
            warehouse.inboundShipment(new CKitchenApplianceMicrowave("SAM003", "SAM", "Gray", 789.99));
            warehouse.inboundShipment(new CKitchenApplianceMicrowave("SAM003", "SAM", "Gray", 789.99));
            warehouse.inboundShipment(new CKitchenApplianceMicrowave("SAM003", "SAM", "Gray", 789.99));
            warehouse.inboundShipment(new CKitchenApplianceMicrowave("SAM003", "SAM", "Gray", 789.99));
            warehouse.inboundShipment(new CKitchenApplianceMicrowave("SAM003", "SAM", "Gray", 789.99));
        //M_SAM_SAM004
            warehouse.inboundShipment(new CKitchenApplianceMicrowave("SAM004", "SAM", "Yellow", 399.99));
            warehouse.inboundShipment(new CKitchenApplianceMicrowave("SAM004", "SAM", "Yellow", 399.99));
            warehouse.inboundShipment(new CKitchenApplianceMicrowave("SAM004", "SAM", "Yellow", 399.99));
            warehouse.inboundShipment(new CKitchenApplianceMicrowave("SAM004", "SAM", "Yellow", 399.99));
            warehouse.inboundShipment(new CKitchenApplianceMicrowave("SAM004", "SAM", "Yellow", 399.99));
    //*/

    ///*
    //GE
        //R_GE_GEM001
            warehouse.inboundShipment(new CKitchenApplianceRefrigerator("GEM001", "GE", "White", 699.99));
            warehouse.inboundShipment(new CKitchenApplianceRefrigerator("GEM001", "GE", "White", 699.99));
            warehouse.inboundShipment(new CKitchenApplianceRefrigerator("GEM001", "GE", "White", 699.99));
            warehouse.inboundShipment(new CKitchenApplianceRefrigerator("GEM001", "GE", "White", 699.99));
            warehouse.inboundShipment(new CKitchenApplianceRefrigerator("GEM001", "GE", "White", 699.99));
            warehouse.inboundShipment(new CKitchenApplianceRefrigerator("GEM001", "GE", "White", 699.99));
            warehouse.inboundShipment(new CKitchenApplianceRefrigerator("GEM001", "GE", "White", 699.99));
            warehouse.inboundShipment(new CKitchenApplianceRefrigerator("GEM001", "GE", "White", 699.99));
            warehouse.inboundShipment(new CKitchenApplianceRefrigerator("GEM001", "GE", "White", 699.99));
            warehouse.inboundShipment(new CKitchenApplianceRefrigerator("GEM001", "GE", "White", 699.99));
            warehouse.inboundShipment(new CKitchenApplianceRefrigerator("GEM001", "GE", "White", 699.99));
            warehouse.inboundShipment(new CKitchenApplianceRefrigerator("GEM001", "GE", "White", 699.99));
            warehouse.inboundShipment(new CKitchenApplianceRefrigerator("GEM001", "GE", "White", 699.99));
        //R_GE_GEM002
            warehouse.inboundShipment(new CKitchenApplianceRefrigerator("GEM002", "GE", "Red", 420.99));
            warehouse.inboundShipment(new CKitchenApplianceRefrigerator("GEM002", "GE", "Red", 420.99));
            warehouse.inboundShipment(new CKitchenApplianceRefrigerator("GEM002", "GE", "Red", 420.99));
            warehouse.inboundShipment(new CKitchenApplianceRefrigerator("GEM002", "GE", "Purple", 420.99));
            warehouse.inboundShipment(new CKitchenApplianceRefrigerator("GEM002", "GE", "Purple", 420.99));
        //R_GE_GEM003
            warehouse.inboundShipment(new CKitchenApplianceRefrigerator("GEM003", "GE", "Blue", 999.99));
            warehouse.inboundShipment(new CKitchenApplianceRefrigerator("GEM003", "GE", "Blue", 999.99));
            warehouse.inboundShipment(new CKitchenApplianceRefrigerator("GEM003", "GE", "Blue", 999.99));
            warehouse.inboundShipment(new CKitchenApplianceRefrigerator("GEM003", "GE", "Blue", 999.99));
            warehouse.inboundShipment(new CKitchenApplianceRefrigerator("GEM003", "GE", "Blue", 999.99));
            warehouse.inboundShipment(new CKitchenApplianceRefrigerator("GEM003", "GE", "Blue", 999.99));
        //R_GE_GEM004
            warehouse.inboundShipment(new CKitchenApplianceRefrigerator("GEM004", "GE", "Black", 569.99));
            warehouse.inboundShipment(new CKitchenApplianceRefrigerator("GEM004", "GE", "Black", 569.99));
            warehouse.inboundShipment(new CKitchenApplianceRefrigerator("GEM004", "GE", "Black", 569.99));
            warehouse.inboundShipment(new CKitchenApplianceRefrigerator("GEM004", "GE", "Black", 569.99));
            warehouse.inboundShipment(new CKitchenApplianceRefrigerator("GEM004", "GE", "Black", 569.99));

    //SAM
        //R_SAM_SAM001
            warehouse.inboundShipment(new CKitchenApplianceRefrigerator("SAM001", "SAM", "Green", 299.99));
            warehouse.inboundShipment(new CKitchenApplianceRefrigerator("SAM001", "SAM", "Green", 299.99));
            warehouse.inboundShipment(new CKitchenApplianceRefrigerator("SAM001", "SAM", "Green", 299.99));
            warehouse.inboundShipment(new CKitchenApplianceRefrigerator("SAM001", "SAM", "Green", 299.99));
            warehouse.inboundShipment(new CKitchenApplianceRefrigerator("SAM001", "SAM", "Green", 299.99));
            warehouse.inboundShipment(new CKitchenApplianceRefrigerator("SAM001", "SAM", "Green", 299.99));
        //R_SAM_SAM002
            warehouse.inboundShipment(new CKitchenApplianceRefrigerator("SAM002", "SAM", "Blue", 599.99));
            warehouse.inboundShipment(new CKitchenApplianceRefrigerator("SAM002", "SAM", "Blue", 599.99));
            warehouse.inboundShipment(new CKitchenApplianceRefrigerator("SAM002", "SAM", "Blue", 599.99));
            warehouse.inboundShipment(new CKitchenApplianceRefrigerator("SAM002", "SAM", "Blue", 599.99));
            warehouse.inboundShipment(new CKitchenApplianceRefrigerator("SAM002", "SAM", "Blue", 599.99));
            warehouse.inboundShipment(new CKitchenApplianceRefrigerator("SAM002", "SAM", "Blue", 599.99));
            warehouse.inboundShipment(new CKitchenApplianceRefrigerator("SAM002", "SAM", "Blue", 599.99));
            warehouse.inboundShipment(new CKitchenApplianceRefrigerator("SAM002", "SAM", "Blue", 599.99));
        //R_SAM_SAM003
            warehouse.inboundShipment(new CKitchenApplianceRefrigerator("SAM003", "SAM", "Pink", 789.99));
            warehouse.inboundShipment(new CKitchenApplianceRefrigerator("SAM003", "SAM", "Gray", 789.99));
            warehouse.inboundShipment(new CKitchenApplianceRefrigerator("SAM003", "SAM", "Gray", 789.99));
            warehouse.inboundShipment(new CKitchenApplianceRefrigerator("SAM003", "SAM", "Gray", 789.99));
            warehouse.inboundShipment(new CKitchenApplianceRefrigerator("SAM003", "SAM", "Gray", 789.99));
            warehouse.inboundShipment(new CKitchenApplianceRefrigerator("SAM003", "SAM", "Gray", 789.99));
            warehouse.inboundShipment(new CKitchenApplianceRefrigerator("SAM003", "SAM", "Gray", 789.99));
            warehouse.inboundShipment(new CKitchenApplianceRefrigerator("SAM003", "SAM", "Gray", 789.99));
            warehouse.inboundShipment(new CKitchenApplianceRefrigerator("SAM003", "SAM", "Gray", 789.99));
            warehouse.inboundShipment(new CKitchenApplianceRefrigerator("SAM003", "SAM", "Gray", 789.99));
        //R_SAM_SAM004
            warehouse.inboundShipment(new CKitchenApplianceRefrigerator("SAM004", "SAM", "Yellow", 399.99));
            warehouse.inboundShipment(new CKitchenApplianceRefrigerator("SAM004", "SAM", "Yellow", 399.99));
            warehouse.inboundShipment(new CKitchenApplianceRefrigerator("SAM004", "SAM", "Yellow", 399.99));
            warehouse.inboundShipment(new CKitchenApplianceRefrigerator("SAM004", "SAM", "Yellow", 399.99));
            warehouse.inboundShipment(new CKitchenApplianceRefrigerator("SAM004", "SAM", "Yellow", 399.99));
    //*/

    store.checkout();
}