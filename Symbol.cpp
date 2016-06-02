#ifndef Symbol_S
#define Symbol_S
#include "Symbol.h"
// symbol must be single or escape
Symbol::Symbol() {
  onlySymType = seqType::noType;
}

Symbol::Symbol(char c) : char_Symbol_Base(c) { }

Symbol::~Symbol() {
  // no pointer members
}

// copy constructor
Symbol::Symbol(Symbol &s) { }

char Symbol::getSymbol() {
  return getMe();
}

bool Symbol::isEscapeSequence(char seq) {
  // read from file?
  if (seq == '\\') {
    return true;
  }
  else  if (seq == ' ') {
    return true;
  }
  else if (seq == ' ') {
    return true;
  }
  else {
    return false;
  }
}

seqType Symbol::get_symbol_type() {
  return onlySymType;
}
#endif