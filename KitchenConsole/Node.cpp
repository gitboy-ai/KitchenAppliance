/*
#include "Node.h"
#include <string>
#include <iostream>

Node::Node() : value(0), next(0), prev(0), type(node_type_none)
{
}

Node::Node(void* value, nodeType type) : value(value), next(0), prev(0), type(type)
{
}

void* Node::prepareString(std::string string)
{
	void* vp = static_cast<void*>(new std::string(string));
	//std::string* sp = static_cast<std::string*>(vp);
	return vp;
}

Node* Node::addNext(void* value, nodeType type)
{
	Node* nextNode = new Node(value, type);
	this->next = nextNode;
	return nextNode;
}

Node* Node::addPrev(void* value, nodeType type)
{
	Node* prevNode = new Node(value, type);
	this->prev = prevNode;
	return prevNode;
}

bool Node::addNext(std::string value)
{
	Node* nextNode = new Node(prepareString(value), node_type_string);
	this->next = nextNode;
	return true;
}
bool Node::addPrev(std::string value)
{
	Node* prevNode = new Node(prepareString(value), node_type_string);
	this->prev = prevNode;
	return true;
}


void Node::display(Node* firstNode)
{
	Node* currentNode = firstNode;
	while (currentNode != nullptr)
	{
		switch (type)
		{
			case node_type_int:
				std::cout << *((int*)currentNode->value) << std::endl;
				break;
			case node_type_string:
			{
				//std::string temp = (std::string)*((std::string*)currentNode->value);
				std::string* sp = static_cast<std::string*>(currentNode->value);
				std::cout << *sp << std::endl;
				//std::cout << temp << std::endl;
				//std::cout << &temp << std::endl;
			}
				break;
		}
		currentNode = currentNode->next;
	}
}
*/