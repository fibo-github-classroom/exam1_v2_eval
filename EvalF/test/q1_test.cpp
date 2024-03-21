#include "q2_1.h"

#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include <cmath>
#include <cstdlib>

namespace {

TEST(EncoderString1, Test1) { EXPECT_EQ(EncoderString1("FIBO"), "QKZY"); }

TEST(EncoderString1, Test2) {
  EXPECT_EQ(EncoderString1("FIRST YEAR STUDENTS"), "QKHRT NDAH RTLPDVTR");
}

TEST(EncoderString1, Test3) {
  EXPECT_EQ(EncoderString1("SHOULD ALL PASS COMPUTER PROGRAMMING2!!"),
            "RMYLCP ACC SARR FYUSLTDH SHYOHAUUKVO2!!");
}

TEST(EncoderString1, Test4) {
  EXPECT_EQ(EncoderString1("ACCIO!@@@@_ _ []"), "AFFKY!@@@@_ _ []");
}

TEST(Decoder1, Test1) {
  EXPECT_EQ(Decoder1('A'), 'A');
  EXPECT_EQ(Decoder1('Q'), 'F');
  EXPECT_EQ(Decoder1('B'), 'K');
  EXPECT_EQ(Decoder1('E'), 'Z');
}

TEST(Decoder1, Test2) {
  EXPECT_EQ(Decoder1(' '), ' ');
  EXPECT_EQ(Decoder1('.'), '.');
  EXPECT_EQ(Decoder1('!'), '!');
}

TEST(DecoderString1, Test1) { EXPECT_EQ(DecoderString1("QKZY"), "FIBO"); }

TEST(DecoderString1, Test2) {
  EXPECT_EQ(DecoderString1("QKHRT NDAH RTLPDVTR"), "FIRST YEAR STUDENTS");
}

TEST(DecoderString1, Test3) {
  EXPECT_EQ(DecoderString1("RMYLCP ACC SARR FYUSLTDH SHYOHAUUKVO2!!"),
            "SHOULD ALL PASS COMPUTER PROGRAMMING2!!");
}

TEST(DecoderString1, Test4) {
  EXPECT_EQ(DecoderString1("AFFKY!@@@@_ _ []"), "ACCIO!@@@@_ _ []");
}

TEST(EncodeDecodeLowerCase, Test1) {
  EXPECT_EQ(Encoder1('a'), 'q');
  EXPECT_EQ(Encoder1('r'), 'g');
  EXPECT_EQ(Encoder1('t'), 'x');
}

TEST(EncodeDecodeLowerCase, Test2) {
  EXPECT_EQ(Decoder1('q'), 'a');
  EXPECT_EQ(Decoder1('g'), 'r');
  EXPECT_EQ(Decoder1('x'), 't');
}

TEST(EncodeDecodeLowerCase, Test3) {
  EXPECT_EQ(EncoderString1("grade"), "ogqhc");
}

TEST(EncodeDecodeLowerCase, Test4) {
  EXPECT_EQ(EncoderString1("easy A!"), "cqzp A!");
}

TEST(EncodeDecodeLowerCase, Test5) {
  EXPECT_EQ(EncoderString1("The Max Score of This Exam is 8.4."),
            "Tfc Uqy Rtrgc rs Tfiz Dyqe iz 8.4.");
}

TEST(EncodeDecodeLowerCase, Test6) {
  EXPECT_EQ(DecoderString1("Lvdcaicbqdac!"), "Unbelievable!");
}

TEST(EncoderString2, Test1) { EXPECT_EQ(EncoderString2("ZZZ"), "ZED"); }

TEST(EncoderString2, Test2) {
  EXPECT_EQ(EncoderString2("Fibo Student Are Extraordinary!"),
            "Fiho Lbeldkz Aoj Deeoarosifxgs!");
}

TEST(DecoderString2, Test1) { EXPECT_EQ(DecoderString2("ZED"), "ZZZ"); }

TEST(DecoderString2, Test2) {
  EXPECT_EQ(DecoderString2("Fiho Lbeldkz Aoj Deeoarosifxgs!"),
            "Fibo Student Are Extraordinary!");
}

TEST(Decoder2, Test1) { EXPECT_EQ(Decoder2('H'), 'F'); }

TEST(Decoder2, Test2) { EXPECT_EQ(Decoder2('L'), 'I'); }

TEST(Decoder2, Test3) {
  EXPECT_EQ(Decoder2('V'), 'B');
  EXPECT_EQ(Decoder2('A'), 'O');
}

TEST(Decoder2, Test4) {
  EXPECT_EQ(Decoder2('E'), 'A');
  EXPECT_EQ(Decoder2('N'), 'M');
  EXPECT_EQ(Decoder2('U'), 'N');
  EXPECT_EQ(Decoder2('C'), 'Z');
}

TEST(EncoderString3, Test1) { EXPECT_EQ(EncoderString3("AWESOME"), "AKDDYND"); }

TEST(EncoderString3, Test2) {
  EXPECT_EQ(EncoderString3("THIS IS EXTRA CREDIT!"), "TTKD LR DWTPA FPDSKQ!");
}

TEST(DecoderString3, Test1) { EXPECT_EQ(DecoderString3("AKDDYND"), "AWESOME"); }

TEST(DecoderString3, Test2) {
  EXPECT_EQ(DecoderString3("TTKD LR DWTPA FPDSKQ!"), "THIS IS EXTRA CREDIT!");
}
} // namespace
