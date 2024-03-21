#include "q2_2.h"

#include "gmock/gmock.h"
#include "gtest/gtest.h"

namespace {

TEST(FindingNano, Test0_Base) {
  auto res = FindingNano({1}, {});
  EXPECT_EQ(res.x, 0);
  EXPECT_EQ(res.y, 1);
  EXPECT_EQ(res.total_steps, 1);
}

TEST(FindingNano, Test1_Base) {
  {
    auto res = FindingNano({2}, {});
    EXPECT_EQ(res.x, 1);
    EXPECT_EQ(res.y, 0);
    EXPECT_EQ(res.total_steps, 1);
  }
  {
    auto res = FindingNano({3}, {});
    EXPECT_EQ(res.x, 0);
    EXPECT_EQ(res.y, -1);
    EXPECT_EQ(res.total_steps, 1);
  }
  {
    auto res = FindingNano({4}, {});
    EXPECT_EQ(res.x, -1);
    EXPECT_EQ(res.y, 0);
    EXPECT_EQ(res.total_steps, 1);
  }
}

TEST(FindingNano, Test2_5Steps) {
  auto res = FindingNano({1, 1, 1, 1, 1}, {});
  EXPECT_EQ(res.x, 0);
  EXPECT_EQ(res.y, 5);
  EXPECT_EQ(res.total_steps, 5);
}

TEST(FindingNano, Test3_10Steps) {
  auto res = FindingNano({1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, {});
  EXPECT_EQ(res.x, 4);
  EXPECT_EQ(res.y, 6);
  EXPECT_EQ(res.total_steps, 10);
}

TEST(FindingNano, Test4_40Steps) {
  auto res =
      FindingNano({2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 4, 4, 4, 4, 4, 4, 3, 3,
                   2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 4, 4, 4, 4, 4, 4, 3, 3, 3, 3},
                  {});
  EXPECT_EQ(res.x, 20);
  EXPECT_EQ(res.y, 20);
  EXPECT_EQ(res.total_steps, 40);
}

TEST(FindingNano, Test5_50Steps) {
  auto res = FindingNano({4, 3, 3, 2, 1, 4, 1, 1, 3, 3, 3, 2, 1, 2, 2, 4, 3,
                          3, 2, 4, 2, 4, 1, 4, 4, 4, 4, 3, 1, 4, 4, 1, 4, 1,
                          1, 2, 2, 2, 2, 3, 4, 2, 4, 1, 3, 4, 4, 1, 3, 2},
                         {});
  EXPECT_EQ(res.x, -2);
  EXPECT_EQ(res.y, 0);
  EXPECT_EQ(res.total_steps, 50);
}

TEST(FindingNano, Test6_Traps) {
  const std::set<std::pair<int, int>> kTraps = {
      {1, 0}, {-1, 0}, {0, -1}, {0, 1}};
  {
    auto res = FindingNano({1}, kTraps);
    EXPECT_EQ(res.x, 2);
    EXPECT_EQ(res.y, -1);
    EXPECT_EQ(res.total_steps, 1);
  }
  {
    auto res = FindingNano({2}, kTraps);
    EXPECT_EQ(res.x, 2);
    EXPECT_EQ(res.y, -1);
    EXPECT_EQ(res.total_steps, 1);
  }
  {
    auto res = FindingNano({3}, kTraps);
    EXPECT_EQ(res.x, 1);
    EXPECT_EQ(res.y, -2);
    EXPECT_EQ(res.total_steps, 1);
  }
  {
    auto res = FindingNano({4}, kTraps);
    EXPECT_EQ(res.x, 1);
    EXPECT_EQ(res.y, -2);
    EXPECT_EQ(res.total_steps, 1);
  }
}

TEST(FindingNano, Test7_Traps) {
  const std::set<std::pair<int, int>> kTraps = {
      {1, 0}, {-1, 0}, {0, -1}, {0, 1}};
  auto res =
      FindingNano({2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 4, 4, 4, 4, 4, 4, 3, 3,
                   2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 4, 4, 4, 4, 4, 4, 3, 3, 3, 3},
                  kTraps);
  EXPECT_EQ(res.x, 12);
  EXPECT_EQ(res.y, -16);
  EXPECT_EQ(res.total_steps, 40);
}

TEST(FindingNano, Test8_Traps) {
  const std::set<std::pair<int, int>> kTraps = {
      {3, 0}, {4, -1}, {5, -2}, {6, -3}, {7, -4}};
  auto res =
      FindingNano({2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 4, 4, 4, 4, 4, 4, 3, 3,
                   2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 4, 4, 4, 4, 4, 4, 3, 3, 3, 3},
                  kTraps);
  EXPECT_EQ(res.x, 26);
  EXPECT_EQ(res.y, -20);
  EXPECT_EQ(res.total_steps, 40);
}

TEST(FindingNano, Test9_Traps) {
  const std::set<std::pair<int, int>> kTraps = {
      {-1, 0}, {0, -2}, {0, 5}, {1, 3}, {2, 8}};
  auto res = FindingNano({4, 3, 3, 2, 1, 4, 1, 1, 3, 3, 3, 2, 1, 2, 2, 4, 3,
                          3, 2, 4, 2, 4, 1, 4, 4, 4, 4, 3, 1, 4, 4, 1, 4, 1,
                          1, 2, 2, 2, 2, 3, 4, 2, 4, 1, 3, 4, 4, 1, 3, 2},
                         kTraps);
  EXPECT_EQ(res.x, 3);
  EXPECT_EQ(res.y, -1);
  EXPECT_EQ(res.total_steps, 50);
}

} // namespace
