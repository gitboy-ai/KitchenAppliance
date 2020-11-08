#include "CKitchenApplianceMicrowave.h"
#include <iostream>

CKitchenApplianceMicrowave::CKitchenApplianceMicrowave()
{
}
int CKitchenApplianceMicrowave::switchOn() 
{
	m_objMicrowaveTransformer.process(110);
	m_objMicrowaveTransformer.switchOn();
	int l_intOutputVoltage = m_objMicrowaveTransformer.getOutputVoltage();
	m_objMicrowaveHeater.switchOn(l_intOutputVoltage);
	m_objMicrowaveTimer.switchOn(l_intOutputVoltage);
	m_objMicrowaveKeypad.switchOn(l_intOutputVoltage);
	m_objMicrowaveTurntable.switchOn(l_intOutputVoltage);
	return 0;
}
int CKitchenApplianceMicrowave::switchOff() 
{
	m_objMicrowaveTransformer.switchOff();
	m_objMicrowaveHeater.switchOff();
	m_objMicrowaveTimer.switchOff();
	m_objMicrowaveKeypad.switchOff();
	m_objMicrowaveTurntable.switchOff();
	return 0;
}
int CKitchenApplianceMicrowave::process() 
{
	m_objMicrowaveDoor.doorOpen();
	std::cout << "Pizza placed onto turntable" << std::endl;
	m_objMicrowaveDoor.doorClose();
	m_objMicrowaveKeypad.setLastOperation("TEMPERATURE");
	std::cout << "What temperature do you want to heat the pizza?" << std::endl;
	m_objMicrowaveKeypad.process();
	int l_intTemp = m_objMicrowaveKeypad.getLastKeyPressed();
	m_objMicrowaveHeater.setHeat(l_intTemp);
	m_objMicrowaveKeypad.setLastOperation("TIMER");
	std::cout << "How long do you want to heat the pizza?" << std::endl;
	m_objMicrowaveKeypad.process();
	int l_intTime = m_objMicrowaveKeypad.getLastKeyPressed();
	m_objMicrowaveTimer.setTimer(l_intTime);
	m_objMicrowaveKeypad.setLastOperation("START");
	std::cout << "Started" << std::endl;
	//1 second in timer = 1 rotation in turntable
	int l_intPassedRotations = 0;
	bool l_boolStopHeating = false;
	std::string l_strStopInput;
	while ((l_intPassedRotations < l_intTime) && (l_boolStopHeating == false))
	{
		m_objMicrowaveTurntable.startStopRotating(true);
		m_objMicrowaveTurntable.process();
		std::cout << l_intTime - (l_intPassedRotations + 1) << std::endl;
		if ((l_intPassedRotations % 5) == 0)
		{
			std::cout << "Would you like to stop? Type 'STOP'. Type 'NO' to continue." << std::endl;
			std::cin >> l_strStopInput;
			if (l_strStopInput == "STOP")
			{
				l_boolStopHeating = true;
				l_intTime = 0;
			}
			
		}
		l_intPassedRotations++;
	}
	m_objMicrowaveTurntable.startStopRotating(false);
	m_objMicrowaveDoor.doorOpen();
	std::cout << "Stopped heating. Please take food out." << std::endl;
	m_objMicrowaveDoor.doorClose();
	switchOff();
	std::cout << "Microwave switched off." << std::endl;
	return 0;
}