// str.cpp

#include "str.h"
#include <cstring>

str::str() 
{
  _buf = nullptr;
  _n = 0;
}

str::str(char ch)
{
   _n = 1;
  _buf = new char[_n];
  _buf[0] = ch;
}

str::str(const char* c_str)
{
  _n = strlen(c_str);
  _buf = new char[_n];
  for (int i = 0; i < _n; ++i) 
    _buf[i] = c_str[i];
}
str::str(const str &s)
{
  _n = s._n;
  _buf = new char[_n];
  for (int i = 0; i < _n; ++i) 
    _buf[i] = s._buf[i];
}

str::~str()
{
  if (_buf) 
    delete [] _buf;
  _n = 0;
  _buf = nullptr;
}

void str::print()
{
  for (int i = 0; i < _n; ++i) 
    cout << _buf[i];
  cout << endl;
}

void str::clear()
{
  if (_buf) 
    delete [] _buf;

  _buf = nullptr;
  _n = 0;
}

void str::append(const str & s)
{
  char *p = new char[_n + s._n];

  int i;
  
  for (i = 0; i < _n; ++i) 
    p[i] = _buf[i];
  
  for (int j = 0; j < s._n; ++i,++j) 
    p[i] = s._buf[j];

  if (_buf) 
    delete [] _buf;

  _buf = p;  
  _n = _n + s._n;
}

void swap(str& x, str& y)
{
  char *tmp;
  int ntmp;
  
  tmp = x._buf;
  x._buf = y._buf;
  y._buf = tmp;

  ntmp = x._n;
  x._n = y._n;
  y._n = ntmp;
  
}


