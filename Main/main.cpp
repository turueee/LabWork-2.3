#include "TString.h"
#include "TConsole.h"

int main()
{
  TConsole app;
  int count;
  char d[256] = "wd";
  char c[256] = "aba";
  char** sp;
  char* set;
  int* wordslen;
  TString b(d),t(c),re,ap;

  cin >> app;
  system("cls");
  ap = app.Init();
  cout << ap << endl;
}