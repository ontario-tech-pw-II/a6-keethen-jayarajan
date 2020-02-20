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

    // TODO 1. Implement copy constructor 
    str(const str &);

    // lets not forget the destructor
    ~str();

    // function for finding length of the string
    int length() const { return _n; }

    // function for checking if string is null string
    bool is_empty() const { return _n == 0; }

    void print();

    // TODO 2. Implement the following member functions:
  
    // clear erases the contents of the string, which becomes an empty string (with a length of 0 characters).
    void clear();

    // append extends the string by appending additional characters at the end of its current value:
    void append(const str& str);


  // TODO 3. Implement the following swap functions that exchanges the values of two strings
  friend void swap(str &, str &);
};

#endif