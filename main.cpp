#include "raytracer.hpp"

int main(){
  ContiguousDataMatrix<vec3> image;
  RayTracer raytracer;

  image =raytracer.render();

  return 0;
}
