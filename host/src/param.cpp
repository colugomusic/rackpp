#include "..\..\module\include\rack++\module\param.h"
#include "..\..\module\include\rack++\module\param.h"
#include "..\..\module\include\rack++\module\param.h"
#include "host/param.h"

namespace rack {
namespace host {

Param::Param(std::shared_ptr<Module> module, int index, void* handle)
	: module_(module)
	, handle_(handle)
	, index_(index)
{
}

int Param::get_index() const
{
	return index_;
}

std::string Param::get_name() const
{
	return module_->ptrs.rack_param_get_name(handle_);
}

void Param::set_value(float value)
{
	module_->ptrs.rack_param_set_value(handle_, value);
}

void Param::set_value_buffer(const float* buffer)
{
	module_->ptrs.rack_param_set_value_buffer(handle_, buffer);
}

float Param::get_value() const
{
	return module_->ptrs.rack_param_get_value(handle_);
}

float Param::get_default_value() const
{
	return module_->ptrs.rack_param_get_default_value(handle_);
}

Rack_ParamFormatHint Param::get_format_hint() const
{
	return module_->ptrs.rack_param_get_format_hint(handle_);
}

float Param::get_size_hint() const
{
	return module_->ptrs.rack_param_get_size_hint(handle_);
}

float Param::get_min() const
{
	return module_->ptrs.rack_param_get_min(handle_);
}

float Param::get_max() const
{
	return module_->ptrs.rack_param_get_max(handle_);
}

std::string Param::get_switch_option_name(int id) const
{
	return module_->ptrs.rack_param_get_switch_option_name(handle_, id);
}

}}