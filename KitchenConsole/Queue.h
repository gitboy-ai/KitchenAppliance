#pragma once
#include "CKitchenApplianceMicrowave.h"
#include "CKitchenApplianceRefrigerator.h"

//Queue & Node for microwave
class microwaveNode
{
public:
	microwaveNode();
	microwaveNode* next;
	CKitchenApplianceMicrowave* data;
};

class microwaveQueue
{
public:
	microwaveQueue();
	void add(CKitchenApplianceMicrowave*);
	CKitchenApplianceMicrowave* remove();
	int length() { return n; };
private:
	int n;
	microwaveNode *front, *rear;
};

//Queue & Node for refrigerator
class refrigeratorNode
{
public:
	refrigeratorNode();
	refrigeratorNode* next;
	CKitchenApplianceRefrigerator* data;
};

class refrigeratorQueue
{
public:
	refrigeratorQueue();
	void add(CKitchenApplianceRefrigerator*);
	CKitchenApplianceRefrigerator* remove();
	int length() { return n; };
private:
	int n;
	refrigeratorNode *front, *rear;
};