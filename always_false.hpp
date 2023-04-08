// `always_false` and `always_false_v` are just templated `false` values. Useful with `static_assert`s.

#include <type_traits>

// since C++14
template<class>
inline constexpr bool always_false = false;

// since C++14
template<auto>
inline constexpr bool always_false_v = false;


// Use-case:
template<class Arg>
struct cannot_be_instantiated {
    // You can imagine more nontrivial condition:
    static_assert(always_false<Arg>, "You cannot instatiate this class");
};

template<auto Arg>
struct cannot_be_instantiated2 {
    // You can imagine more nontrivial condition:
    static_assert(always_false_v<Arg>, "You cannot instatiate this class");
};
