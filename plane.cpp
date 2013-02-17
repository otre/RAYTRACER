#include "plane.hpp"

Plane::Plane(){
  m_delta =0;
}

Plane::Plane(const vec3& n){
  m_normal =n;
  m_delta =0;
}

Plane::Plane(const vec3& n, double d){
  m_normal =n;
  m_delta =d;
}

Plane::~Plane(){
  m_normal.fill(0);
  m_delta =0;
}

bool Plane::intersect(const vec3& ray, const vec3& eye, vec3& i){
  bool ret=false;

  return ret;
}
