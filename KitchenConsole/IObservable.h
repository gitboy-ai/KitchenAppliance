#pragma once
#include "IObserver.h"

class IObserver;
class IObservable		// store
{
	public:
		virtual bool Register(IObserver* observer) = 0;
};