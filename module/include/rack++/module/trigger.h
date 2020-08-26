#pragma once

#include <string>
#include "listenable.h"
#include "trigger_listener.h"

namespace rack {

class Trigger : public Listenable<TriggerListener>
{
	std::deque<std::function<void()>> callbacks_;

public:

	std::string name;

	void add_callback(std::function<void()> callback);
	void fire() const;
};

}