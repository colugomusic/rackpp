#pragma once

#include <string>
#include <vector>

#include "channel_listener.h"
#include "param_listener.h"
#include "trigger_listener.h"

namespace rack {

class Channel;
class Param;
class Trigger;

class Unit : public ChannelListener, public ParamListener, public TriggerListener
{
	std::string name_;
	std::vector<Param*> params_;
	std::vector<Channel*> input_channels_;
	std::vector<Channel*> output_channels_;
	std::vector<Trigger*> triggers_;

	virtual void on_sample_rate_changed() {}

protected:

	int sample_rate_ = 44100;

	Param* add_param(const std::string& name = "");
	Param* add_switch_param(const std::vector<std::string>& options, const std::string& name = "");
	Channel* add_input_channel(const std::string& name = "");
	Channel* add_output_channel(const std::string& name = "");
	Trigger* add_trigger(const std::string& name = "");

public:

	Unit(const std::string name = "");
	~Unit();

	virtual void process(int num_frames) = 0;

	int get_num_params() const;
	Param* get_param(int id) const;
	int get_num_input_channels() const;
	int get_num_output_channels() const;
	int get_num_triggers() const;
	Channel* get_input_channel(int id) const;
	Channel* get_output_channel(int id) const;
	Trigger* get_trigger(int id) const;
	int get_sample_rate() const;
	void set_sample_rate(int sample_rate);
	const std::string& get_name() const;
};

}