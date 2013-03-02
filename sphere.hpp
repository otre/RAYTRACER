#ifndef SPHERE_HPP
#define SPHERE_HPP

#include "object.hpp"

class Sphere : public Object{
 private:
  // centre de la sphere
  vec3 m_centre;
  // rayon de la sphere
  double m_rayon;

 public:
  // cree une sphere centree sur l'origine et de rayon 1.0
  Sphere();
  // cree une sphere de centre c et de rayon 1.0
  Sphere(const vec3& c);
  // cree une sphere de centre c et de rayon r
  Sphere(const vec3& c, double r);
  // Destructeur standard
  ~Sphere();

  // renvoie le resultat du test d'intersection i avec la sphere
  bool isIntersected(const vec3& ray, const vec3& eye, vec3& i);
};

#endif // SPHERE_HPP
