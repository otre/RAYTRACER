#ifndef INFO_HPP
#define INFO_HPP

#include <cstdlib>
#include <unistd.h>
#include <string>

class Info{
private:
  unsigned int m_core;

public:
  // constructeur standard
  Info();

  // compte le nombre de coeur de la machine
  void countCPUCore();
};

#endif
