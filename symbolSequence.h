#ifndef symbolSequence_HS
#define symbolSequence_HS
#include <string>
#include "Symbol.h"

const int ROUGH_symbolSequence_INT = 10;

enum seqType { escape = 0, unicode, regular };

template<int ROUGH_symbolSequence_INT>
class symbolSequence : Symbol {
public:
  //symbolSequence(int &paramLimit);
  symbolSequence(char* seq, char endingToken);
  ~symbolSequence();

  void getPlSequence(char* str);
  std::string getSecureSeq();
  seqType getSeqType();
private:
  bool validSequence;
  seqType seqObjType;
  bool isSingle(char *c);
  std::string secureSeq;
};

// invalid if not sequence
symbolSequence<ROUGH_symbolSequence_INT>::symbolSequence(char* str, char endingToken) {
  bool single = isSingle(str);
  if (single) {
    validSequence = false;
  }
  else {
    validSequence = true;
  }
  // if valid parse sequence!
  // WARNING -- rough approximation of sequence classifications ( loose definition )
  if (validSequence) {
    int travStr = 0;
    char tokRef = str[travStr];
    seqObjType = regular;
    while (tokRef != endingToken) { // could cause traversal of unallocated memory
      if (tokRef == '\\') {
        seqObjType = escape;
      }
      if (tokRef > 127) {
        seqObjType = unicode;
      }
      travStr++;
      tokRef = str[travStr];
      if (travStr >= ROUGH_symbolSequence_INT) {
        //std::cout << "symbolSequence limit has been breached" << std::endl;
        break;
      }
    }
  }

  // Did i create single

}

symbolSequence<ROUGH_symbolSequence_INT>::~symbolSequence() { }

template<>
bool symbolSequence<ROUGH_symbolSequence_INT>::isSingle(char *c) {
  char *nextC = &*(c + 1);
  if (nextC != NULL) {
    return false;
  }
  else {
    return true;
  }
}

seqType symbolSequence<ROUGH_symbolSequence_INT>::getSeqType() {
  return seqObjType;
}

std::string symbolSequence<ROUGH_symbolSequence_INT>::getSecureSeq() {
  return secureSeq;
}

#endif