#ifndef BENCHMARK_H
#define BENCHMARK_H

#include <chrono>
#include <string>


namespace Benchmark {

class Benchmark {
public:
    Benchmark(const std::string &name) : name(name) {}

    void run() {
        auto start = std::chrono::system_clock::now();
        benchmark();
        auto end = std::chrono::system_clock::now();
        duration = end - start;
        post_benchmark();
    }

protected:
    virtual void benchmark() = 0;
    virtual void post_benchmark() = 0;

    std::chrono::duration<double> duration;
    std::string name;
};

} // namespace Benchmark


#endif // BENCHMARK_H
