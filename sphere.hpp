#ifndef SPHERE_HPP
#define SPHERE_HPP

#include "object.hpp"

class Sphere : public Object{
 private:
  // centre de la sphere
  vec3 m_center;
  // rayon de la sphere
  double m_radius;

 public:
  // cree une sphere centree sur l'origine et de rayon 1.0
  Sphere();
  // cree une sphere de centre c et de rayon 1.0
  Sphere(const vec3& c);
  // cree une sphere de centre c et de rayon r
  Sphere(const vec3& c, double r);
  // cree une sphere centree sur l'origine et de rayon r
  Sphere(double r);
  // Destructeur standard
  ~Sphere();

  // renvoie le resultat du test d'intersection i avec la sphere
  double isIntersected(const vec3& ray, const vec3& start, vec3& i) const;

  // renvoie la normal au point d'intersection
  vec3 normal(const vec3& ray, const vec3& intersection) const;
};

#endif // SPHERE_HPP
