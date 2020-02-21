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
    str & operator=(const str &);
    str & operator+(const str &s1);

  friend ostream & operator<<(ostream &, const str &);
  friend istream & operator<<(istream &, str &);
  friend void swap(str &, str &);
};

#endif