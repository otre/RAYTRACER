#include "plane.hpp"

Plane::Plane():
  m_delta(0)
{
}

Plane::Plane(const vec3& n):
  m_normal(n),
  m_delta(0)
{
  m_normal.normalize();
}

Plane::Plane(const vec3& n, double d):
  m_normal(n),
  m_delta(d)
{
  m_normal.normalize();
}

Plane::~Plane(){
  m_normal.fill(0);
  m_delta =0;
}

double Plane::isIntersected(const vec3& ray, const vec3& eye, vec3& i){
  return -1;
}

vec3 Plane::normal(const vec3& ray, const vec3& intersection){
  return m_normal;
}
