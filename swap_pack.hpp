// `swap_pack` swaps two values in a given `std::integer_sequence` object, returns the transformed `std::integer_sequence`.

// since C++20

#include <algorithm>
#include <utility>

template<class F, std::size_t ...Idxs>
constexpr auto transform_pack(F f, std::index_sequence<Idxs...>) {
	return std::integer_sequence<
		typename decltype(f(std::integral_constant<std::size_t, 0>()))::value_type,
		decltype(f(std::integral_constant<std::size_t, Idxs>()))::value...>();
}

template<std::size_t I, std::size_t J, class C, C ...Idxs>
constexpr auto swap_pack(std::integer_sequence<C, Idxs...>) {
	constexpr std::size_t l = std::min(I, J);
	constexpr std::size_t h = std::max(I, J);
	constexpr C idxs[] = {Idxs...};

	return transform_pack([&]<std::size_t X>(std::integral_constant<std::size_t, X>) {
		if constexpr (X != l && X != h)
			return std::integral_constant<C, idxs[X]>();
		else if constexpr (X == l)
			return std::integral_constant<C, idxs[h]>();
		else
			return std::integral_constant<C, idxs[l]>();
	}, std::make_index_sequence<sizeof...(Idxs)>());
}
