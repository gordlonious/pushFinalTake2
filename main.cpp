#include "symbolProcessor.h"
#include "topSearch.h"
int main() {
  //UI and symbol processing / searching
  std::string symBuf;
    std::cout << "Please enter a Symbol or character sequence " << std::endl;
    std::cin >> symBuf;
    symbolProcessor symProc = symbolProcessor(symBuf);
    std::cout << std::endl << "There are 2 databases at the moment: " << std::endl;
    std::cout << "   1: regResource1 (ascii/escape)" << std::endl << "   2: oddResource1 (odd/cyrillic)" << std::endl;
    int data1 = 0;
    std::cout << "Please enter 1 or 2 " << std::endl;
    std::cin >> data1;

    // search for symbol
    if (data1 == 1) {
      std::filebuf fb;
      fileReader reader = fileReader(fb, "regResource1.txt");
      topSearch searchUtil = topSearch(reader);
      searchUtil.displayFileName();
      searchUtil.intakeWholeFile();

      std::fstream data1Output;
      if (symProc.usingSequence()) {
        std::string symProcStr1;
        symProc.getSymbolSequence(symProcStr1);
        bool trySearch = searchUtil.basic_linearSearch(symProcStr1);
        if (symProc.getTypeOfSequence() == seqType::regular) {
          data1Output.open("regularOutput1", std::ios::out);
          std::string data1Symbol;
          symProc.getSymbolSequence(data1Symbol);
          data1Output << data1Symbol << std::endl;
        }
        else if (symProc.getTypeOfSequence() == seqType::unicode) {
          data1Output.open("unicodeOutput1", std::ios::out);
          std::string data1UnicodeSymbol;
          symProc.getSymbolSequence(data1UnicodeSymbol);
          data1Output << data1UnicodeSymbol << std::endl;
        }
        else if (symProc.getTypeOfSequence() == seqType::escape) {
          data1Output.open("escapeOutput1", std::ios::out);
          std::string data1EscapeSymbol;
          symProc.getSymbolSequence(data1EscapeSymbol);
          data1Output << data1EscapeSymbol << std::endl;
        }
      }
      else {
        if (symProc.getTypeOfSymbol() == seqType::regular) {
          data1Output.open("regularOutput1", std::ios::out);
          char regC;
          symProc.getSymbolChar(regC);
          data1Output << regC << std::endl;
        }
        else if (symProc.getTypeOfSymbol() == seqType::unicode) {
          data1Output.open("unicodeOutput1", std::ios::out);
          char  uniC;
          symProc.getSymbolChar(uniC);
          data1Output << uniC << std::endl;
        }
        else if (symProc.getTypeOfSymbol() == seqType::escape) {
          data1Output.open("escapeOutput1", std::ios::out);
          char escC;
          symProc.getSymbolChar(escC);
          data1Output << escC << std::endl;
        }
      }
    }
    else if (data1 == 2) {
      std::filebuf fb2;
      fileReader reader2 = fileReader(fb2, "oddResource1.txt");
      topSearch searchUtil2 = topSearch(reader2);
      searchUtil2.intakeWholeFile();
      std::fstream data2Output;
      if (symProc.usingSequence()) {
        std::string symProcStr2;
        symProc.getSymbolSequence(symProcStr2);
        bool trySearch = searchUtil2.basic_linearSearch(symProcStr2);
        if (symProc.getTypeOfSequence() == seqType::regular) {
          data2Output.open("regularOutput2", std::ios::out);
          std::string data2Symbol;
          symProc.getSymbolSequence(data2Symbol);
          data2Output << data2Symbol << std::endl;
        }
        else if (symProc.getTypeOfSequence() == seqType::unicode) {
          data2Output.open("unicodeOutput2", std::ios::out);
          std::string data2UnicodeSymbol;
          symProc.getSymbolSequence(data2UnicodeSymbol);
          data2Output << data2UnicodeSymbol << std::endl;
        }
        else if (symProc.getTypeOfSequence() == seqType::escape) {
          data2Output.open("escapeOutput2", std::ios::out);
          std::string data2EscapeSymbol;
          symProc.getSymbolSequence(data2EscapeSymbol);
          data2Output << data2EscapeSymbol << std::endl;
        }
      }
      else {
        if (symProc.getTypeOfSymbol() == seqType::regular) {
          data2Output.open("regularOutput2", std::ios::out);
          char regC2;
          symProc.getSymbolChar(regC2);
          data2Output << regC2 << std::endl;
        }
        else if (symProc.getTypeOfSymbol() == seqType::unicode) {
          data2Output.open("unicodeOutput2", std::ios::out);
          char  uniC2;
          symProc.getSymbolChar(uniC2);
          data2Output << uniC2 << std::endl;
        }
        else if (symProc.getTypeOfSymbol() == seqType::escape) {
          data2Output.open("escapeOutput2", std::ios::out);
          char escC2;
          symProc.getSymbolChar(escC2);
          data2Output << escC2 << std::endl;
        }
      }
    }
  std::cout << std::endl;

  std::cout << "PLEASE SEE FOLLOWING OBJ FILES FOR OUTPUT: (if exist) " << std::endl;
  std::cout << "   regularOutput1, unicodeOutput1, escapeOutput1, regularOutput2, unicodeOutput2, escapeOutput2" << std::endl;
  std::cout << std::endl;
  std::cout << "PLEASE SEE 'standardError' OBJ FILE FOR ERROR OUTPUT" << std::endl;

  char stop;
  std::cout << "program has ended, please enter 'a' key..." << std::endl;
  std::cin >> stop;
  return 0;
}