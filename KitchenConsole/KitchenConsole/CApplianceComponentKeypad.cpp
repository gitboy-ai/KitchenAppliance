#include "CApplianceComponentKeypad.h"
#include <iostream>
#include <windows.h>

#define KEY_MINVALUE 0
#define KEY_MAXVALUE 9
#define KEY_DEFAULTVALUE -1

CApplianceComponentKeypad::CApplianceComponentKeypad() : m_intLastKeyPressed(KEY_DEFAULTVALUE)
{
}
int CApplianceComponentKeypad::process()     
{
    m_intLastKeyPressed = KEY_DEFAULTVALUE;
    while (!(m_intLastKeyPressed >= KEY_MINVALUE && m_intLastKeyPressed <= KEY_MAXVALUE)) 
    {
        std::cin >> m_intLastKeyPressed;
        Beep(1, 100);
    }
    return m_intLastKeyPressed;
}
void CApplianceComponentKeypad::setLastOperation(std::string lastOperation) 
{
    m_strLastOperation = lastOperation;
}
int CApplianceComponentKeypad::getLastKeyPressed() 
{
    if (m_strLastOperation == "TEMPERATURE") 
    {
        return m_intLastKeyPressed * 50;
    }
    else if (m_strLastOperation == "TIMER") 
    {
        return m_intLastKeyPressed * 10;
    }
    else if (m_strLastOperation == "START")
    {
        return 1;
    }
    return 0;
}
int CApplianceComponentKeypad::switchOn(int inputVoltage)
{
    int voltageSet = CApplianceComponentWithPower::switchOn(inputVoltage);
    std::cout << "Keypad ready to go" << std::endl;
    return voltageSet;
}
int CApplianceComponentKeypad::switchOff()
{
    int voltageSet = CApplianceComponentWithPower::switchOff();
    std::cout << "Keypad powered off" << std::endl;
    return voltageSet;
}