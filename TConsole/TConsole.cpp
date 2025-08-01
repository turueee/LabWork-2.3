#include <conio.h>
#include "TConsole.h"
#include "TString.h"

TConsole::TConsole()
{
  x = 0;
  y = 0;
  len = 1;
}


TConsole::TConsole(int x_, int y_, int len_)
{
  if (x_ < 0 || y_ < 0 || len_ <= 0)
    throw "<0";
  x = x_;
  y = y_;
  len = len_;
}


TConsole::TConsole(const TConsole& pos)
{
  x = pos.x;
  y = pos.y;
  len = pos.len;
}


TConsole::~TConsole()
{
}

void TConsole::SetX(int x_)
{
  if (x_ < 0)
    throw "x_<0";
  x = x_;
}

void TConsole::SetY(int y_)
{
  if (y_ < 0)
    throw "y_<0";
  y = y_;
}

void TConsole::SetLen(int len_)
{
  if (len_ <= 0)
    throw "len_<=0";
  len = len_;
}

int TConsole::GetX()
{
  return x;
}

int TConsole::GetY()
{
  return y;
}

int TConsole::GetLen()
{
  return len;
}

TString TConsole::Init()
{
  for (int i = 0; i < y; ++i)
    cout << "\n";
  for (int i = 0; i < x; ++i)
    cout << " ";

  char * str = new char[256];
  int i = 0;
  while (str[i - 1] != '\r')
  {
    if (i > len)
    {
      system("cls");
      for (int i = 0; i < y; ++i)
        cout << "\n";
      for (int i = 0; i < x; ++i)
        cout << " ";
      i = 0;
    }
    str[i] = _getch();
    cout << str[i];
    ++i;
  }
  str[i - 1] = '\0';
  len = strlen(str);
  system("cls");
  return TString(str);
}


ostream& operator<<(ostream& o, TConsole& line)
{
  o << "X: " << line.x << endl << "Y: " << line.y << endl << "Len: " << line.len << endl;
  return o;
}

istream& operator>>(istream& i, TConsole& line)
{
  int x_, y_, len_;
  cout << "Enter the X coordinate: " << endl;
  i >> x_;
  cout << "Enter the Y coordinate: " << endl;
  i >> y_;
  cout << "Enter the len:" << endl;
  i >> len_;
  line.SetX(x_);
  line.SetY(y_);
  line.SetLen(len_);
  return i;
}
