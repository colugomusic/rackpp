#include "module/channel.h"
#include "module/param.h"
#include "module/trigger.h"
#include "module/unit.h"

namespace rack {

Param* Unit::add_param(const std::string& name)
{
	auto param = new Param();

	param->name = name;
	param->add_listener(this);

	params_.push_back(param);

	return param;
}

Param* Unit::add_switch_param(const std::vector<std::string>& options, const std::string& name)
{
	auto param = new Param();

	param->name = name;
	param->set_format_hint(Rack_ParamFormatHint_Switch);
	param->set_switch_options(options);
	param->add_listener(this);

	params_.push_back(param);

	return param;
}

Channel* Unit::add_input_channel(const std::string& name)
{
	auto channel = new Channel(Channel::Type::Input);

	channel->name = name;
	channel->add_listener(this);

	input_channels_.push_back(channel);

	return channel;
}

Channel* Unit::add_output_channel(const std::string& name)
{
	auto channel = new Channel(Channel::Type::Output);

	channel->name = name;
	channel->add_listener(this);

	output_channels_.push_back(channel);

	return channel;
}

Trigger* Unit::add_trigger(const std::string& name)
{
	auto trigger = new Trigger();

	trigger->name = name;
	trigger->add_listener(this);

	triggers_.push_back(trigger);

	return trigger;
}

Unit::Unit(const std::string name)
	: name_(name)
{
}

Unit::~Unit()
{
	for (auto channel : output_channels_)
	{
		delete channel;
	}

	for (auto param : params_)
	{
		delete param;
	}

	for (auto trigger : triggers_)
	{
		delete trigger;
	}
}

int Unit::get_num_params() const
{
	return int(params_.size());
}

Param* Unit::get_param(int id) const
{
	return params_[id];
}

int Unit::get_num_input_channels() const
{
	return int(input_channels_.size());
}

int Unit::get_num_output_channels() const
{
	return int(output_channels_.size());
}

int Unit::get_num_triggers() const
{
	return int(triggers_.size());
}

Channel* Unit::get_input_channel(int id) const
{
	return input_channels_[id];
}

Channel* Unit::get_output_channel(int id) const
{
	return output_channels_[id];
}

Trigger* Unit::get_trigger(int id) const
{
	return triggers_[id];
}

int Unit::get_sample_rate() const
{
	return sample_rate_;
}

void Unit::set_sample_rate(int sample_rate)
{
	sample_rate_ = sample_rate;

	on_sample_rate_changed();
}

const std::string& Unit::get_name() const
{
	return name_;
}

}