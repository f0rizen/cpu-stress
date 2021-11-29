#include "argv.hpp"
#include "help.hpp"
#include "int128.hpp"
#include "loadavg.hpp"
#include "primes.hpp"
#include <algorithm>
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

int main(int argc, char *argv[]) {
    argvparse flags(argc, argv);
    if (flags.flagExists("--help")) {
        gethelp();
        exit(0);
    }
    int th = 0;
    if (!flags.flagExists("--threads")) {
        th = omp_get_max_threads();
        omp_set_num_threads(th);
    } else {
        const std::string &threads = flags.getFlag("--threads");
        if (threads.empty()) {
            std::cout << "--threads <number of threads to use>\n";
            exit(1);
        }
        if (!isnumber(threads)) {
            std::cout << "--threads <NUMBER of threads to use>\n";
            exit(1);
        }
        th = std::min(omp_get_max_threads(), atoi(threads.c_str()));
        omp_set_num_threads(th);
    }
    std::cout << "Running on " << th << " OpenMP thread(s)\n";
    std::cout << "Ctrl + c to stop\n";
    __int128 cur = 2000000;
#pragma omp parallel
    {
        while (cur < INT128_MAX) {
            get_primes(cur);
            ++cur;
            auto vec = getstats();
            std::cout << std::flush << cur << " " << vec[0] << " " << vec[1]
                      << " " << vec[2] << std::setw(4) << '\r';
        }
    }
    return 0;
}
