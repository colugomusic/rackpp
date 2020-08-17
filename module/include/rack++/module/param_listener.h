#pragma once

namespace rack {

class ParamListener {
	friend class Param;

	virtual void on_param_value_changed(const Param* p) {};
	virtual void on_param_min_changed(const Param* p) {};
	virtual void on_param_max_changed(const Param* p) {};
	virtual void on_param_format_hint_changed(const Param* p) {};
};

}