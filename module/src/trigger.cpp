#include "module/trigger.h"

namespace rack {

void Trigger::fire() const
{
	notify(&TriggerListener::on_trigger_fired, this);

	for (auto cb : callbacks_)
	{
		cb();
	}
}

void Trigger::add_callback(std::function<void()> callback)
{
	callbacks_.push_back(callback);
}

}
