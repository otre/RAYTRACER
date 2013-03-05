#ifndef COLOR_HPP
#define COLOR_HPP

#include "object.hpp"
#include "vec3.hpp"

class Color{
private:

public:
  // renvoie la couleur de fond de la scene
  static void computeBackgroundColor(double ligne, double height, vec3& color);
  static vec3 computeBackgroundColor(double ligne, double height);

  // renvoie la couleur de l'intersection selon le modele de Lambert
  static vec3 computeLambertBRDF(const vec3& lightRay, const vec3& normal, const Object* object);

  // renvoie la couleur de l'intersection selon le modele de Phong
  static vec3 computePhongBRDF(const vec3& ray, const vec3& eye, const vec3& intersection, const Object* object);
};

#endif // COLOR_HPP

