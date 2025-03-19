#include "Text.h"

int main()
{
  char d[256] = "ooregardard";
  char c[256] = "ard";
  TString a(c),b("\0", 2), r;
  cout << b.WordSearch(c);
}