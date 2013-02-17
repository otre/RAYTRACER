#include "raytracer.hpp"

const unsigned int RayTracer::WIDTH=800;
const unsigned int RayTracer::HEIGHT=600;

RayTracer::RayTracer():
  m_width(WIDTH),
  m_heigth(HEIGHT),
  m_image(WIDTH, HEIGHT)
{
}

RayTracer::~RayTracer(){
  m_width =0;
  m_heigth =0;
}

ContiguousDataMatrix<vec3>& RayTracer::render(){

  return m_image;
}

