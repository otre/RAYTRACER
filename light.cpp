#include "light.hpp"

Light::Light():
  m_diffuse(1),
  m_specular(1)
{
}

Light::Light(double x, double y, double z):
  m_position(x, y, z),
  m_diffuse(1),
  m_specular(1)
{
}

Light::Light(const vec3& position):
  m_position(position),
  m_diffuse(1),
  m_specular(1)
{
}

Light::~Light(){
}
