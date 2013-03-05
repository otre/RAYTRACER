#ifndef LIGHT_HPP
#define LIGHT_HPP

#include "vec3.hpp"

class Light{
private:
  // position de la source lumineuse
  vec3 m_position;
  // intensite de lumiere incidente diffuse
  vec3 m_diffuse;
  // intensite de lumiere incidente speculaire
  vec3 m_specular;

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
  inline vec3 position() const{
    return m_position;
  }

  // renvoie la composante diffuse de la lumiere
  inline vec3 diffuse() const{
    return m_diffuse;
  }

  // renvoie la composante speculaire de la lumiere
  inline vec3 specular() const{
    return m_specular;
  }

  // modifie la composante diffuse de la lumiere
  inline void setDiffuse(const vec3& diffuse){
    m_diffuse =diffuse;
  }

  // modifie la composante speculaire de la lumiere
  inline void setSpecular(const vec3& specular){
    m_specular =specular;
  }
};

#endif // LIGHT_HPP
