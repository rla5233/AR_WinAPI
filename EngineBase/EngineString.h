#pragma once
#include <string>
#include <string_view>


// Ό³Έν :
class EngineString
{
public:
	static std::string ToUpper(std::string_view _View);

protected:

private:
	// constructor destructor
	EngineString();
	~EngineString();

	// delete Function
	EngineString(const EngineString& _Other) = delete;
	EngineString(EngineString&& _Other) noexcept = delete;
	EngineString& operator=(const EngineString& _Other) = delete;
	EngineString& operator=(EngineString&& _Other) noexcept = delete;

};
