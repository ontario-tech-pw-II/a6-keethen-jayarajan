## Operator Overloading for <code>str</code> class

Learning outcomes highlights: 
- Opverloading operator for a *class with resource* (<code>str</code>)
  - = (assignment)
  - \+ (concatination)
  - &gt;&gt; and &lt;&lt; (input/output)

**Problem:** Implement the following operators for <code>str class</code>. Note that <code>str</code> class (solution to Lab 6) has been written for you and you need only focus on adding the following operator functions.   
- = (assignment operator): performs the assignment. An example of usage is  <code>s1 = s2; // s1 and s2 are str </code>
- \+ (concatenation operator): returns the concatenation of two operands.  An example of usage is <code>s1 + s2; </code>
  - Hint: the operator should create a string which has enouth space to hold the concatination of two straing (it does not change any of its operands) 
-  &lt;&lt; and &gt;&gt; (insertion and extraction operators): do the input and output. An example of usage is  <code>cout &lt;&lt; s1;</code>
- Write a main.cpp to test the operators that you have overloaded.

### str.h
```C++
// str.h

#ifndef __str_h__
#define __str_h__

#include <iostream>

using namespace std;


class str
{
  private:
    char* _buf;  // pointer to the underlying storage
    int _n;      // size of the buffer

  public:
  
    // constructors of various forms
    str();      
    str(char ch);
    str(const char* c_str);

    str(const str &);   // copy constructor 
    ~str();

    // function for finding length of the string
    int length() const { return _n; }

    // function for checking if string is null string
    bool is_empty() const { return _n == 0; }

    void print();
  
    // clear erases the contents of the string, which becomes an empty string (with a length of 0 characters).
    void clear();

    // append extends the string by appending additional characters at the end of its current value:
    void append(const str& str);

  friend void swap(str &, str &);
};

#endif

```
### str.cpp
```C++
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
```
