#pragma once

#include <stdexcept>
#include <functional>
#include <sstream>
#include <boost/dll.hpp>

namespace rack {
namespace host {

class DLL
{

public:

	DLL(const std::string& path);

protected:

	template <typename F> std::function<F> get(const std::string& name)
	{
		if (!lib_.has(name))
		{
			std::stringstream ss;

			ss << "No symbol '" << name << "' in library: '" << lib_.location().string() << "'";

			throw std::runtime_error(ss.str());
		}

		return lib_.get<F>(name);
	}

	template <typename F> void get(std::function<F>* function, const std::string& name)
	{
		*function = get<F>(name);
	}

	boost::dll::shared_library lib_;
};

#define RACK_DLL_GET(Name) get(&this->Name, #Name)

}}