#pragma once

#include <rack/rack.h>

namespace rack {

class ParamListener {
	friend class Param;

	virtual void on_param_value_changed(const Param* p, float new_value) {};
	virtual void on_param_min_changed(const Param* p, float new_min) {};
	virtual void on_param_max_changed(const Param* p, float new_max) {};
	virtual void on_param_format_hint_changed(const Param* p, Rack_ParamFormatHint new_format) {};
};

}