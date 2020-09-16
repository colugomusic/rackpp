#pragma once

#include "module.h"

namespace rack {
namespace host {

class Param
{
	std::shared_ptr<Module> module_;
	void* handle_;
	int index_;

public:
	Param(std::shared_ptr<Module> module, int index, void* handle);

	std::string get_name() const;

	void set_value(float value);
	void set_value_buffer(const float* buffer);
	int get_index() const;
	float get_value() const;
	float get_default_value() const;
	Rack_ParamFormatHint get_format_hint() const;
	float get_size_hint() const;
	float get_min() const;
	float get_max() const;
	std::string get_switch_option_name(int id) const;
};

}}