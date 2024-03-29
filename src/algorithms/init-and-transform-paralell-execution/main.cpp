#include <cassert>
#include <chrono>
#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <algorithm>
#include <ranges>
#include <execution>

void initialize(std::vector<double> &x, std::vector<double> &y)
{
    assert(x.size() == y.size());
    // Parallelize initialization of `x`. Notice that `x.data()` is captured by value.
    auto ints = std::views::iota(0); // unbounded (infinite)

    std::for_each_n(std::execution::par_unseq, ints.begin(), x.size(), [x = x.data()](int i)
                    { x[i] = (double)i; });

    // Parallelize initialization of `y`
    std::fill_n(std::execution::par_unseq, y.begin(), y.size(), 2.);
}

void daxpy(double a, std::vector<double> const &x, std::vector<double> &y)
{
    assert(x.size() == y.size());
    // Parallelize DAXPY computation. Notice that `a` is captured by value.
    std::transform(std::execution::par_unseq, x.begin(), x.end(), y.begin(), y.begin(),
                   [a](double x, double y)
                   { return a * x + y; });
}

// Check solution
bool check(double a, std::vector<double> const &y);

int main(int argc, char *argv[])
{
    // Read CLI arguments, the first argument is the name of the binary:
    if (argc != 2)
    {
        std::cerr << "ERROR: Missing length argument!" << std::endl;
        return 1;
    }

    // Read length of vector elements
    long long n = std::stoll(argv[1]);

    // Allocate the vector
    std::vector<double> x(n, 0.), y(n, 0.);
    double a = 2.0;

    initialize(x, y);

    daxpy(a, x, y);

    if (!check(a, y))
    {
        std::cerr << "ERROR!" << std::endl;
        return 1;
    }

    std::cerr << "OK!" << std::endl;

    // Measure bandwidth in [GB/s]
    using clk_t = std::chrono::steady_clock;
    daxpy(a, x, y);
    auto start = clk_t::now();
    int nit = 100;
    for (int it = 0; it < nit; ++it)
    {
        daxpy(a, x, y);
    }
    auto seconds = std::chrono::duration<double>(clk_t::now() - start).count(); // Duration in [s]
                                                                                // Amount of bytes transferred from/to chip.
                                                                                // x is read, y is read and written:
    auto gigabytes =
        static_cast<double>((x.size() + 2 * y.size()) * sizeof(double) * nit) / 1.e9; // GB
    std::cerr << "Bandwidth [GB/s]: " << (gigabytes / seconds) << std::endl;

    return 0;
}

bool check(double a, std::vector<double> const &y)
{
    double tolerance = 2. * std::numeric_limits<double>::epsilon();
    for (std::size_t i = 0; i < y.size(); ++i)
    {
        double should = a * i + 2.;
        if (std::abs(y[i] - should) > tolerance)
            return false;
    }
    return true;
}
