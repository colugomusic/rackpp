#include "module/smooth_param.h"

namespace rack {

SmoothParam::SmoothParam(float default_value, int frames)
{
	glide_.setGlideTimeInSamples(float(frames));

	set_default_value(default_value);
	set(default_value);

	glide_.setValue(default_value);
}

ml::DSPVector SmoothParam::operator()()
{
	auto value = glide_(Param::get());

	if (transform_) value = transform_(value);

	return value;
}

}