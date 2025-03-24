#include "Text.h"

int main()
{
  char d[256] = "aba aba aba";
  char c[256] = "aba";
  char** sp;
  int* wordslen;
  TString b(d), r(c);
  /*
  sp = b / c;
  printsplit(sp, b, c);
  int* mass = b.LenWordsOfIncludes(c);
  */
  cout << b.AllIndexWordSearch(c)[0] << endl;
}