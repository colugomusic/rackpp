#include "module/param.h"

namespace rack {

void Param::set(float value)
{
	value_ = value;

	notify(&ParamListener::on_param_value_changed, this);
}

float Param::get() const
{
	return value_;
}

void Param::set_format_hint(Rack_ParamFormatHint format)
{
	format_ = format;
}

Rack_ParamFormatHint Param::get_format_hint() const
{
	return format_;
}

void Param::set_min(float value)
{
	min_ = value;
}

void Param::set_max(float value)
{
	max_ = value;
}

float Param::get_min() const
{
	return min_;
}

float Param::get_max() const
{
	return max_;
}

void Param::begin_notify()
{
	Listenable<ParamListener>::begin_notify();

	notify(&ParamListener::on_param_value_changed, this);
	notify(&ParamListener::on_param_min_changed, this);
	notify(&ParamListener::on_param_max_changed, this);
	notify(&ParamListener::on_param_format_hint_changed, this);
}

}