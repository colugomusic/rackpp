#pragma once

#include <iostream>
#include <deque>
#include <functional>

namespace rack {

template <class T>
class Listenable
{
	std::deque<T*> listeners_;
	bool notify_active_ = false;

protected:

	template <class Callback, class ...Args>
	void notify(Callback callback, Args ...args) const;

public:

	void add_listener(T* listener);

	virtual void begin_notify() { notify_active_ = true; }
};

template <class T>
template <class Callback, class ...Args>
void Listenable<T>::notify(Callback callback, Args ...args) const
{
	if (!notify_active_) return;

	for (auto listener : listeners_)
	{
		(listener->*callback)(args...);
	}
}

template <class T>
void Listenable<T>::add_listener(T* listener)
{
	listeners_.push_back(listener);
}

}
