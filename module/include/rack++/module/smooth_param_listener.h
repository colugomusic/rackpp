#pragma once

namespace rack {

class SmoothParamListener {
	friend class SmoothParam;

	virtual void on_smooth_param_value_changed(const SmoothParam* sp, float new_value) {};
};

}