#pragma once
#include "centity.h"
#include <stdint.h>
#include "../util/memory.h"

class ClientEntityList
{
public:
	virtual CEntity* GetClientEntity(int index) = 0;
	constexpr CEntity* GetEntityFromIndex(const int32_t index) noexcept
	{
		return memory::Call<CEntity*>(this, 3, index);
	}
	template <typename T = CEntity>
	constexpr T* Get1(int index)
	{
		return static_cast<T*>(GetClientEntity(index));
	}
};
