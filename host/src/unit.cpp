#include "host/unit.h"

namespace rack {
namespace host {

Unit::Unit(std::shared_ptr<Module> module, int id)
	: module_(module)
	, handle_(module->ptrs.rack_unit_make(id))
{
}

Unit::~Unit()
{
	module_->ptrs.rack_unit_free(handle_);
}

Unit::operator bool() const
{
	return handle_;
}

void Unit::clear()
{
	module_->ptrs.rack_unit_clear(handle_);
}

void Unit::process()
{
	module_->ptrs.rack_unit_process(handle_);
}

std::string Unit::get_name() const
{
	return module_->ptrs.rack_unit_get_name(handle_);
}

int Unit::get_sample_rate() const
{
	return module_->ptrs.rack_unit_get_sample_rate(handle_);
}

int Unit::get_num_params() const
{
	return module_->ptrs.rack_unit_get_num_params(handle_);
}

int Unit::get_num_input_channels() const
{
	return module_->ptrs.rack_unit_get_num_input_channels(handle_);
}

int Unit::get_num_output_channels() const
{
	return module_->ptrs.rack_unit_get_num_output_channels(handle_);
}

void Unit::set_sample_rate(int sr)
{
	module_->ptrs.rack_unit_set_sample_rate(handle_, sr);
}

Channel Unit::get_input_channel(int id) const
{
	return Channel(module_, module_->ptrs.rack_unit_get_input_channel(handle_, id));
}

Channel Unit::get_output_channel(int id) const
{
	return Channel(module_, module_->ptrs.rack_unit_get_output_channel(handle_, id));
}

Param Unit::get_param(int id)
{
	return Param(module_, id, module_->ptrs.rack_unit_get_param(handle_, id));
}

}}