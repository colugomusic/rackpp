#pragma once

namespace rack {

class ChannelListener {
	friend class Channel;

	virtual void on_channel_input_buffer_changed(const Channel* c) {};
	virtual void on_channel_output_buffer_changed(const Channel* c) {};
};

}