#pragma once
#include <EngineBase/EngineDebug.h>

// Ό³Έν :
class UTickObject
{
public:
	// constructor destructor
	UTickObject();
	virtual ~UTickObject();

	// delete Function
	UTickObject(const UTickObject& _Other) = delete;
	UTickObject(UTickObject&& _Other) noexcept = delete;
	UTickObject& operator=(const UTickObject& _Other) = delete;
	UTickObject& operator=(UTickObject&& _Other) noexcept = delete;

	void ActiveOn()
	{
		IsActiveValue = true;
	}

	void ActiveOff()
	{
		IsActiveValue = false;
	}

	void SetActive(bool _Active)
	{
		IsActiveValue = _Active;
	}

	bool IsActive()
	{
		return IsActiveValue && IsDestroyValue == false;
	}

	void Destroy()
	{
		IsDestroyValue = true;
	}

	bool IsDestroy()
	{
		return IsDestroyValue;
	}

	int GetOrder()
	{
		return Order;
	}

	virtual void SetOrder(int _Order)
	{
		Order = _Order;
	}

	virtual void BeginPlay();
	virtual void Tick(float _DeltaTime);

protected:

private:
	int Order = 0;
	bool IsActiveValue = true;
	bool IsDestroyValue = false;
	
};
