#ifndef BENCHMARK_H
#define BENCHMARK_H

#include <chrono>
#include <string>


namespace Benchmark {

class Benchmark {
public:
    Benchmark(const std::string &name) : name(name) {}

private:
    virtual void benchmark() = 0;

    std::string name;
};

} // namespace Benchmark


#endif // BENCHMARK_H
