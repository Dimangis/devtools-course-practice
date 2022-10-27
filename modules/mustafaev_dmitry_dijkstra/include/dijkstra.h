// Copyright 2022 Mustafaev Dmitry

#ifndef MODULES_MUSTAFAEV_DMITRY_DIJKSTRA_INCLUDE_DIJKSTRA_H_
#define MODULES_MUSTAFAEV_DMITRY_DIJKSTRA_INCLUDE_DIJKSTRA_H_

#include <string>
#include <vector>

class Algorithm {
 public:
  std::vector<std::vector<size_t>> getRandomVector(const size_t count = 2);
  std::vector<size_t> getDijkstra(
      const std::vector<std::vector<size_t>>& graf = {{0, 7, 9, 0, 0, 14},
                                                      {7, 0, 10, 15, 0, 0},
                                                      {9, 10, 0, 11, 0, 2},
                                                      {0, 15, 11, 0, 6, 0},
                                                      {0, 0, 0, 6, 0, 9},
                                                      {14, 0, 2, 0, 9, 0}},
      size_t top = 0);
};

#endif  // MODULES_MUSTAFAEV_DMITRY_DIJKSTRA_INCLUDE_DIJKSTRA_H_
