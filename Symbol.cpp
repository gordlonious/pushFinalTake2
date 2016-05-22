#ifndef Symbol_S
#define Symbol_S
#include "Symbol.h"

Symbol::Symbol() {

}

//Symbol::Symbol(std::string str) { }

// how necessary
Symbol::Symbol(char c) : char_Symbol_Base(c) { }

Symbol::~Symbol() {
  // no pointer members
}

// copy constructor
Symbol::Symbol(Symbol &s) { }

char Symbol::getSymbol() {
  return getMe();
}
#endif