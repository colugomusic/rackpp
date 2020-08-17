#pragma once

#include <string>
#include "listenable.h"
#include "trigger_listener.h"

namespace rack {

class Trigger : public Listenable<TriggerListener>
{
public:

	std::string name;

	void fire() const;
};

}