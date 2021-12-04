#include "argv.hpp"
#include "help.hpp"
#include "int128.hpp"
#include "loadavg.hpp"
#include "primes.hpp"
#include <algorithm>
#include <chrono>
#include <iomanip>
#include <omp.h>
#include <string>

static const __uint128_t UINT128_MAX = __uint128_t(__int128_t(-1L));
static const __int128_t INT128_MAX = UINT128_MAX >> 1;

bool isnumber(std::string str) {
    for (int i = 0; i < (int)str.size(); ++i)
        if (str[i] < '0' || str[i] > '9') return false;
    return true;
}
