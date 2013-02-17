#include "light.hpp"

Light::Light():
  m_x(0),
  m_y(0),
  m_z(0)
{
}

Light::Light(double x, double y, double z):
  m_x(x),
  m_y(y),
  m_z(z)
{
}

Light::~Light(){
  m_x =0;
  m_y =0;
  m_z =0;
}
