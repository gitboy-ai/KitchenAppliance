#pragma once
#include "CApplianceComponentWithPower.h"
#include <string>

class CApplianceComponentKeypad : public CApplianceComponentWithPower
{
    public:
        CApplianceComponentKeypad();
        int virtual process();
        void setLastOperation(std::string lastOperation);
        int getLastKeyPressed();
        int switchOn(int inputVoltage);
        int switchOff();

    protected:
        int m_intLastKeyPressed;
        std::string m_strLastOperation;
};
