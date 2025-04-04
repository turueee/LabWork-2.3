#pragma once
#include <iostream>
using namespace std;

class TConsole
{
protected:
  int x;
  int y;
  int len;
public:
  TConsole();
  TConsole(int x, int y, int len);
  TConsole(const TConsole& pos);
  ~TConsole();
};