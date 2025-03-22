#include "Text.h"

int main()
{
  char d[256] = "oregardardr";
  char c = 'r';
  int* wordslen;
  TString b(d), r;
  int* mass = b.LenWordsOfIncludes(c);
  for (int i = 0; i < b.CountOfIncludes(c); ++i)
  {
    cout << mass[i] << endl;
  }
}