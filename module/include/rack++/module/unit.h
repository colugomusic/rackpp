#pragma once

#include <string>
#include <vector>

#include "channel_listener.h"
#include "param_listener.h"
#include "smooth_param_listener.h"
#include "trigger_listener.h"

namespace rack {

class Channel;
class Param;
class SmoothParam;
class Trigger;

class Unit : public ChannelListener, public ParamListener, public SmoothParamListener, public TriggerListener
{
	std::string name_;
	std::vector<Param*> params_;
	std::vector<SmoothParam*> smooth_params_;
	std::vector<Channel*> input_channels_;
	std::vector<Channel*> output_channels_;
	std::vector<Trigger*> triggers_;

	virtual void on_sample_rate_changed(int new_SR) {}

	std::uint32_t buffer_count_ = 0;

protected:

	int sample_rate_ = 44100;

	Param* add_param(float default_value, const std::string& name = "");
	SmoothParam* add_smooth_param(float default_value, const std::string& name = "");
	Param* add_switch_param(const std::vector<std::string>& options, const std::string& name = "");
	Channel* add_input_channel(const std::string& name = "");
	Channel* add_output_channel(const std::string& name = "");
	Trigger* add_trigger(const std::string& name = "");

	bool is_first_buffer() const { return buffer_count_ <= 1; }

	virtual void effect_process() = 0;
	virtual void effect_clear() = 0;

public:

	Unit(const std::string name = "");
	~Unit();

	void process();
	void clear();

	virtual void copy(const Unit& rhs);

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