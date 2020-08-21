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

void BasicStereoEffect::process(int num_frames)
{
	const auto in_L_buffer = in_L_->get_input_buffer();
	const auto in_R_buffer = in_R_->get_input_buffer();
	const auto out_L_buffer = out_L_->get_output_buffer();
	const auto out_R_buffer = out_R_->get_output_buffer();

	const auto in_L_stride = in_L_->get_buffer_stride();
	const auto in_R_stride = in_R_->get_buffer_stride();
	const auto out_L_stride = out_L_->get_buffer_stride();
	const auto out_R_stride = out_R_->get_buffer_stride();

	for (int i = 0; i < num_frames; i++)
	{
		update_smooth_params();

		int in_idx = 0;
		int out_idx = 0;

		float value[2] = { 0.0f, 0.0f };

		if (out_L_buffer || (!in_R_buffer && in_R_buffer))
		{
			if (in_L_buffer)
			{
				process_left(in_L_buffer[i * in_L_stride], &(value[0]));
			}
		}

		if (out_R_buffer)
		{
			if (in_R_buffer)
			{
				process_right(in_R_buffer[i * in_R_stride], &(value[1]));
			}
			else if (in_L_buffer)
			{
				value[1] = value[0];
			}
		}

		if (out_L_buffer) out_L_buffer[i * out_L_stride] = value[0];
		if (out_R_buffer) out_R_buffer[i * out_R_stride] = value[1];
	}
}

}