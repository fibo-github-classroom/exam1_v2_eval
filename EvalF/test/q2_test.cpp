#include "q2_2.h"

#include "gmock/gmock.h"
#include "gtest/gtest.h"

namespace {

TEST(FindingTheOne, Test0_Base) {
  auto res = FindingTheOne({1}, {});
  EXPECT_EQ(res.x, 0);
  EXPECT_EQ(res.y, 1);
  EXPECT_EQ(res.total_steps, 1);
}

TEST(FindingTheOne, Test1_Base) {
  {
    auto res = FindingTheOne({2}, {});
    EXPECT_EQ(res.x, 1);
    EXPECT_EQ(res.y, 0);
    EXPECT_EQ(res.total_steps, 1);
  }
  {
    auto res = FindingTheOne({3}, {});
    EXPECT_EQ(res.x, 0);
    EXPECT_EQ(res.y, -1);
    EXPECT_EQ(res.total_steps, 1);
  }
  {
    auto res = FindingTheOne({4}, {});
    EXPECT_EQ(res.x, -1);
    EXPECT_EQ(res.y, 0);
    EXPECT_EQ(res.total_steps, 1);
  }
}

TEST(FindingTheOne, Test2_5Steps) {
  auto res = FindingTheOne({1, 1, 1, 1, 1}, {});
  EXPECT_EQ(res.x, 0);
  EXPECT_EQ(res.y, 5);
  EXPECT_EQ(res.total_steps, 5);
}

TEST(FindingTheOne, Test3_10Steps) {
  auto res = FindingTheOne({1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, {});
  EXPECT_EQ(res.x, -4);
  EXPECT_EQ(res.y, 6);
  EXPECT_EQ(res.total_steps, 10);
}

TEST(FindingTheOne, Test4_40Steps) {
  auto res =
      FindingTheOne({1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 4, 4,
                   3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2},
                  {});
  EXPECT_EQ(res.x, -20);
  EXPECT_EQ(res.y, 20);
  EXPECT_EQ(res.total_steps, 40);
}

TEST(FindingTheOne, Test5_50Steps) {
  auto res = FindingTheOne({4, 3, 3, 2, 1, 4, 1, 1, 3, 3, 3, 2, 1, 2, 2, 4, 3,
                          3, 2, 4, 2, 4, 1, 4, 4, 4, 4, 3, 1, 4, 4, 1, 4, 1,
                          1, 2, 2, 2, 2, 3, 4, 2, 4, 1, 3, 4, 4, 1, 3, 2},
                         {});
  EXPECT_EQ(res.x, -8);
  EXPECT_EQ(res.y, -6);
  EXPECT_EQ(res.total_steps, 50);
}

TEST(FindingTheOne, Test6_Traps) {
  const std::set<std::pair<int, int>> kTraps = {
      {1, 0}, {-1, 0}, {0, -1}, {0, 1}};
  {
    auto res = FindingTheOne({1}, kTraps);
    EXPECT_EQ(res.x, -1);
    EXPECT_EQ(res.y, 2);
    EXPECT_EQ(res.total_steps, 1);
  }
  {
    auto res = FindingTheOne({2}, kTraps);
    EXPECT_EQ(res.x, -1);
    EXPECT_EQ(res.y, 2);
    EXPECT_EQ(res.total_steps, 1);
  }
  {
    auto res = FindingTheOne({3}, kTraps);
    EXPECT_EQ(res.x, -2);
    EXPECT_EQ(res.y, 1);
    EXPECT_EQ(res.total_steps, 1);
  }
  {
    auto res = FindingTheOne({4}, kTraps);
    EXPECT_EQ(res.x, -2);
    EXPECT_EQ(res.y, 1);
    EXPECT_EQ(res.total_steps, 1);
  }
}

TEST(FindingTheOne, Test7_Traps) {
  const std::set<std::pair<int, int>> kTraps = {
      {1, 0}, {-1, 0}, {0, -1}, {0, 1}};
  auto res =
      FindingTheOne({1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 4, 4,
                   3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2},
                  kTraps);
  EXPECT_EQ(res.x, -26);
  EXPECT_EQ(res.y, 14);
  EXPECT_EQ(res.total_steps, 40);
}

TEST(FindingTheOne, Test8_Traps) {
  const std::set<std::pair<int, int>> kTraps = {
      {0, 3}, {-1, 4}, {-2, 5}, {-5, 6}, {-10, 7}};
  auto res =
      FindingTheOne({1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 4, 4,
                   3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2},
                  kTraps);
  EXPECT_EQ(res.x, -37);
  EXPECT_EQ(res.y, 3);
  EXPECT_EQ(res.total_steps, 40);
}

TEST(FindingTheOne, Test9_Traps) {
  const std::set<std::pair<int, int>> kTraps = {
      {-1, 0}, {-2, 1}, {-2, 0}, {-1, 1}, {2, 8}};
  auto res = FindingTheOne({4, 3, 3, 2, 1, 4, 1, 1, 3, 3, 3, 2, 1, 2, 2, 4, 3,
                          3, 2, 4, 2, 4, 1, 4, 4, 4, 4, 3, 1, 4, 4, 1, 4, 1,
                          1, 2, 2, 2, 2, 3, 4, 2, 4, 1, 3, 4, 4, 1, 3, 2},
                         kTraps);
  EXPECT_EQ(res.x, -5);
  EXPECT_EQ(res.y, 3);
  EXPECT_EQ(res.total_steps, 50);
}

} // namespace
