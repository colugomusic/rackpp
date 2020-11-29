#pragma once

namespace rack {

class Trigger;

class TriggerListener
{
	friend class Trigger;

	virtual void on_trigger_fired(const Trigger* t) {};
};

}
