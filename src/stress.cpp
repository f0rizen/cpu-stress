#include "stress.hpp"

int main(int argc, char *argv[]) {
    cmdparse::init(argc, argv);
    if (cmdparse::vm.count("help")) {
        std::cout << cmdparse::desc << "\n";
        return 0;
    }
    int th = omp_get_max_threads();
    if (cmdparse::vm.count("threads")) th = cmdparse::vm["threads"].as<int>();
    th = std::min(omp_get_max_threads(), th);
    omp_set_num_threads(th);
    bool quiet = false;
    if (cmdparse::vm.count("quiet")) quiet = true;
    if (!quiet) {
        std::cout << "Running on " << th << " OpenMP thread(s)\n";
        std::cout << "Ctrl + c to stop\n";
    }
    double timeout = -1;
    if (cmdparse::vm.count("timeout")) timeout = cmdparse::vm["timeout"].as<double>();
    __int128 cur = 2000000;
    if (cmdparse::vm.count("cur")) cur = cmdparse::vm["cur"].as<__int128>();
    std::chrono::steady_clock timer;
    auto start = timer.now();
    bool abort = false;
    int it = 1;
#pragma omp parallel
    {
        while (cur < INT128_MAX && !abort) {
            get_primes(cur);
            ++cur;
            auto vec = getstats();
            auto end = timer.now();
            auto time = static_cast<std::chrono::duration<double>>(end - start);
            if (timeout != -1 && time.count() > timeout) abort = true;
            if (!quiet && cur % 10 == 0)
                std::cout << std::flush << "[" << it / 10 << "]  cur = " << cur
                          << " | loadavg: " << vec[0] << " " << vec[1] << " " << vec[2]
                          << " | running time: " << time.count() << "\n";
            ++it;
        }
    }
    return 0;
}
