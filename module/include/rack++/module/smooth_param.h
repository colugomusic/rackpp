#pragma once

#include <snd/control/smoother.h>
#include "param.h"
#include "smooth_param_listener.h"

namespace rack {

class SmoothParam : public Param, public Listenable<SmoothParamListener>
{
	snd::control::Smoother smoother_;
	std::deque<std::function<void(float)>> callbacks_;

	void smoother_callback(float v);

public:

	SmoothParam();

	void copy(const SmoothParam& rhs);
	void reset();

	void add_callback(std::function<void(float)> callback);
	void set_sample_rate(int SR);
	void update();

	void begin_notify();
};

}