#pragma once

#include "module.h"

namespace rack {
namespace host {

class Param
{
	std::shared_ptr<Module> module_;
	void* handle_;

public:
	Param(std::shared_ptr<Module> module, void* handle);

	std::string get_name() const;

	void set_value(float value);
	float get_value() const;
	int get_format_hint() const;
	float get_min() const;
	float get_max() const;
};

}}