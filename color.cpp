#include "color.hpp"

void Color::computeBackgroundColor(double ligne, double height, vec3& color){
  color.set(0, 0, 255-(ligne/height*255));
  color.toInt();
}

vec3 Color::computeBackgroundColor(double ligne, double height){
  vec3 color(0, 0, 255-(ligne/height*255));
  color.toInt();

  return color;
}

vec3 Color::computeLambertBRDF(const vec3& lightRay, const vec3& normal, const Object* object, const Light* light){
  vec3 color;

  color =light->diffuse() * object->diffuse() * normal.dot(lightRay);

  return color;
}

vec3 Color::computePhongBRDF(const vec3& lightRay, const vec3& normal, const vec3& view, const Object* object, const Light* light){
  vec3 color, r;
  double t;

  color =computeLambertBRDF(lightRay, normal, object, light);
  r =2*lightRay.dot(normal)*normal - lightRay;
  t =r.dot(view);
  color +=light->specular() * object->specular() * pow(t, object->shininess());

  return color;
}
