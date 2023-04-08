// `is_defined` is `std::true_type` and `is_defined_v` is `true` if and only if the given class implements a value.

// since C++17

#include <type_traits>

template<class ValueType, class = void>
struct is_defined : std::false_type {};

template<class ValueType>
struct is_defined<ValueType, std::void_t<decltype(ValueType::value)>> : std::true_type {};

template<class ValueType>
inline constexpr bool  is_defined_v = is_defined<ValueType>::value;

// Use-case:
struct undefined;

struct defined {
    static constexpr int value = 42;
};

// - Proof:
static_assert(is_defined<defined>::value, "`defined` is defined");
static_assert(is_defined_v<defined>, "`defined` is defined");

static_assert(!is_defined<undefined>::value, "`undefined` is not defined");
static_assert(!is_defined_v<undefined>, "`undefined` is not defined");
