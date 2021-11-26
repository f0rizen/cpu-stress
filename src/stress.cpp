#include "int128.hpp"
#include "primes.hpp"
#include <algorithm>
#include <chrono>
#include <omp.h>

int main(int argc, char *argv[]) {
    omp_set_num_threads(8);
    __int128 cur = 1000000;
    std::chrono::steady_clock timer;
    auto start = timer.now();
#pragma omp parallel
    {
        while (true) {
            auto end = timer.now();
            auto time_span =
                static_cast<std::chrono::duration<double>>(end - start).count();
            if (time_span < double(std::stoi(argv[1]))) {
                get_primes(cur);
                ++cur;
            } else
                break;
        }
    }
    return 0;
}
