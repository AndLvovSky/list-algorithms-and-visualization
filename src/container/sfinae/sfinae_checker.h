#ifndef SFINAE_CHECKER_H
#define SFINAE_CHECKER_H

#include <type_traits>

/**
 * Namespace is used for SFINAE checks, that allow to determine
 * existing of operator less (<).
 */
namespace SFINAEChecker {

    struct No {};

    template<typename T>
    No operator < (const T&, const T&);

    template<typename T>
    constexpr bool less_operator_exists() {
        return !std::is_same<decltype(*(T*)0 < *(T*)0), No>::value;
    }

};

#endif // SFINAE_CHECKER_H
