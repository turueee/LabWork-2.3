#pragma once
#include <iostream>
#include "TString.h"
using namespace std;

class TConsole
{
protected:
  int x;
  int y;
  int len;
public:
  TConsole();
  TConsole(int x_, int y_, int len_);
  TConsole(const TConsole& pos);
  ~TConsole();

  void SetX(int x_);
  void SetY(int y_);
  void SetLen(int len_);

  int GetX();
  int GetY();
  int GetLen();

  TString Init();
  friend ostream& operator<<(ostream& o, TConsole& line);
  friend istream& operator>>(istream& i, TConsole& line);
};