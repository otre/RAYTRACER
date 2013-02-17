#include "raytracer.hpp"

int main(int argc, char** argv){
  ContiguousDataMatrix<vec3> out;
  Parser parser;
  RayTracer raytracer(parser);

  if(argc > 1){
    parser.load(argv[1]);
    out =raytracer.render();
  }
  return 0;
}
