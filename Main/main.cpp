#include "Text.h"

int main()
{
  char d[256] = "ooregardard";
  char c[256] = "ard";
  TString a(c),b(d), r;
  cout << b.WordSearch(c);
}