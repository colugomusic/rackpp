#pragma once

#include "unit.h"

#pragma warning(push, 0)
#include <DSP/MLDSPOps.h>
#pragma warning(pop)

namespace rack {

/// base class for simple stereo effects with two inputs and two outputs
/// for left and right channels
///
/// the right output channel will be copied from the left channel if:
///		- the right input channel is disabled, and
///		- the right output channel is enabled, and
///		- the left input channel is enabled
class BasicStereoEffect : public Unit
{
	Channel* in_L_ = nullptr;
	Channel* in_R_ = nullptr;
	Channel* out_L_ = nullptr;
	Channel* out_R_ = nullptr;

	virtual ml::DSPVectorArray<2> operator()(const ml::DSPVectorArray<2>& in) = 0;

public:

	BasicStereoEffect(const std::string& name);

	virtual void process(int num_frames);
};

}