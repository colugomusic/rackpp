#include "host/module.h"
#include "host/unit.h"

namespace rack {
namespace host {

Module::Module(const std::string& path)
	: DLL(path)
{
	get(&ptrs.rack_get_api_version, "rack_get_api_version");
	get(&ptrs.rack_get_num_units, "rack_get_num_units");
	get(&ptrs.rack_get_module_name, "rack_get_module_name");
	get(&ptrs.rack_get_module_version, "rack_get_module_version");
	get(&ptrs.rack_get_module_vendor, "rack_get_module_vendor");

	get(&ptrs.rack_unit_make, "rack_unit_make");
	get(&ptrs.rack_unit_free, "rack_unit_free");
	get(&ptrs.rack_unit_get_name, "rack_unit_get_name");
	get(&ptrs.rack_unit_process, "rack_unit_process");
	get(&ptrs.rack_unit_get_num_params, "rack_unit_get_num_params");
	get(&ptrs.rack_unit_get_num_input_channels, "rack_unit_get_num_input_channels");
	get(&ptrs.rack_unit_get_num_output_channels, "rack_unit_get_num_output_channels");
	get(&ptrs.rack_unit_get_input_channel, "rack_unit_get_input_channel");
	get(&ptrs.rack_unit_get_output_channel, "rack_unit_get_output_channel");
	get(&ptrs.rack_unit_get_sample_rate, "rack_unit_get_sample_rate");
	get(&ptrs.rack_unit_set_sample_rate, "rack_unit_set_sample_rate");
	get(&ptrs.rack_unit_get_param, "rack_unit_get_param");

	get(&ptrs.rack_param_get_name, "rack_param_get_name");
	get(&ptrs.rack_param_set_value, "rack_param_set_value");
	get(&ptrs.rack_param_get_value, "rack_param_get_value");
	get(&ptrs.rack_param_get_default_value, "rack_param_get_default_value");
	get(&ptrs.rack_param_get_format_hint, "rack_param_get_format_hint");
	get(&ptrs.rack_param_get_size_hint, "rack_param_get_size_hint");
	get(&ptrs.rack_param_get_min, "rack_param_get_min");
	get(&ptrs.rack_param_get_max, "rack_param_get_max");
	get(&ptrs.rack_param_get_switch_option_name, "rack_param_get_switch_option_name");

	get(&ptrs.rack_channel_get_name, "rack_channel_get_name");
	get(&ptrs.rack_channel_set_input_buffer, "rack_channel_set_input_buffer");
	get(&ptrs.rack_channel_get_input_buffer, "rack_channel_get_input_buffer");
	get(&ptrs.rack_channel_set_output_buffer, "rack_channel_set_output_buffer");
	get(&ptrs.rack_channel_get_output_buffer, "rack_channel_get_output_buffer");

	get(&ptrs.rack_trigger_get_name, "rack_trigger_get_name");
	get(&ptrs.rack_trigger_fire, "rack_trigger_fire");
}

const char* Module::get_api_version() const
{
	return ptrs.rack_get_api_version();
}

int Module::get_num_units() const
{
	return ptrs.rack_get_num_units();
}

const char* Module::get_name() const
{
	return ptrs.rack_get_module_name();
}

const char* Module::get_version() const
{
	return ptrs.rack_get_module_version();
}

const char* Module::get_vendor() const
{
	return ptrs.rack_get_module_vendor();
}

std::shared_ptr<Unit> Module::make_unit(int id)
{
	return std::make_shared<Unit>(shared_from_this(), id);
}

std::shared_ptr<Module> open_module(const std::string& path)
{
	return std::make_shared<Module>(path);
}

}}