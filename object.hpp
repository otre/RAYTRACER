#ifndef OBJECT_H
#define OBJECT_H

#include "vec3.hpp"

class Object{
 protected:

 public:
  // renvoie le test d'intersection i avec l'objet
  virtual bool intersect(const vec3& ray, const vec3& eye, vec3& i)=0;
};

#endif // OBJECT_H
