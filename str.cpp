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
str & str::operator=(const str &s){
    _n = s._n;
    
    delete [] _buf;
	_buf = new char[strlen(s._buf)+1];
	strcpy(_buf,s._buf);
    return *this;
}

str & str::operator+(const str &s){
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

    return *this;
}

ostream & operator<<(ostream & os, const str &s){
    for (int i = 0; i < s._n; i++){
        os << s._buf[i];
    }
    return os;
}

istream & operator>>(istream & is, str &s){
    char temp_buf[100];
    is >> temp_buf;
    cout << endl;

    s = str(temp_buf);
    return is;
}

int main(){
    str s1("Hello");
    str s2;
    cout << "Type your name: ";
    cin >> s2;
    str s3 = s1 + s2;
    cout << "S1: " << s1 << endl;
    cout << "S2: " << s2 << endl;
    cout << "S3: " << s3 << endl;
}