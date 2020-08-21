#pragma once

#include <rack/rack.h>
#include "dll.h"

namespace rack {
namespace host {

class Unit;

class Module : public DLL, public std::enable_shared_from_this<Module>
{
public:

	Module(const std::string& path);

	struct {
		std::function<const char* ()> rack_get_api_version;
		std::function<int()> rack_get_num_units;
		std::function<const char*()> rack_get_module_name;
		std::function<const char* ()> rack_get_module_version;
		std::function<const char* ()> rack_get_module_vendor;

		std::function<void* (int id)> rack_unit_make;
		std::function<void(void* handle)> rack_unit_free;
		std::function<const char* (void* handle)> rack_unit_get_name;
		std::function<void(void* handle, int num_frames)> rack_unit_process;
		std::function<int(void* handle)> rack_unit_get_num_params;
		std::function<int(void* handle)> rack_unit_get_num_input_channels;
		std::function<int(void* handle)> rack_unit_get_num_output_channels;
		std::function<void* (void* handle, int id)> rack_unit_get_input_channel;
		std::function<void* (void* handle, int id)> rack_unit_get_output_channel;
		std::function<int(void* handle)> rack_unit_get_sample_rate;
		std::function<void(void* handle, int sample_rate)> rack_unit_set_sample_rate;
		std::function<void* (void* handle, int id)> rack_unit_get_param;

		std::function<const char* (void* handle)> rack_param_get_name;
		std::function<void(void* handle, float value)> rack_param_set_value;
		std::function<float(void* handle)> rack_param_get_value;
		std::function<float(void* handle)> rack_param_get_default_value;
		std::function<Rack_ParamFormatHint(void* handle)> rack_param_get_format_hint;
		std::function<float(void* handle)> rack_param_get_size_hint;
		std::function<float(void* handle)> rack_param_get_min;
		std::function<float(void* handle)> rack_param_get_max;
		std::function<const char* (void* handle, int id)> rack_param_get_switch_option_name;

		std::function<const char* (void* handle)> rack_channel_get_name;
		std::function<void(void* handle, int side, char enabled)> rack_channel_set_enabled;
		std::function<char(void* handle, int side)> rack_channel_get_enabled;
		std::function<char(void* handle)> rack_channel_is_stereo;

		std::function<void (void* handle, int stride)> rack_channel_set_buffer_stride;
		std::function<int (void* handle)> rack_channel_get_buffer_stride;
		std::function<char (void* handle, const float* in)> rack_channel_set_input_buffer;
		std::function<const float* (void* handle)> rack_channel_get_input_buffer;
		std::function<char (void* handle, float* out)> rack_channel_set_output_buffer;
		std::function<float* (void* handle)> rack_channel_get_output_buffer;

		std::function<const char* (void* handle)> rack_trigger_get_name;
		std::function<void (void* handle)> rack_trigger_fire;
	} ptrs;

	const char* get_api_version() const;
	int get_num_units() const;
	const char* get_name() const;
	const char* get_version() const;
	const char* get_vendor() const;
	std::shared_ptr<Unit> make_unit(int id);
};

extern std::shared_ptr<Module> open_module(const std::string& path);

}}