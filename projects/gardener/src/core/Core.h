#pragma once

#include <memory>

#ifdef GA_DEBUG
	#define GA_ENABLE_ASSERTS
#endif // GA_DEBUG

#ifdef GA_ENABLE_ASSERTS
	#define GA_ASSERT(x, ...) {if(!(x)){GA_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define GA_CORE_ASSERT(x, ...) {if(!(x)){GA_CORE_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define GA_ASSERT(x, ...)
	#define GA_CORE_ASSERT(x, ...)
#endif // GA_ENABLE_ASSERTS

#define BIT(x) (1 << x)

#define GA_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)

namespace Gardener {

	template<typename T>
	using Scope = std::unique_ptr<T>;

	template<typename T, typename ... Args>
	constexpr Scope<T> CreateScope(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}



	template<typename T>
	using Ref = std::shared_ptr<T>;

	template<typename T, typename ... Args>
	constexpr Ref<T> CreateRef(Args&& ... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}

}