#pragma once
#include <iostream>
using namespace std;
class TString
{
protected:
  char* str;
  int len;
public:
  TString();
  TString(const TString& p);
  TString(TString&& p) noexcept;
  TString(char* str_, int len_);
  TString(const char* str_);
  ~TString();

  char* GetStr();
  int GetLen();

  void SetStr(char* str_);
  void SetLen(int i);

  TString operator+(const TString& line);
  TString operator*(int repeat);
  char** operator/(char letter);
  TString operator=(const TString& line);

  bool operator==(const TString& line);
  bool operator!=(const TString& line);
  bool operator<(const TString& line);
  bool operator>(const TString& line);

  char operator[](int index);

  int WordSearch(char* word);
  int AllWordSearch(char* word);
  int LetterSearch(char letter);
  int CountOfIncludes(char letter);
  int* LenWordsOfIncludes(char letter);
  int Insert(int position, char* word);
  int Insert(int position, const TString& elem);
  

  friend ostream& operator<<(ostream& o, TString& line);
  friend istream& operator>>(istream& i, TString& line);
};


int strlen(char* str);
int cstrlen(const char* str);
void printsplit(char** split, TString& b,char letter);