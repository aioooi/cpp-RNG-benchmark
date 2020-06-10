#ifndef RNGBENCHMARK_H
#define RNGBENCHMARK_H

#include <iostream>
#include <string>

#include "benchmark.h"

namespace Benchmark {

template <class RNG, class DIST, class FLOATTYPE>
class RNGBenchmark : public Benchmark {
 public:
  RNGBenchmark(const std::string &name, const DIST &distribution,
               const unsigned int seed, const unsigned long trials)
      : Benchmark(name),
        distribution(distribution),
        seed(seed),
        trials(trials) {}

 protected:
  void benchmark() {
    RNG rng(seed);
    for (unsigned long i = 0; i < trials; ++i) {
      FLOATTYPE sample = distribution(rng);
    }
  }

  void post_benchmark() {
    std::cout << "Benchmark " << name << ":" << std::endl
              << trials << " samples in " << duration.count()
              << " seconds, i.e., " << trials / duration.count()
              << " samples per second" << std::endl;
  }

  DIST distribution;
  unsigned int seed;
  unsigned long trials;
};

}  // namespace Benchmark

#endif  // RNGBENCHMARK_H
