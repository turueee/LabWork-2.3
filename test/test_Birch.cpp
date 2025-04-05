#include "TString.h"
#include "TConsole.h"

#include <gtest.h>


///Тесты для класса TAllInstruments
TEST(TString, can_create_String_with_positive_len)
{
  ASSERT_NO_THROW(TString s("abdsfd",3));
}


TEST(TString, throw_create_string_with_negative_len)
{
  ASSERT_ANY_THROW(TString s("dddfjf",-5));
}


TEST(TString, throw_copy_string_by_nullptr)
{
  char* d = nullptr;
  ASSERT_ANY_THROW(TString s(d));
}


TEST(TString, can_copy)
{
  TString s("dfg",3);
  TString sc(s);
  EXPECT_NEAR(1, s==sc, 0.000001);
}


TEST(TString, can_get_string)
{
  TString z("abdsfd", 3);
  char* stl;
  ASSERT_NO_THROW(z.GetStr(&stl));
}


TEST(TString, can_get_len)
{
  TString s("dfg", 3);
  EXPECT_NEAR(3, s.GetLen(), 0.000001);
}


TEST(TString, can_set_str)
{
  TString s("dfg", 3);
  TString z;
  z.SetStr("dfg");
  EXPECT_NEAR(1, s==z, 0.000001);
}


TEST(TString, throw_set_str)
{
  TString s("dfg", 3);
  ASSERT_ANY_THROW(s.SetStr(nullptr));
}


TEST(TString, can_set_len)
{
  TString s("dfg", 3);
  s.SetLen(2);
  EXPECT_NEAR(2, s.GetLen(), 0.000001);
}


TEST(TString, throw_set_len)
{
  TString s("dfg", 3);
  ASSERT_ANY_THROW(s.SetLen(-5));
}


TEST(TString, can_add)
{
  TString s("dfg", 3),u("uio",3),add("dfguio",6);
  EXPECT_NEAR(1,s+u==add, 0.000001);
}


TEST(TString, can_mul)
{
  TString s("dfg"), mul ("dfgdfgdfg");
  EXPECT_NEAR(1, s * 3 == mul, 0.000001);
}


TEST(TString, throw_mul)
{
  TString s("dfg");
  ASSERT_ANY_THROW(s*-3);
}


TEST(TString, can_equality)
{
  TString s("dfg"), mul;
  mul = s;
  EXPECT_NEAR(1, s == mul, 0.000001);
}


TEST(TString, can_equal)
{
  TString s("dfg"), mul("dfg");
  EXPECT_NEAR(1, s == mul, 0.000001);
}


TEST(TString, can_non_equal)
{
  TString s("dfg"), mul("fg");
  EXPECT_NEAR(1, s != mul, 0.000001);
}


TEST(TString, can_more)
{
  TString s("dfg"), mul("fg");
  EXPECT_NEAR(1, s > mul, 0.000001);
}


TEST(TString, can_few)
{
  TString s("df"), mul("dfg");
  EXPECT_NEAR(1, s < mul, 0.000001);
}


TEST(TString, can_index)
{
  TString s("df");
  EXPECT_NEAR(1, s[1]=="f", 0.000001);
}


TEST(TString, throw_index)
{
  TString s("df");
  ASSERT_ANY_THROW(s[4]);
}


TEST(TString, can_search_word)
{
  TString s("dfabaddkdaba");
  EXPECT_NEAR(2, s.WordSearch("aba"), 0.000001);
}


TEST(TString, can_search_letter)
{
  TString s("dfabaddkdaba");
  EXPECT_NEAR(2, s.LetterSearch('a'), 0.000001);
}


TEST(TString, can_split)
{
  TString s("dfabaddkdaba"),c("df"),ab("aba");
  char** sp;
  int l;
  s.Split(ab, &sp, &l);
  TString res(sp[0]);
  EXPECT_NEAR(1, res==c, 0.000001);
}


TEST(TString, can_search_all_word)
{
  TString s("dfabaddkdaba");
  int* ind;
  s.AllIndexWordSearch("aba", &ind);
  EXPECT_NEAR(9, ind[1], 0.000001);
}


TEST(TString, can_search_more_popular_letter)
{
  TString s("aaadfabaddkdaba");
  EXPECT_NEAR(1,'a' == s.MostPopularLetter(), 0.000001);
}


TEST(TString, can_set_unic)
{
  TString s("abcab");
  char* unic;
  s.SetOfLetters(&unic);
  TString d(unic), res("abc");
  EXPECT_NEAR(1, d==res, 0.000001);
}


TEST(TString, can_set_counts)
{
  TString s("abcab");
  int* unic;
  s.CountsOfLetters(&unic);
  EXPECT_NEAR(2, unic[0], 0.000001);
}


TEST(TConsole, can_create_console_with_correct_parametrs)
{
  ASSERT_NO_THROW(TConsole c(2,3,2));
}


TEST(TConsole, throw_create_string_with_negative_x)
{
  ASSERT_ANY_THROW(TConsole c(-2, 3, 2));
}


TEST(TConsole, throw_create_string_with_negative_y)
{
  ASSERT_ANY_THROW(TConsole c(2, -3, 2));
}


TEST(TConsole, throw_create_string_with_negative_len)
{
  ASSERT_ANY_THROW(TConsole c(2, 3, -2));
}


TEST(TConsole, can_get_x)
{
  TConsole c(2, 3, 2);
  EXPECT_NEAR(2, c.GetX(), 0.000001);
}


TEST(TConsole, can_get_y)
{
  TConsole c(2, 3, 2);
  EXPECT_NEAR(3, c.GetY(), 0.000001);
}


TEST(TConsole, can_get_len)
{
  TConsole c(2, 3, 2);
  EXPECT_NEAR(2, c.GetLen(), 0.000001);
}


TEST(TConsole, can_set_x)
{
  TConsole c(2, 3, 2);
  c.SetX(10);
  EXPECT_NEAR(10, c.GetX(), 0.000001);
}


TEST(TConsole, can_set_y)
{
  TConsole c(2, 3, 2);
  c.SetY(10);
  EXPECT_NEAR(10, c.GetY(), 0.000001);
}


TEST(TConsole, can_set_len)
{
  TConsole c(2, 3, 2);
  c.SetLen(10);
  EXPECT_NEAR(10, c.GetLen(), 0.000001);
}

/*
TEST(TComplex, can_get_real_part_of_number)
{
  TComplex<double> z(8,5);
  EXPECT_NEAR(8, z.GetRe(), 0.000001);
}


TEST(TComplex, can_get_imaginary_part_of_number)
{
  TComplex<double> z(8, 5);
  EXPECT_NEAR(5, z.GetIm(), 0.000001);
}


TEST(TComplex, can_copy)
{
  TComplex<double> z(2,3);
  TComplex<double> p(z);
  EXPECT_NEAR(1, p==z, 0.000001);
}


TEST(TComplex, can_set_real_part_of_number)
{
  TComplex<double> z;

  z.SetRe(3);
  EXPECT_NE(0, z.GetRe());
}


TEST(TComplex, can_set_imaginary_part_of_number)
{
  TComplex<double> z;

  z.SetIm(3);
  EXPECT_NE(0, z.GetIm());
}


TEST(TComplex, can_add_numbers)
{
  TComplex<double> z(2, 3),p(3,5),r(5,8);
  EXPECT_NEAR(1, (z+p)==r, 0.000001);
}


TEST(TComplex, can_subtract_numbers)
{
  TComplex<double> z(2, 3), p(3, 5), r(-1, -2);
  EXPECT_NEAR(1, (z - p) == r, 0.000001);
}


TEST(TComplex, can_multiply_numbers)
{
  TComplex<double> z(2, 3), p(3, 5), r(-9, 19);
  EXPECT_NEAR(1, (z * p) == r, 0.000001);
}


TEST(TComplex, can_divide_numbers)
{
  TComplex<double> z(4, 0), p(2,0), r(2,0);
  EXPECT_NEAR(1, (z / p) == r, 0.000001);
}


TEST(TComplex, throws_divide_number_by_zero)
{
  TComplex<double> z(2,3), r(0, 0);
  ASSERT_ANY_THROW(z/r);
}


TEST(TComplex, can_equal_add_numbers)
{
  TComplex<double> z(2, 3), p(3, 5), r(5, 8);
  z += p;
  EXPECT_NEAR(1, z == r, 0.000001);
}


TEST(TComplex, can_equal_subtract_numbers)
{
  TComplex<double> z(2, 3), p(3, 5), r(-1, -2);
  z -= p;
  EXPECT_NEAR(1, z == r, 0.000001);
}


TEST(TComplex, can_equal_multiply_numbers)
{
  TComplex<double> z(2, 3), p(3, 5), r(-9, 19);
  z *= p;
  EXPECT_NEAR(1, z == r, 0.000001);
}


TEST(TComplex, can_equal_divide_numbers)
{
  TComplex<double> z(4, 0), p(2, 0), r(2, 0);
  z /= p;
  EXPECT_NEAR(1, z == r, 0.000001);
}


TEST(TComplex, throws_equal_divide_number_by_zero)
{
  TComplex<double> z(2, 3), r(0, 0);
  ASSERT_ANY_THROW(z /= r);
}


TEST(TComplex, can_assign_numbers)
{
  TComplex<double> z(4, 0), p(2, 0);
  z = p;
  EXPECT_NEAR(1, z == p, 0.000001);
}


TEST(TComplex, can_equal_numbers)
{
  TComplex<double> z(6, 4), p(6, 4);
  EXPECT_NEAR(1, z == p, 0.000001);
}


TEST(TComplex, can_not_equal_numbers)
{
  TComplex<double> z(6, 4), p(4, 4);
  EXPECT_NEAR(1, z != p, 0.000001);
}


TEST(TComplex, can_abs_number)
{
  TComplex<double> z(3, 4);
  EXPECT_NEAR(5, z.Abs(), 0.000001);
}


TEST(TComplex, can_pow_numbers)
{
  TComplex<double> z(6, 4),p(20,48),r(0,0);
  r = z.Pow(2);
  r -= p;
  EXPECT_NEAR(0, r.Abs(), 0.000001);
}


TEST(TComplex, can_impow_numbers)
{
  TComplex<double> z(6, 4), p(2,0), r,y(20,48);
  r = z.ImPow(p);
  r -= r;
  EXPECT_NEAR(0, r.Abs(), 0.000001);
}


TEST(TComplex, throws_pow_uncertainty_0_0)
{
  TComplex<double> z(0, 0);
  ASSERT_ANY_THROW(z.Pow(0));
}


TEST(TComplex, throws_impow_uncertainty_0_0)
{
  TComplex<double> z(0, 0),r(0,0);
  ASSERT_ANY_THROW(z.ImPow(r));
}


TEST(TComplex, throws_impow_uncertainty_1_devide_0)
{
  TComplex<double> z(0, 0), r(-2, 0);
  ASSERT_ANY_THROW(z.ImPow(r));
}


TEST(TComplex, throws_impow_uncertainty_1_devide_im0)
{
  TComplex<double> z(0, 0), r(0, -2);
  ASSERT_ANY_THROW(z.ImPow(r));
}
*/