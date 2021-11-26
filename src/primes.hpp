#include <vector>

bool prime(int n) {
    for (int d = 2; d * d <= n; ++d)
        if (n % d == 0) return false;
    return true;
}

__int128 get_primes(__int128 x) {
    __int128 ans = 0;
    for (int i = 2; i <= x; ++i)
        if (prime(i)) ++ans;
    return ans;
}
