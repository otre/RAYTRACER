#include "raytracer.hpp"

RayTracer::RayTracer():
  m_width(800),
  m_heigth(600)
{
}

RayTracer::RayTracer(std::list<Object>& o, std::list<Light>& l):
  m_width(800),
  m_heigth(600)
{
}

RayTracer::~RayTracer(){
  m_width =0;
  m_heigth =0;
}

ContiguousDataMatrix<vec3>& RayTracer::render(){

  return m_image;
}

