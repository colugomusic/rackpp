#pragma once

#include "channel.h"
#include "param.h"

namespace rack {
namespace host {

class Unit
{
	std::shared_ptr<Module> module_;
	void* handle_;

public:

	Unit(std::shared_ptr<Module> module, int id);
	~Unit();

	operator bool() const;

	void process(int num_frames);

	std::string get_name() const;
	int get_sample_rate() const;
	int get_num_params() const;
	int get_num_input_channels() const;
	int get_num_output_channels() const;

	void set_sample_rate(int sr);

	Channel get_input_channel(int id) const;
	Channel get_output_channel(int id) const;

	Param get_param(int id);
};

}}