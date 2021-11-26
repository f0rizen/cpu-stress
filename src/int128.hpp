#include <algorithm>
#include <iostream>

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
