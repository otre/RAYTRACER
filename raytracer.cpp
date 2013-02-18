#include "raytracer.hpp"

const unsigned int RayTracer::WIDTH=800;
const unsigned int RayTracer::HEIGHT=600;

RayTracer::RayTracer(const Scene& p):
  m_scene(p)
{
}

RayTracer::~RayTracer(){
}

ContiguousDataMatrix<vec3>& RayTracer::render(){
  return m_image;
}

void RayTracer::renderToPPM(char file[]){
}
