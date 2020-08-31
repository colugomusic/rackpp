#include "module/smooth_param.h"

namespace rack {

SmoothParam::SmoothParam()
	: smoother_(44100, 0.02f, std::bind(&SmoothParam::smoother_callback, this, std::placeholders::_1))
{
}

void SmoothParam::add_callback(std::function<void(float)> callback)
{
	callbacks_.push_back(callback);
}

void SmoothParam::set_sample_rate(int SR)
{
	smoother_.set_sample_rate(SR);
}

void SmoothParam::update()
{
	smoother_(get());
}

void SmoothParam::smoother_callback(float v)
{
	Listenable<SmoothParamListener>::notify(&SmoothParamListener::on_smooth_param_value_changed, this, v);

	for (auto cb : callbacks_)
	{
		cb(v);
	}
}

void SmoothParam::begin_notify()
{
	Param::begin_notify();

	const auto value = get();

	Listenable<SmoothParamListener>::notify(&SmoothParamListener::on_smooth_param_value_changed, this, value);

	for (auto cb : callbacks_)
	{
		cb(value);
	}
}

void SmoothParam::copy(const SmoothParam& rhs)
{
	Param::copy(rhs);

	smoother_.copy(rhs.smoother_);
}

void SmoothParam::reset()
{
	smoother_(get());
	smoother_.reset();
}

}