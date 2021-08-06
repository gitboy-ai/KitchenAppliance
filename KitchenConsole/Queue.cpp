#include <iostream>
#include "Queue.h"

microwaveQueue::microwaveQueue() : front(nullptr), rear(nullptr), n(0)
{
}

microwaveNode::microwaveNode() : data(NULL), next(nullptr)
{
}

void microwaveQueue::add(CKitchenApplianceMicrowave* value)
{
	// First create the node which will be inserted
	microwaveNode* newNode = new microwaveNode;
	newNode->data = value;
	newNode->next = NULL;

	// If the front of the queue is NULL, means that the queue is empty so the front and rear will be the same (newNode)
	if ( front == NULL )
	{
		front = rear = newNode;
		n = 1;
	}
	// Else newNode will be pushed from the rear of the queue
	else
	{
		rear->next = newNode;
		rear = newNode;
		n++;
	}
}

CKitchenApplianceMicrowave* microwaveQueue::remove()
{
	microwaveNode* temp;
	// If queue is deemed to be empty, there is nothing to remove!
	if (front == NULL || n == 0) 
	{
		std::cout << "There are no units in stock!" << std::endl;
		return NULL;
	}
	// If only first space in queue was occupied, the whole queue will be empty after this
	else if (front == rear)
	{
		CKitchenApplianceMicrowave* returnObj = new CKitchenApplianceMicrowave(*front->data);
		temp = front;
		delete temp;
		front = rear = temp = NULL;
		n--;
		return returnObj;
	}
	// If 2+ objects in queue
	else
	{
		CKitchenApplianceMicrowave* returnObj = new CKitchenApplianceMicrowave(*front->data);
		temp = front;
		front = front->next;
		delete temp;
		n--;
		return returnObj;
	}
}

refrigeratorQueue::refrigeratorQueue() : front(nullptr), rear(nullptr), n(0)
{
}

refrigeratorNode::refrigeratorNode() : data(NULL), next(nullptr)
{
}

void refrigeratorQueue::add(CKitchenApplianceRefrigerator* value)
{
	// First create the node which will be inserted
	refrigeratorNode* newNode = new refrigeratorNode;
	newNode->data = value;
	newNode->next = NULL;

	// If the front of the queue is NULL, means that the queue is empty so the front and rear will be the same (newNode)
	if (front == NULL)
	{
		front = rear = newNode;
		n = 1;
	}
	// Else newNode will be pushed from the rear of the queue
	else
	{
		rear->next = newNode;
		rear = newNode;
		n++;
	}
}

CKitchenApplianceRefrigerator* refrigeratorQueue::remove()
{
	refrigeratorNode* temp;	// Temporary node for use later in the function

	// If queue is deemed to be empty, there is nothing to remove!
	if (front == NULL)
	{
		std::cout << "There are no units in stock!" << std::endl;
		return NULL;
	}
	// If only first space in queue was occupied, the whole queue will be empty after this
	else
	{
		CKitchenApplianceRefrigerator* returnObj;
		temp = front;
		returnObj = temp->data;
		front = front->next;
		delete temp;
		n--;
		return returnObj;
	}
}