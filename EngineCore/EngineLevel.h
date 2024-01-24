#pragma once
#include <EngineBase/EngineNameObject.h>

// ���� :
class EngineLevel : public EngineNameObject
{
public:
	// constructor destructor
	EngineLevel();
	~EngineLevel();

	// delete Function
	EngineLevel(const EngineLevel& _Other) = delete;
	EngineLevel(EngineLevel&& _Other) noexcept = delete;
	EngineLevel& operator=(const EngineLevel& _Other) = delete;
	EngineLevel& operator=(EngineLevel&& _Other) noexcept = delete;

protected:

private:

};
