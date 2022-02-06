#include <boost/program_options.hpp>

namespace cmdparse {
boost::program_options::variables_map vm;
boost::program_options::options_description desc("Usage: stress [OPTION...]");
void init(int argc, char **argv) {
    desc.add_options()("help,h", "Display this help message")(
        "threads,t", boost::program_options::value<int>(), "Number of threads to use")(
        "cur,c", boost::program_options::value<__int128>(), "The start value of variable \"cur\"")(
        "quiet,q", "Don't produce any output")("timeout,i", boost::program_options::value<double>(),
                                               "Specify a timeout");
    boost::program_options::store(boost::program_options::parse_command_line(argc, argv, desc), vm);
    boost::program_options::notify(vm);
}
} // namespace cmdparse
