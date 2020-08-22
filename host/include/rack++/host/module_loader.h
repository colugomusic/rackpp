#pragma once

#include <map>
#include "module.h"

namespace rack {
namespace host {

class ModuleLoader
{
	std::map<std::string, std::weak_ptr<Module>> store_;

public:

	std::shared_ptr<Module> operator[](const std::string& path);
};

}}