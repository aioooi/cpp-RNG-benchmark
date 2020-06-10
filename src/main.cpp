#include <boost/random/mersenne_twister.hpp>
#include <boost/random/normal_distribution.hpp>
#include <boost/random/taus88.hpp>
#include <chrono>
#include <random>

#include "rngbenchmark.h"

int main() {
  const int SEED = 235;
  const unsigned long TRIALS = 1 << 27;

  std::vector<Benchmark::Benchmark *> benchmarks = {
      new Benchmark::RNGBenchmark<std::mt19937, std::normal_distribution<float>,
                                  float>(
          "std::mt199937 and std::normal_distribution in float precision",
          std::normal_distribution<float>(0, 1), SEED, TRIALS),

      new Benchmark::RNGBenchmark<std::mt19937,
                                  std::normal_distribution<double>, double>(
          "std::mt199937 and std::normal_distribution in double precision",
          std::normal_distribution<double>(0, 1), SEED, TRIALS),

      new Benchmark::RNGBenchmark<std::mt19937_64,
                                  std::normal_distribution<float>, float>(
          "std::mt199937_64 and std::normal_distribution in float precision",
          std::normal_distribution<float>(0, 1), SEED, TRIALS),

      new Benchmark::RNGBenchmark<std::mt19937_64,
                                  std::normal_distribution<double>, double>(
          "std::mt199937_64 and std::normal_distribution in double precision",
          std::normal_distribution<double>(0, 1), SEED, TRIALS),

      new Benchmark::RNGBenchmark<std::minstd_rand,
                                  std::normal_distribution<float>, float>(
          "std::minstd_rand and std::normal_distribution in float precision",
          std::normal_distribution<float>(0, 1), SEED, TRIALS),

      new Benchmark::RNGBenchmark<std::minstd_rand,
                                  std::normal_distribution<double>, double>(
          "std::minstd_rand and std::normal_distribution in double precision",
          std::normal_distribution<double>(0, 1), SEED, TRIALS),

      new Benchmark::RNGBenchmark<boost::random::mt19937,
                                  boost::random::normal_distribution<float>,
                                  float>(
          "boost::random::mt19937 and boost::random::normal_distribution in "
          "float precision",
          boost::random::normal_distribution<float>(0, 1), SEED, TRIALS),

      new Benchmark::RNGBenchmark<boost::random::mt19937,
                                  boost::random::normal_distribution<double>,
                                  double>(
          "boost::random::mt19937 and boost::random::normal_distribution in "
          "double precision",
          boost::random::normal_distribution<double>(0, 1), SEED, TRIALS),

      new Benchmark::RNGBenchmark<boost::random::mt19937_64,
                                  boost::random::normal_distribution<float>,
                                  float>(
          "boost::random::mt19937_64 and boost::random::normal_distribution in "
          "float precision",
          boost::random::normal_distribution<float>(0, 1), SEED, TRIALS),

      new Benchmark::RNGBenchmark<boost::random::mt19937_64,
                                  boost::random::normal_distribution<double>,
                                  double>(
          "boost::random::mt19937_64 and boost::random::normal_distribution in "
          "double precision",
          boost::random::normal_distribution<double>(0, 1), SEED, TRIALS),

      new Benchmark::RNGBenchmark<boost::random::mt11213b,
                                  boost::random::normal_distribution<float>,
                                  float>(
          "boost::random::mt11213b and boost::random::normal_distribution in "
          "float precision",
          boost::random::normal_distribution<float>(0, 1), SEED, TRIALS),

      new Benchmark::RNGBenchmark<boost::random::mt11213b,
                                  boost::random::normal_distribution<double>,
                                  double>(
          "boost::random::mt11213b and boost::random::normal_distribution in "
          "double precision",
          boost::random::normal_distribution<double>(0, 1), SEED, TRIALS),

      new Benchmark::RNGBenchmark<boost::random::taus88,
                                  boost::random::normal_distribution<float>,
                                  float>(
          "boost::random::taus88 and boost::random::normal_distribution in "
          "float precision",
          boost::random::normal_distribution<float>(0, 1), SEED, TRIALS),

      new Benchmark::RNGBenchmark<boost::random::taus88,
                                  boost::random::normal_distribution<double>,
                                  double>(
          "boost::random::taus88 and boost::random::normal_distribution in "
          "double precision",
          boost::random::normal_distribution<double>(0, 1), SEED, TRIALS),
  };

  for (const auto &bm : benchmarks) {
    bm->run();
    std::cout << std::endl;
  }

  // example to (crudely) verify (low) benchmark class overhead:
  boost::random::taus88 rng(SEED);
  boost::random::normal_distribution<double> dist(0, 1);
  
  auto start = std::chrono::system_clock::now();
  for (long i = 0; i < TRIALS; ++i) {
    double s = dist(rng);
  }
  std::chrono::duration<double> duration =
      std::chrono::system_clock::now() - start;
  
  std::cout << std::endl
            << "Running without Benchmark class:" << std::endl
            << "Benchmark boost::random::taus88 and "
               "boost::random::normal_distribution in double precision:"
            << std::endl
            << TRIALS << " samples in " << duration.count()
            << " seconds, i.e., " << TRIALS / duration.count()
            << " samples per second" << std::endl;

  return 0;
}
