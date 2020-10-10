#pragma once

#include <snd/control/smoother.h>
#include "param.h"
#include "smooth_param_listener.h"

#pragma warning(push, 0)
#include <DSP/MLDSPGens.h>
#pragma warning(pop)

namespace rack {

class SmoothParam : public Param
{
	ml::LinearGlide glide_;
	std::function<ml::DSPVector(const ml::DSPVector&)> transform_;

public:

	SmoothParam(float default_value, int frames = kFloatsPerDSPVector * 8);

	void set_transform(std::function<ml::DSPVector(const ml::DSPVector&)> transform) { transform_ = transform; }

	ml::DSPVector operator()();
};

}