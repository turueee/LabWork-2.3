#pragma once
#include <iostream>
using namespace std;
class TString
{
protected:
  char* str;
  int len;
public:
  TString();
  TString(const TString& p);
  TString(TString&& p);
  TString(char* str_, int len_);
  TString(const char* str_);
  ~TString();

  char* GetStr();
  int GetLen();

  void SetStr(char* str_);
  void SetLen(int i);

  TString operator+(const TString& line);
  TString operator*(int rep);
  TString operator=(const TString& line);

  bool operator==(const TString& line);
  bool operator!=(const TString& line);
  bool operator<(const TString& line);
  bool operator>(const TString& line);

  char operator[](int p);


  friend ostream& operator<<(ostream& o, TString& line);
  friend istream& operator>>(istream& i, TString& line);
};