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
	ml::DSPVector cache_;
	std::function<ml::DSPVector(const ml::DSPVector&)> transform_;
	bool cache_init_ = false;

public:

	SmoothParam(float default_value, int frames = kFloatsPerDSPVector * 8);

	void set_transform(std::function<ml::DSPVector(const ml::DSPVector&)> transform) { transform_ = transform; }

	void set_cache_dirty() { cache_init_ = false; }

	const ml::DSPVector& operator()();
};

}