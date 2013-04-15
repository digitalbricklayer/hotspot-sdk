#pragma once

template <class T>
class deleter
{
public:

	deleter()
		{ }

	void operator() (T* element)
	{
		delete element;
	}

};
