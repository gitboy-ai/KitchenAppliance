// KitchenConsole.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "CKitchenApplianceMicrowave.h"
#include "CKitchenApplianceRefrigerator.h"

int main()
{
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
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
