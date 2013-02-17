#include "sphere.hpp"

Sphere::Sphere(){
  m_rayon =1;
}

Sphere::Sphere(const vec3& n){
  m_centre =n;
  m_rayon =1;
}

Sphere::Sphere(const vec3& n, double d){
  m_centre =n;
  m_rayon =d;
}

Sphere::~Sphere(){
  m_centre.fill(0);
  m_rayon =0;
}

bool Sphere::intersect(const vec3& ray, const vec3& eye, vec3& i){
  bool ret=false;

  return ret;
}
