#pragma once
#include "erroroutput.h"
#include <ostream>
class streamo {
public:
  streamo(std::ostream *ostr);
  ~streamo();
  void outputError(std::string msg);

  void copyErrorObj(erroroutput erro);
private:
  std::ostream fickleStream;

  erroroutput er1;

};