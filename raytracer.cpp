#include "raytracer.hpp"

const unsigned int RayTracer::WIDTH=800;
const unsigned int RayTracer::HEIGHT=600;

RayTracer::RayTracer(Parser& p):
  m_parser(p)
{
}

RayTracer::~RayTracer(){
}

ContiguousDataMatrix<vec3>& RayTracer::render(){

  return m_image;
}

