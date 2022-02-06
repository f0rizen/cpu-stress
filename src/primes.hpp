inline bool prime(__int128 n) {
    for (__int128 d = 2; d * d <= n; ++d)
        if (n % d == 0) return false;
    return true;
}

__int128 get_primes(__int128 x) {
    __int128 ans = 0;
    for (__int128 i = 2; i <= x; ++i)
        if (prime(i)) ++ans;
    return ans;
}
