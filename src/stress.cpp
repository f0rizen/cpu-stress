#include "stress.hpp"

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
        if (!std::all_of(threads.begin(), threads.end(), ::isdigit)) {
            std::cout << "--threads <NUMBER of threads to use>\n";
            exit(1);
        }
        th = std::min(omp_get_max_threads(), atoi(threads.c_str()));
        omp_set_num_threads(th);
    }
    std::cout << "Running on " << th << " OpenMP thread(s)\n";
    std::cout << "Ctrl + c to stop\n";
    __int128 cur = 2000000;
    std::chrono::steady_clock timer;
    auto start = timer.now();
#pragma omp parallel
    {
        while (cur < INT128_MAX) {
            get_primes(cur);
            ++cur;
            auto vec = getstats();
            auto end = timer.now();
            auto time = static_cast<std::chrono::duration<double>>(end - start);
            std::cout << std::flush << "cur = " << cur
                      << "; loadavg: " << vec[0] << " " << vec[1] << " "
                      << vec[2] << "; running time: " << time.count()
                      << std::setw(4) << '\r';
        }
    }
    return 0;
}
