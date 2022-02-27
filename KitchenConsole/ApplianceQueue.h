#pragma once

template<class T> class ApplianceQueueNode
{
public:
	ApplianceQueueNode();
	T* data;
	ApplianceQueueNode* next;
};

template<class T> class ApplianceQueue
{
public:
	ApplianceQueue();
	void add(T*);
	T* remove();
	int length() { return n; };
private:
	int n;
	ApplianceQueueNode<T>* front, * rear;
};