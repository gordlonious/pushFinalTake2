
#include <string>

class erroroutput {
public:
  erroroutput(char* msg);
  erroroutput(std::string msg);
  ~erroroutput();
private:
  char* errorThis;
  std::string stdStr;

};