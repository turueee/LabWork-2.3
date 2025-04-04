#include "TString.h"
#include "TConsole.h"

int main()
{
  int count;
  char d[256] = "nsabamsabamk";
  char c[256] = "aba";
  char** sp;
  char* set;
  int* wordslen;
  TString b, r;

  b.SetStr(d);
  r.SetStr(c);

  b.Split(c, &sp,&count);
  b.SetOfLetters(&set);
  b.CountsOfLetters(&wordslen);
  cout << (b == r) << endl;
  for (int i = 0; i < strlen(set); ++i)
    cout << set[i] << " = " << wordslen[i] << endl;
  cout << set << endl;
  for (int i = 0; i < count; ++i)
    cout << sp[i] << endl;

  cout << b.MostPopularLetter()<<endl;
}