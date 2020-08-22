#include "host/module_loader.h"

namespace rack {
namespace host {

std::shared_ptr<Module> ModuleLoader::operator[](const std::string& path)
{
	auto find = store_.find(path);

	if (find == store_.end())
	{
		auto module = open_module(path);

		store_[path] = module;

		return module;
	}

	auto module = find->second;

	if (module.expired())
	{
		auto module = open_module(path);

		store_[path] = module;

		return module;
	}

	return module.lock();
}

}}