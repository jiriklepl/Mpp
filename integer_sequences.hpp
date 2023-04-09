#include <bits/utility.h>
#include <utility>

template<class IntSeq>
struct integer_sequence_head;

template<class T, T Val, T ...Vals>
struct integer_sequence_head<std::integer_sequence<T, Val, Vals...>> {
    using value_type = T;
    static constexpr T value = Val;
};

template<class IntSeq>
inline constexpr auto integer_sequence_head_v = integer_sequence_head<IntSeq>::value;

template<class IntSeq>
struct integer_sequence_tail;

template<class T, T Val, T ...Vals>
struct integer_sequence_tail<std::integer_sequence<T, Val, Vals...>> {
    using value_type = std::integer_sequence<T, Vals...>;
    static constexpr value_type value = value_type();
};

template<class IntSeq>
inline constexpr auto integer_sequence_tail_v = integer_sequence_tail<IntSeq>::value;

template<class T, T ...LVals, T ...RVals>
constexpr auto integer_sequence_eq(std::integer_sequence<T, LVals...>, std::integer_sequence<T, RVals...>) {
    return (... && (LVals == RVals));
}

static_assert(integer_sequence_head_v<std::make_index_sequence<5>> == 0, "");
static_assert(integer_sequence_eq(integer_sequence_tail_v<std::make_index_sequence<5>>, std::index_sequence<1, 2, 3, 4>()), "");
