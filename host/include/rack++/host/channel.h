#pragma once

#include "module.h"

namespace rack {
namespace host {

class Channel
{
	std::shared_ptr<Module> module_;
	void* handle_;

public:
	Channel(std::shared_ptr<Module> module, void* handle);

	std::string get_name() const;

	void rack_channel_set_buffer_stride(int stride);
	int rack_channel_get_buffer_stride();
	bool rack_channel_set_input_buffer(const float* in);
	const float* rack_channel_get_input_buffer();
	bool rack_channel_set_output_buffer(float* out);
	const float* rack_channel_get_output_buffer();
};

}}