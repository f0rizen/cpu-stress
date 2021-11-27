#include "argv.hpp"
#include "int128.hpp"
#include "primes.hpp"
#include <algorithm>
#include <chrono>
#include <cstdlib>
#include <omp.h>
#include <string>

bool isnumber(std::string str) {
    for (int i = 0; i < (int)str.size(); ++i)
        if (str[i] < '0' || str[i] > '9') return false;
    return true;
}

int main(int argc, char *argv[]) {
    argvparse flags(argc, argv);
    int th = 0;
    if (!flags.flagExists("--threads")) {
        th = omp_get_max_threads();
        omp_set_num_threads(th);
    }
    else {
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
    std::cout << "Running on " << th << " threads\n";
    std::cout << "Ctrl + C to stop\n";
    __int128 cur = 1000000;
#pragma omp parallel
    {
        while (true) {
            get_primes(cur);
            ++cur;
        }
    }
    return 0;
}
