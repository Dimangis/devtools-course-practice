// Copyright 2022 Mustafaev Dmitry

#include <gtest/gtest.h>

#include <vector>

#include "./include/dijkstra.h"

TEST(Algorithm, Test_Default_No_Throw) { ASSERT_NO_THROW(Algorithm Dijkstra); }

TEST(Algorithm, Test_Default_Copy_No_Throw) {
  Algorithm Dijkstra;
  ASSERT_NO_THROW(Algorithm simpleAlgorithm(Dijkstra));
}

TEST(Random_Vector, Test_Default_No_Throw) {
  Algorithm Dijkstra;
  ASSERT_NO_THROW(Dijkstra.getRandomVector());
}

TEST(Random_Vector, Test_No_Throw) {
  size_t count = 10;
  Algorithm Dijkstra;
  ASSERT_NO_THROW(Dijkstra.getRandomVector(count));
}

TEST(Dijkstra_Algorithm, Test_Default_No_Throw) {
  Algorithm Dijkstra;
  ASSERT_NO_THROW(Dijkstra.getDijkstra());
}

TEST(Dijkstra_Algorithm, Test_Default_Top_No_Throw) {
  const std::vector<std::vector<size_t>> graf = {
      {0, 7, 9, 0, 0, 14},  {7, 0, 10, 15, 0, 0}, {9, 10, 0, 11, 0, 2},
      {0, 15, 11, 0, 6, 0}, {0, 0, 0, 6, 0, 9},   {14, 0, 2, 0, 9, 0}};
  Algorithm Dijkstra;

  ASSERT_NO_THROW(Dijkstra.getDijkstra(graf));
}

TEST(Dijkstra_Algorithm, Test_No_Throw) {
  const std::vector<std::vector<size_t>> graf = {
      {0, 7, 9, 0, 0, 14},  {7, 0, 10, 15, 0, 0}, {9, 10, 0, 11, 0, 2},
      {0, 15, 11, 0, 6, 0}, {0, 0, 0, 6, 0, 9},   {14, 0, 2, 0, 9, 0}};
  const size_t top = 5;
  Algorithm Dijkstra;

  ASSERT_NO_THROW(Dijkstra.getDijkstra(graf, top));
}

TEST(Dijkstra_Algorithm, Test_Top_Greater_Count_No_Throw) {
  const std::vector<std::vector<size_t>> graf = {
      {0, 7, 9, 0, 0, 14},  {7, 0, 10, 15, 0, 0}, {9, 10, 0, 11, 0, 2},
      {0, 15, 11, 0, 6, 0}, {0, 0, 0, 6, 0, 9},   {14, 0, 2, 0, 9, 0}};
  const size_t top = 10;
  Algorithm Dijkstra;

  ASSERT_NO_THROW(Dijkstra.getDijkstra(graf, top));
}

TEST(Dijkstra_Algorithm, Test_Top_Null_Vector_No_Throw) {
  const std::vector<std::vector<size_t>> graf = {};
  const size_t top = 10;
  Algorithm Dijkstra;

  ASSERT_NO_THROW(Dijkstra.getDijkstra(graf, top));
}

TEST(Dijkstra_Algorithm, Test_Default_Top_Null_Vector_No_Throw) {
  const std::vector<std::vector<size_t>> graf = {};
  Algorithm Dijkstra;
  ASSERT_NO_THROW(Dijkstra.getDijkstra(graf));
}

TEST(Dijkstra_Algorithm, Test_First_Top_Null_Vector_No_Throw) {
  const std::vector<std::vector<size_t>> graf = {};
  const size_t top = 0;
  Algorithm Dijkstra;

  ASSERT_NO_THROW(Dijkstra.getDijkstra(graf, top));
}

TEST(Dijkstra_Algorithm, Test_Single_Top_Correctness) {
  const std::vector<std::vector<size_t>> graf = {{10}};
  const size_t top = 0;
  const size_t count = graf.size();
  const std::vector<size_t> trueResult = {0};
  bool check = true;
  Algorithm Dijkstra;

  std::vector<size_t> algorithmResult = Dijkstra.getDijkstra(graf, 0);
  for (size_t i = 0; i < count; ++i) {
    if (trueResult[i] != algorithmResult[i]) {
      check = false;
    }
  }

  ASSERT_EQ(check, true);
}

TEST(Dijkstra_Algorithm, Test_First_Top_With_Static_Data) {
  const std::vector<std::vector<size_t>> graf = {
      {0, 7, 9, 0, 0, 14},  {7, 0, 10, 15, 0, 0}, {9, 10, 0, 11, 0, 2},
      {0, 15, 11, 0, 6, 0}, {0, 0, 0, 6, 0, 9},   {14, 0, 2, 0, 9, 0}};
  const std::vector<size_t> trueResult = {0, 7, 9, 20, 20, 11};
  bool check = true;
  const size_t count = graf.size();
  Algorithm Dijkstra;

  std::vector<size_t> algorithmResult = Dijkstra.getDijkstra(graf, 0);
  for (size_t i = 0; i < count; ++i) {
    if (trueResult[i] != algorithmResult[i]) {
      check = false;
    }
  }

  ASSERT_EQ(check, true);
}

TEST(Dijkstra_Algorithm, Test_No_Top_With_Static_Data) {
  const std::vector<std::vector<size_t>> graf = {
      {0, 7, 9, 0, 0, 14},  {7, 0, 10, 15, 0, 0}, {9, 10, 0, 11, 0, 2},
      {0, 15, 11, 0, 6, 0}, {0, 0, 0, 6, 0, 9},   {14, 0, 2, 0, 9, 0}};
  const std::vector<size_t> trueResult = {0, 7, 9, 20, 20, 11};
  bool check = true;
  const size_t count = graf.size();
  Algorithm Dijkstra;

  std::vector<size_t> algorithmResult = Dijkstra.getDijkstra(graf);
  for (size_t i = 0; i < count; ++i) {
    if (trueResult[i] != algorithmResult[i]) {
      check = false;
    }
  }

  ASSERT_EQ(check, true);
}

TEST(Dijkstra_Algorithm, Test_Default_Top_With_Default_Data) {
  const std::vector<size_t> trueResult = {0, 7, 9, 20, 20, 11};
  bool check = true;
  const size_t count = 6;
  Algorithm Dijkstra;

  std::vector<size_t> algorithmResult = Dijkstra.getDijkstra();
  for (size_t i = 0; i < count; ++i) {
    if (trueResult[i] != algorithmResult[i]) {
      check = false;
    }
  }

  ASSERT_EQ(check, true);
}

TEST(Dijkstra_Algorithm, Test_Last_Top_With_Static_Data) {
  const std::vector<std::vector<size_t>> graf = {
      {0, 7, 9, 0, 0, 14},  {7, 0, 10, 15, 0, 0}, {9, 10, 0, 11, 0, 2},
      {0, 15, 11, 0, 6, 0}, {0, 0, 0, 6, 0, 9},   {14, 0, 2, 0, 9, 0}};
  const std::vector<size_t> trueResult = {11, 12, 2, 13, 9, 0};
  bool check = true;
  const size_t count = graf.size();
  Algorithm Dijkstra;

  std::vector<size_t> algorithmResult = Dijkstra.getDijkstra(graf, count - 1);
  for (size_t i = 0; i < count; ++i) {
    if (trueResult[i] != algorithmResult[i]) {
      check = false;
    }
  }

  ASSERT_EQ(check, true);
}

TEST(Dijkstra_Algorithm, Test_Last_Top_Two_Times_Static) {
  const std::vector<std::vector<size_t>> graf = {
      {0, 7, 9, 0, 0, 14},  {7, 0, 10, 15, 0, 0}, {9, 10, 0, 11, 0, 2},
      {0, 15, 11, 0, 6, 0}, {0, 0, 0, 6, 0, 9},   {14, 0, 2, 0, 9, 0}};
  bool check = true;
  const size_t count = graf.size();
  Algorithm Dijkstra;

  const std::vector<size_t> algorithmResultFirst =
      Dijkstra.getDijkstra(graf, count - 1);

  const std::vector<size_t> algorithmResultSecond =
      Dijkstra.getDijkstra(graf, count - 1);

  for (size_t i = 0; i < count; ++i) {
    if (algorithmResultFirst[i] != algorithmResultSecond[i]) {
      check = false;
    }
  }

  ASSERT_EQ(check, true);
}

TEST(Dijkstra_Algorithm, Test_Last_Top_Two_Times_Random) {
  Algorithm Dijkstra;
  const std::vector<std::vector<size_t>> graf = Dijkstra.getRandomVector(10);
  bool check = true;
  const size_t count = graf.size();

  const std::vector<size_t> algorithmResultFirst =
      Dijkstra.getDijkstra(graf, count - 1);

  const std::vector<size_t> algorithmResultSecond =
      Dijkstra.getDijkstra(graf, count - 1);

  for (size_t i = 0; i < count; ++i) {
    if (algorithmResultFirst[i] != algorithmResultSecond[i]) {
      check = false;
    }
  }

  ASSERT_EQ(check, true);
}
