#include <cstdlib>
#include <sys/types.h>
#include <vector>

std::vector<double> getstats() {
    double avg[3];
    getloadavg(avg, 3);
    std::vector<double> ans = {avg[0], avg[1], avg[2]};
    return ans;
}
