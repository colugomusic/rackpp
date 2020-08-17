#include "host/dll.h"

using namespace boost;

namespace rack {
namespace host {

DLL::DLL(const std::string& path)
	: lib_(path)
{
}

}}