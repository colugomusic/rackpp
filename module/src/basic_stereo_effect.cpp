#include "module/basic_stereo_effect.h"
#include "module/channel.h"

namespace rack {

BasicStereoEffect::BasicStereoEffect(const std::string& name)
	: Unit(name)
{
	in_L_ = add_input_channel();
	in_R_ = add_input_channel();

	in_L_->name = "Input:Left";
	in_R_->name = "Input:Right";

	out_L_ = add_output_channel();
	out_R_ = add_output_channel();

	out_L_->name = "Output:Left";
	out_R_->name = "Output:Right";

	in_L_->begin_notify();
	in_R_->begin_notify();
	out_L_->begin_notify();
	out_R_->begin_notify();
}

void BasicStereoEffect::effect_process()
{
	const auto in_L_buffer = in_L_->get_input_buffer();
	const auto in_R_buffer = in_R_->get_input_buffer();
	const auto out_L_buffer = out_L_->get_output_buffer();
	const auto out_R_buffer = out_R_->get_output_buffer();

	ml::DSPVectorArray<2> in;

	if (out_L_buffer)
	{
		if (in_L_buffer)
		{
			ml::load(in.row(0), in_L_buffer);
		}
	}

	if (out_R_buffer)
	{
		if (in_R_buffer)
		{
			ml::load(in.row(1), in_R_buffer);
		}
		else if (in_L_buffer)
		{
			ml::load(in.row(1), in_L_buffer);
		}
	}

	auto out = this->operator()(in);

	ml::store(out.constRow(0), out_L_buffer);
	ml::store(out.constRow(1), out_R_buffer);
}

}