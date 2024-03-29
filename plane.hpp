#ifndef PLANE_HPP
#define PLANE_HPP

#include "object.hpp"

class Plane : public Object{
 private:
  // normale au plan
  vec3 m_normal;
  // decalage a l'origine
  double m_delta;

 public:
  // cree un plan à l'origine de normale vers le haut
  Plane();
  // cree un plan à l'origine de normale n
  Plane(const vec3& n);
  // cree un plan à l'origine de normale n et de decalage à l'origine d
  Plane(const vec3& n, double d);
  // Destructeur standard
  ~Plane();

  // renvoie le resultat du test d'intersection i avec le plan
  double isIntersected(const vec3& ray, const vec3& eye, vec3& i);
  // renvoie la normal au point d'intersection
  vec3 normal(const vec3& ray, const vec3& intersection);
};

#endif // PLANE_HPP
