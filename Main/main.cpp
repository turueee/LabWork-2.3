#include "Text.h"

int main()
{
  char d[256] = "ooregardard";
  char c = 'o';
  TString b(d), r;
  cout << b.LetterSearch(c);
}