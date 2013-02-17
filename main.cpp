#include "raytracer.hpp"

int main(){
  ContiguousDataMatrix<vec3> out;
  Parser parser;
  RayTracer raytracer(parser);

  parser.loadDefault();
  out =raytracer.render();

  return 0;
}
