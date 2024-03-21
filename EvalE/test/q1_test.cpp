#include "q2_1.h"

#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include <cmath>
#include <cstdlib>

namespace {

TEST(EncoderString1, Test1) { EXPECT_EQ(EncoderString1("FIBO"), "ZOUE"); }

TEST(EncoderString1, Test2) {
  EXPECT_EQ(EncoderString1("FIRST YEAR STUDENTS"), "ZOYIM NCGY IMVHCKMI");
}

TEST(EncoderString1, Test3) {
  EXPECT_EQ(EncoderString1("SHOULD ALL PASS COMPUTER PROGRAMMING2!!"),
            "IPEVWH GWW FGII DEAFVMCY FYEJYGAAOKJ2!!");
}

TEST(EncoderString1, Test4) {
  EXPECT_EQ(EncoderString1("ACCIO!@@@@_ _ []"), "GDDOE!@@@@_ _ []");
}

TEST(Decoder1, Test1) {
  EXPECT_EQ(Decoder1('G'), 'A');
  EXPECT_EQ(Decoder1('Z'), 'F');
  EXPECT_EQ(Decoder1('R'), 'K');
  EXPECT_EQ(Decoder1('T'), 'Z');
}

TEST(Decoder1, Test2) {
  EXPECT_EQ(Decoder1(' '), ' ');
  EXPECT_EQ(Decoder1('.'), '.');
  EXPECT_EQ(Decoder1('!'), '!');
}

TEST(DecoderString1, Test1) { EXPECT_EQ(DecoderString1("ZOUE"), "FIBO"); }

TEST(DecoderString1, Test2) {
  EXPECT_EQ(DecoderString1("ZOYIM NCGY IMVHCKMI"), "FIRST YEAR STUDENTS");
}

TEST(DecoderString1, Test3) {
  EXPECT_EQ(DecoderString1("IPEVWH GWW FGII DEAFVMCY FYEJYGAAOKJ2!!"),
            "SHOULD ALL PASS COMPUTER PROGRAMMING2!!");
}

TEST(DecoderString1, Test4) {
  EXPECT_EQ(DecoderString1("GDDOE!@@@@_ _ []"), "ACCIO!@@@@_ _ []");
}

TEST(EncodeDecodeLowerCase, Test1) {
  EXPECT_EQ(Encoder1('a'), 'r');
  EXPECT_EQ(Encoder1('r'), 'p');
  EXPECT_EQ(Encoder1('t'), 'g');
}

TEST(EncodeDecodeLowerCase, Test2) {
  EXPECT_EQ(Decoder1('r'), 'a');
  EXPECT_EQ(Decoder1('p'), 'r');
  EXPECT_EQ(Decoder1('g'), 't');
}

TEST(EncodeDecodeLowerCase, Test3) {
  EXPECT_EQ(EncoderString1("grade"), "fprso");
}

TEST(EncodeDecodeLowerCase, Test4) {
  EXPECT_EQ(EncoderString1("easy A!"), "orcb G!");
}

TEST(EncodeDecodeLowerCase, Test5) {
  EXPECT_EQ(EncoderString1("The Max Score of This Exam is 8.4."),
            "Mvo Arz Imapo ai Mvhc Czrq hc 8.4.");
}

TEST(EncodeDecodeLowerCase, Test6) {
  EXPECT_EQ(DecoderString1("Vudothokrdto!"), "Unbelievable!");
}

TEST(EncoderString2, Test1) { EXPECT_EQ(EncoderString2("AAA"), "AGJ"); }

TEST(EncoderString2, Test2) {
  EXPECT_EQ(EncoderString2("Fibo Student Are Extraordinary!"),
            "Fhsp Dkvrgyc Cdy Wjnooopckglge!");
}

TEST(DecoderString2, Test1) { EXPECT_EQ(DecoderString2("AGJ"), "AAA"); }

TEST(DecoderString2, Test2) {
  EXPECT_EQ(DecoderString2("Fhsp Dkvrgyc Cdy Wjnooopckglge!"),
            "Fibo Student Are Extraordinary!");
}

TEST(Decoder2, Test1) { EXPECT_EQ(Decoder2('V'), 'F'); }

TEST(Decoder2, Test2) { EXPECT_EQ(Decoder2('L'), 'I'); }

TEST(Decoder2, Test3) {
  EXPECT_EQ(Decoder2('Q'), 'B');
  EXPECT_EQ(Decoder2('H'), 'O');
}

TEST(Decoder2, Test4) {
  EXPECT_EQ(Decoder2('F'), 'A');
  EXPECT_EQ(Decoder2('E'), 'M');
  EXPECT_EQ(Decoder2('D'), 'N');
  EXPECT_EQ(Decoder2('U'), 'Z');
}

TEST(EncoderString3, Test1) { EXPECT_EQ(EncoderString3("AWESOME"), "GWCPEEC"); }

TEST(EncoderString3, Test2) {
  EXPECT_EQ(EncoderString3("THIS IS EXTRA CREDIT!"), "MSOP LI CAMJG DJCIOO!");
}

TEST(DecoderString3, Test1) { EXPECT_EQ(DecoderString3("GWCPEEC"), "AWESOME"); }

TEST(DecoderString3, Test2) {
  EXPECT_EQ(DecoderString3("MSOP LI CAMJG DJCIOO!"), "THIS IS EXTRA CREDIT!");
}
} // namespace
