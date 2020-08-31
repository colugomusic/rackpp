#include "host/channel.h"

namespace rack {
namespace host {

Channel::Channel(std::shared_ptr<Module> module, void* handle)
	: module_(module)
	, handle_(handle)
{
}

std::string Channel::get_name() const
{
	return module_->ptrs.rack_channel_get_name(handle_);
}

bool Channel::rack_channel_set_input_buffer(const float* in)
{
	return module_->ptrs.rack_channel_set_input_buffer(handle_, in);
}

const float* Channel::rack_channel_get_input_buffer()
{
	return module_->ptrs.rack_channel_get_input_buffer(handle_);
}

bool Channel::rack_channel_set_output_buffer(float* out)
{
	return module_->ptrs.rack_channel_set_output_buffer(handle_, out);
}

const float* Channel::rack_channel_get_output_buffer()
{
	return module_->ptrs.rack_channel_get_output_buffer(handle_);
}

}}