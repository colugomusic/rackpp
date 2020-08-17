#pragma once

#include <string>
#include "listenable.h"
#include "channel_listener.h"

namespace rack {

class Channel : public Listenable<ChannelListener>
{
public:

	enum class Type
	{
		Input,
		Output,
	};

private:

	Type type_;

	const float* input_buffer_ = nullptr;
	float* output_buffer_ = nullptr;

	int buffer_stride_ = 1;

public:

	Channel(Type type);

	std::string name;

	bool set_input_buffer(const float* in);
	bool set_output_buffer(float* out);
	const float* get_input_buffer() const;
	float* get_output_buffer() const;
	void set_buffer_stride(int stride);
	int get_buffer_stride() const;

	void begin_notify() override;
};

}