#include "raytracer.hpp"

int main(){
  char file[]="render.ppm";
  Scene scene;
  RayTracer raytracer(scene);

  scene.loadDefault();
  raytracer.renderToPPM(file);

  return 0;
}
