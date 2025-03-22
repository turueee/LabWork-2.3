#include "Text.h"

TString::TString()
{
  str = new char[1] {0};
  len = 1;
}


TString::TString(const TString& p)
{
  len = p.len;
  if (p.str != nullptr)
  {
    str = new char[len+1];
    for (int i = 0; i < len; ++i)
    {
      str[i] = p.str[i];
    }
    str[len] = '\0';
  }
  else
    throw "p.str == nullptr";
}


TString::TString(TString&& p) noexcept
{
  len = p.len;
  str = p.str;

  p.str = nullptr;
  len = 0;
}


TString::TString(char* str_, int len_)
{
  if (len <= 0)
    throw "len <= 0";
  if (strlen(str_) != len)
    throw "strlen(str_) != len_";
  len = len_;
  str = new char[len+1];
  for (int i = 0; i < len; ++i)
    str[i] = str_[i];
  str[len] = '\0';
}


TString::TString(const char* str_)
{
  if (str_ == nullptr)
    throw "str_ == nullptr";
  len = cstrlen(str_);
  str = new char[len+1];
  for (int i = 0; i < len; ++i)
    str[i] = str_[i];
  str[len] = '\0';
}


TString::~TString()
{
  if (str != nullptr)
    delete[]str;
  str = nullptr;
}


char* TString::GetStr()
{
  if (str != nullptr)
    return str;
  else
    return nullptr;
}


int TString::GetLen()
{
  return len;
}


void TString::SetStr(char* str_)
{
    delete[] str;
    len = strlen(str_);
    str = new char[len + 1];
    for (int i = 0; i < len; ++i)
      str[i] = str_[i];
    str[len] = '\0';
}


void TString::SetLen(int len_)
{
  if (len_ <= 0)
    throw "ken_ <= 0";
  if (len == len_)
    return;
  len = len_;
  char* str_ = this->GetStr();
  str = new char[len + 1];
  for (int i = 0; i < len; ++i)
    str[i] = str_[i];
}


TString TString::operator+(const TString& line)
{
  char* nstr = new char[len + line.len +1];
  for (int i = 0; i < len; ++i)
    nstr[i] = str[i];
  for (int i = 0; i < line.len; ++i)
    nstr[i + len] = line.str[i];
  nstr[len + line.len] = '\0';
  return TString(nstr);
}


TString TString::operator*(int repeat)
{
  if (repeat <= 0)
    throw "rep <= 0";
  char* buf = new char[len * repeat + 1];
  for (int i = 0; i < repeat; ++i)
  {
    for (int j = 0; j < len; ++j)
      buf[len * i + j] = str[j];
  }
  buf[len * repeat] = '\0';
  return TString(buf);
}


char** TString::operator/(char letter)
{
  int* wordslen = this->LenWordsOfIncludes(letter);
  char** split = new char* [this->CountOfIncludes(letter) + 1];
  int i = 0, t = 0, start = 0;
  for (i = 1; i < len; ++i)
  {
    if (str[i] == letter)
    {
      if (str[i - 1] != letter)
      {
        split[t] = new char[wordslen[t] + 1];
        for (int j = 0; j < wordslen[t]; ++j)
        {
          split[t][j] = str[start + j];
        }
        split[t][wordslen[t]] = '\0';
        start = i + 1;
        t++;
      }
      else
        start = i + 1;
    }
  }
  if (str[len - 1] != letter)
  {
    split[t] = new char[wordslen[t] + 1];
    for (int j = 0; j < len; j++)
    {
      split[t][j] = str[start + j];
    }
    split[t][wordslen[t]] = '\0';
  }
  return split;
}


TString TString::operator=(const TString& line)
{
  len = line.len;
  str = new char[len + 1];
  for (int i = 0; i < len; ++i)
    str[i] = line.str[i];
  str[len] = '\0';
  return *this;
}


bool TString::operator==(const TString& line)
{
  if (len != line.len)
    return false;
  bool f = true;
  for (int i = 0; i < len; ++i)
  {
    if (str[i] != line.str[i])
      f = false;
  }
  return f;
}


bool TString::operator!=(const TString& line)
{
  if (len != line.len)
    return true;
  bool f = false;
  for (int i = 0; i < len; ++i)
  {
    if (str[i] != line.str[i])
      f = true;
  }
  return f;
}


bool TString::operator<(const TString& line)
{
  return len < line.len;
}


bool TString::operator>(const TString& line)
{
  return len > line.len;
}


char TString::operator[](int index)
{
  if (index >= len)
    throw "size";
  return str[index];
}


int TString::WordSearch(char* word)
{
  int l = strlen(word);
  if (l > len)
    throw "l > len";
  for (int i = 0; i < len-l+1; ++i)
  {
    if (str[i] = word[0])
    {
      bool log = true;
      for (int j = 1; j < l; ++j)
      {
        if (str[i + j] != word[j])
        {
          log = false;
        }
      }
      if (log == true)
        return i;
    }
  }
  cout << "Not founded\n";
  return -1;
}


int TString::LetterSearch(char letter)
{
  for (int i = 0; i < len; ++i)
  {
    if (str[i] == letter)
      return i;
  }
  return -1;
}


int TString::CountOfIncludes(char letter)
{
  int count = 0;
  for (int i = 1; i < len; ++i)
  {
    if (str[i] == letter)
    {
      if (str[i - 1] != letter)
        ++count;
    }
  }
  if (str[len - 1] != letter)
    ++count;
  return count;
}


int* TString::LenWordsOfIncludes(char letter)
{
  int *wordslen = new int [this->CountOfIncludes(letter)+1];
  int i = 0, t = 0, start = 0;
  for (i = 1; i < len; ++i)
  {
    if (str[i] == letter)
    {
      if (str[i - 1] != letter)
      {
        wordslen[t] = i - start;
        start = i + 1;
        ++t;
      }
      else
      {
        start = i + 1;
      }
    }
  }
  if (str[len - 1] != letter)
  {
    wordslen[t] = i - start;
  }
  return wordslen;
}


ostream& operator<<(ostream& o, TString& line)
{
  o << "Length of string: " << line.len << "\n" << "String: " << line.str << "\n";
  return o;
}


istream& operator>>(istream& i, TString& line)
{
  char buf[256];
  cout << "Enter a string: ";
  i >> buf;
  line.SetStr(buf);
  return i;
}


int strlen(char* str)
{
  int counter = 0;
  if (str == nullptr)
    throw "str == nullptr";
  while (str[counter] != '\0')
    counter++;
  return counter;
}


int cstrlen(const char* str)
{
  int counter = 0;
  if (str == nullptr)
    throw "str == nullptr";
  while (str[counter] != '\0')
    counter++;
  return counter;
}


void printsplit(char** split, TString& b,char letter)
{
  for (int i = 0; i < b.CountOfIncludes(letter); ++i)
  {
    for (int j = 0; j < b.LenWordsOfIncludes(letter)[i]; j++)
      cout << split[i][j];
    cout << endl;
  }
}