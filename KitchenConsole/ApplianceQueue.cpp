#include <iostream>
#include "ApplianceQueue.h"

template<class T> ApplianceQueueNode<T>::ApplianceQueueNode() : data(NULL), next(nullptr)
{
}

template<class T> ApplianceQueue<T>::ApplianceQueue() : front(nullptr), rear(nullptr), n(0)
{
}

template<class T> void ApplianceQueue<T>::add(T* value)
{
	//First create the node which will be inserted
	ApplianceQueueNode<T>* newNode = new ApplianceQueueNode<T>;
	newNode->data = value;
	newNode->next = NULL;

	//If the front of the queue is NULL, means that the queue is empty so the front and rear will be the same (newNode)
	if (front == NULL)
	{
		front = rear = newNode;
		n = 1;
	}
	//Else newNode will be pushed from the rear of the queue
	else
	{
		rear->next = newNode;
		rear = newNode;
		n++;
	}
}

template<class T> T* ApplianceQueue<T>::remove()
{
	ApplianceQueueNode<T>* temp;
	//If queue is deemed to be empty, there is nothing to remove!
	if (front == NULL || n == 0)
	{
		std::cout << "There are no units in stock!" << std::endl;
		return NULL;
	}
	//If only first space in queue was occupied, the whole queue will be empty after this
	else if (front == rear)
	{
		T* returnObj = new T(*front->data);
		temp = front;
		delete temp;
		front = rear = temp = NULL;
		n--;
		return returnObj;
	}
	//If 2+ objects in queue
	else
	{
		T* returnObj = new T(*front->data);
		temp = front;
		front = front->next;
		delete temp;
		n--;
		return returnObj;
	}
}
