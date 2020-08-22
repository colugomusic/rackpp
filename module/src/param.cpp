#include "module/param.h"

namespace rack {

void Param::copy(const Param& rhs)
{
	value_.store(rhs.value_);
}

void Param::reset()
{
	value_ = default_value_;
}

void Param::set_name(const std::string& name)
{
	name_ = name;
}

const std::string& Param::get_name() const
{
	return name_;
}

void Param::set(float value)
{
	value_ = value;

	notify(&ParamListener::on_param_value_changed, this, value);
}

float Param::get() const
{
	return value_;
}

void Param::set_default_value(float default_value)
{
	default_value_ = default_value;
}

float Param::get_default_value() const
{
	return default_value_;
}

void Param::set_format_hint(Rack_ParamFormatHint format)
{
	format_ = format;

	notify(&ParamListener::on_param_format_hint_changed, this, format_);
}

Rack_ParamFormatHint Param::get_format_hint() const
{
	return format_;
}

void Param::set_size_hint(float size)
{
	size_ = size;
}

float Param::get_size_hint() const
{
	return size_;
}

void Param::set_min(float value)
{
	min_ = value;

	notify(&ParamListener::on_param_min_changed, this, min_);
}

void Param::set_max(float value)
{
	max_ = value;

	notify(&ParamListener::on_param_max_changed, this, max_);
}

float Param::get_min() const
{
	return min_;
}

float Param::get_max() const
{
	return max_;
}

void Param::set_switch_options(const std::vector<std::string>& options)
{
	options_ = options;
}

const std::vector<std::string>& Param::get_switch_options() const
{
	return options_;
}

void Param::begin_notify()
{
	Listenable<ParamListener>::begin_notify();

	notify(&ParamListener::on_param_value_changed, this, value_.load());
	notify(&ParamListener::on_param_min_changed, this, min_);
	notify(&ParamListener::on_param_max_changed, this, max_);
	notify(&ParamListener::on_param_format_hint_changed, this, format_);
}

}