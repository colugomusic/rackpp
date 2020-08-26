#pragma once

#include <atomic>
#include <string>
#include <vector>
#include <rack/rack.h>
#include "listenable.h"
#include "param_listener.h"

namespace rack {

class Param : public Listenable<ParamListener>
{
	std::string name_;
	Rack_ParamFormatHint format_ = Rack_ParamFormatHint_Float;
	std::vector<std::string> options_;
	float size_ = 1.0f;
	float min_ = 0.0f;
	float max_ = 1.0f;
	std::atomic<float> value_ = 0.0f;
	float default_value_ = 0.0f;

public:

	void copy(const Param& rhs);

	void set_name(const std::string& name);
	const std::string& get_name() const;

	void set(float value);
	float get() const;

	void set_default_value(float default_value);
	float get_default_value() const;

	void set_format_hint(Rack_ParamFormatHint format);
	Rack_ParamFormatHint get_format_hint() const;

	void set_size_hint(float size);
	float get_size_hint() const;

	void set_min(float value);
	void set_max(float value);

	float get_min() const;
	float get_max() const;

	void set_switch_options(const std::vector<std::string>& options);
	const std::vector<std::string>& get_switch_options() const;

	void begin_notify() override;
};

}