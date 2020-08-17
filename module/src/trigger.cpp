#include "module/trigger.h"

namespace rack {

void Trigger::fire() const
{
	notify(&TriggerListener::on_trigger_fired, this);
}

}
