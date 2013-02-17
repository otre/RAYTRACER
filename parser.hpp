#ifndef PARSER_H
#define PARSER_H

#include <list>
#include "object.hpp"
#include "sphere.hpp"
#include "plane.hpp"
#include "light.hpp"

class Parser{
private:
  // position de la camera
  vec3 m_eye;
  // liste des objets de la scene
  std::list<Object*> m_object;
  // liste des lumieres de la scene
  std::list<Light*> m_light;

public:
  Parser();
  Parser(char file[]);
  ~Parser();

  void load(char file[]);
};

#endif
