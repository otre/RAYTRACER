#ifndef LIGHT_HPP
#define LIGHT_HPP

#include "vec3.hpp"

class Light{
private:
  vec3 m_position;

public:
  // construction de la lumiere standard
  Light();
  // construction de la lumiere a sa position (x,y,z)
  Light(double x, double y, double z);
  // construction de la lumiere a sa position
  Light(const vec3& position);
  // destructeur
  ~Light();

  // renvoie la position de la lumiere
  inline vec3& position(){
    return m_position;
  }
};

#endif // LIGHT_HPP
