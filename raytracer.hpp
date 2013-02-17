#ifndef RAYTRACER_H
#define RAYTRACER_H

#include "parser.hpp"
#include "contiguousdatamatrix.hpp"
#include "light.hpp"

class RayTracer{
private:
  vec3 m_eye;
  vec3 m_ray;
  ContiguousDataMatrix<vec3> m_image;
  unsigned int m_width;
  unsigned int m_heigth;

public:
  RayTracer();
  RayTracer(std::list<Object> o, std::list<Light> l);
  ~RayTracer();
  ContiguousDataMatrix<vec3>& render();
};

#endif // RAYTRACER_H
