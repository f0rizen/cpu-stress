#include <algorithm>
#include <iostream>

static const __uint128_t UINT128_MAX = __uint128_t(__int128_t(-1L));
static const __int128_t INT128_MAX = UINT128_MAX >> 1;

std::ostream &operator<<(std::ostream &os, __int128 a) {
    std::string ans;
    while (a > 0) {
        ans.push_back(a % 10 + '0');
        a /= 10;
    }
    reverse(ans.begin(), ans.end());
    os << ans;
    return os;
}
