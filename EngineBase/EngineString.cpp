#include "EngineString.h"

EngineString::EngineString()
{
}

EngineString::~EngineString()
{
}

std::string EngineString::ToUpper(std::string_view _View)
{
	std::string Name = _View.data();

	for (auto& _Ch : Name)
	{
		_Ch = std::toupper(_Ch);
	}

	return Name;
}
