#include "symbolSequence.h"
#include <iostream>
#include <bitset>
int main() {
  Symbol sym0 = Symbol();
  char c1 = 'c';
  Symbol sym1 = Symbol(c1);
  std::cout << c1 << std::endl;

  symbolSequence<ROUGH_symbolSequence_INT> sq1 = symbolSequence<ROUGH_symbolSequence_INT>("seq", 'h'); // end tok
  seqType sq1Type = sq1.getSeqType();
  std::cout << "testing for regular symbol sequence..  ";
  std::cout << "should be 2" << sq1Type << std::endl;
  // test for secure string

  // output binary // std 10
  symbolSequence<ROUGH_symbolSequence_INT> sq2 = symbolSequence<ROUGH_symbolSequence_INT>("sequence\\", '\\'); // sqType tri
  //std::bitset<10> bset1 = std::bitset<10>(sq2.getPlSequence());

  char stop;
  std::cout << "please enter 'a' key..." << std::endl;
  std::cin >> stop;
  return 0;
}