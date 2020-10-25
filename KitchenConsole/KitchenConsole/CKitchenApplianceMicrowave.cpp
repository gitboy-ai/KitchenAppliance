#include "CKitchenApplianceMicrowave.h"
#include <iostream>

CKitchenApplianceMicrowave::CKitchenApplianceMicrowave()
{
}
int CKitchenApplianceMicrowave::switchOn() 
{
	m_objTransformer.process(110);
	m_objTransformer.switchOn();
	int l_outputVoltage = m_objTransformer.getOutputVoltage();
	m_objHeater.switchOn(l_outputVoltage);
	m_objTimer.switchOn(l_outputVoltage);
	m_objKeypad.switchOn(l_outputVoltage);
	m_objTurntable.switchOn(l_outputVoltage);
	return 0;
}
int CKitchenApplianceMicrowave::switchOff() 
{
	m_objTransformer.switchOff();
	m_objHeater.switchOff();
	m_objTimer.switchOff();
	m_objKeypad.switchOff();
	m_objTurntable.switchOff();
	return 0;
}
int CKitchenApplianceMicrowave::process() 
{
	m_objDoor.doorOpen();
	std::cout << "Pizza placed onto turntable" << std::endl;
	m_objDoor.doorClose();
	m_objKeypad.setLastOperation("TEMPERATURE");
	std::cout << "What temperature do you want to heat the pizza?" << std::endl;
	m_objKeypad.process();
	int l_intTemp = m_objKeypad.getLastKeyPressed();
	m_objHeater.setHeat(l_intTemp);
	m_objKeypad.setLastOperation("TIMER");
	std::cout << "How long do you want to heat the pizza?" << std::endl;
	m_objKeypad.process();
	int l_intTime = m_objKeypad.getLastKeyPressed();
	m_objTimer.setTimer(l_intTime);
	m_objKeypad.setLastOperation("START");
	std::cout << "Started" << std::endl;
	//1 second in timer = 1 rotation in turntable
	int l_intPassedRotations = 0;
	bool l_boolStopHeating = false;
	std::string l_strStopInput;
	while ((l_intPassedRotations < l_intTime) && (l_boolStopHeating == false))
	{
		m_objTurntable.startStopRotating(true);
		m_objTurntable.process();
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
	m_objTurntable.startStopRotating(false);
	m_objDoor.doorOpen();
	std::cout << "Stopped heating. Please take food out." << std::endl;
	m_objDoor.doorClose();
	switchOff();
	std::cout << "Microwave switched off." << std::endl;
	return 0;
}