#ifndef Symbol_H
#define Symbol_H
#include <string>
#include "char_Symbol_Base.h"
class Symbol : char_Symbol_Base {
public:
  Symbol();
  Symbol(char c);
  Symbol(Symbol &s);
  ~Symbol();

  char getSymbol();

private:
  //bool isEscapeSequence(std::string str);
};

#endif