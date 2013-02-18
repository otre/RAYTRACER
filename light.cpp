#include "light.hpp"

Light::Light(){
}

Light::Light(double x, double y, double z):
  m_position(x, y, z)
{
}

Light::Light(const vec3& position):
  m_position(position)
{
}

Light::~Light(){
}
