#pragma once

struct float4
{
public:
	float X;
	float Y;
	float Z;
	float W;

public:

	float hX()
	{
		return X * 0.5f;
	}

	float hY()
	{
		return Y * 0.5f;
	}

	int iX()
	{
		return static_cast<int>(hX());
	}

	int iY()
	{
		return static_cast<int>(hY());
	}
};

using FVector = float4;

// Ό³Έν :
class EngineMath
{
public:
	// constructor destructor
	EngineMath();
	~EngineMath();

	// delete Function
	EngineMath(const EngineMath& _Other) = delete;
	EngineMath(EngineMath&& _Other) noexcept = delete;
	EngineMath& operator=(const EngineMath& _Other) = delete;
	EngineMath& operator=(EngineMath&& _Other) noexcept = delete;

protected:

private:

};
