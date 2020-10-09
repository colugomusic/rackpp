#include "module/smooth_param.h"

namespace rack {

SmoothParam::SmoothParam(float default_value, int frames)
{
	glide_.setGlideTimeInSamples(float(frames));

	set_default_value(default_value);
	set(default_value);

	glide_.setValue(default_value);
}

const ml::DSPVector& SmoothParam::operator()()
{
	auto glided = glide_(Param::get());

	if (!transform_)
	{
		cache_ = glided;

		return cache_;
	}

	if (!cache_init_ || (cache_[0] != glided[0]) && (cache_[kFloatsPerDSPVector - 1] != glided[kFloatsPerDSPVector - 1]))
	{
		cache_init_ = true;

		cache_ = transform_(glided);
	}

	return cache_;
}

}