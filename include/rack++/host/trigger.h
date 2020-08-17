#pragma once

#include "module.h"

namespace rack {
namespace host {

class Trigger
{
	std::shared_ptr<Module> module_;
	void* handle_;

public:
	Trigger(std::shared_ptr<Module> module, void* handle);

	std::string get_name() const;

	void fire() const;
};

}
}