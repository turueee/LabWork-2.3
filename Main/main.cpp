#include "Text.h"

int main()
{
  char d[256] = "This is tree";
  char c = ' ';
  char** sp;
  int* wordslen;
  TString b(d), r;
  sp = b / c;
  printsplit(sp, b, c);
  int* mass = b.LenWordsOfIncludes(c);
}