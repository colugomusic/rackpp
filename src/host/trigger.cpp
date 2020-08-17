#include "host/trigger.h"

namespace rack {
namespace host {

Trigger::Trigger(std::shared_ptr<Module> module, void* handle)
	: module_(module)
	, handle_(handle)
{
}

std::string Trigger::get_name() const
{
	return module_->ptrs.rack_trigger_get_name(handle_);
}

void Trigger::fire() const
{
	module_->ptrs.rack_trigger_fire(handle_);
}

}}