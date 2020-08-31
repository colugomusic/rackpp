#include "module/channel.h"

namespace rack {

Channel::Channel(Type type)
	: type_(type)
{
}

bool Channel::set_input_buffer(const float* in)
{
	if (type_ != Type::Input) return false;

	input_buffer_ = in;

	notify(&ChannelListener::on_channel_input_buffer_changed, this);

	return true;
}

bool Channel::set_output_buffer(float* out)
{
	if (type_ != Type::Output) return false;

	output_buffer_ = out;

	notify(&ChannelListener::on_channel_output_buffer_changed, this);

	return true;
}

const float* Channel::get_input_buffer() const
{
	return input_buffer_;
}

float* Channel::get_output_buffer() const
{
	return output_buffer_;
}

void Channel::begin_notify()
{
	Listenable<ChannelListener>::begin_notify();

	notify(&ChannelListener::on_channel_input_buffer_changed, this);
	notify(&ChannelListener::on_channel_output_buffer_changed, this);
}

}