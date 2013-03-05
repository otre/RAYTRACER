#include "sphere.hpp"

Sphere::Sphere():
  m_radius(1)
{
}

Sphere::Sphere(const vec3& n):
  m_center(n),
  m_radius(1)
{
}
Sphere::Sphere(const vec3& n, double d):
  m_center(n),
  m_radius(d)
{
}

Sphere::Sphere(double d):
  m_radius(d)
{
}

Sphere::~Sphere(){
  m_center.fill(0);
  m_radius =0;
}

double Sphere::isIntersected(const vec3& ray, const vec3& start, vec3& i) const{
  double b, c, d, distance;
  vec3 v =start-m_center;

  b =2*ray.dot(v);
  c =v.dot(v) - m_radius*m_radius;
  d = b*b - 4*c;

  if(d < 0){
    return -1;
  }

  distance = (-b - sqrt(d))*0.5;
  if(distance > 0){
    i =start + distance * ray;
  }

  return distance;
}

vec3 Sphere::normal(const vec3& ray, const vec3& intersection) const{
  vec3 n =m_center - intersection;

  n.normalize();

  return n;
}
