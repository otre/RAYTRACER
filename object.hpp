#ifndef OBJECT_HPP
#define OBJECT_HPP

#include "vec3.hpp"

class Object{
 protected:
  // coefficient de reflectance de l'objet
  double m_reflectance;
  // coefficient de transmission de l'objet
  double m_transmittance;
  // coefficient ambiant
  vec3 m_ambient;
  // coefficient diffus
  vec3 m_diffuse;
  // coefficient speculaire
  vec3 m_specular;
  // coefficient de brillance
  double m_shininess;

 public:
  // initialisation standard
  Object():
    m_ambient(0.7),
    m_diffuse(0.7),
    m_specular(0.7),
    m_shininess(10)
  {
  }

  // renvoie le test d'intersection i avec l'objet
  virtual double isIntersected(const vec3& ray, const vec3& start, vec3& i) const =0;
  // renvoie la normal au point d'intersection
  virtual vec3 normal(const vec3& ray, const vec3& intersection) const =0;

  // l'objet a-t-il une composante de reflexion?
  inline bool isReflective() const{
    return (m_reflectance > 0);
  }

  // l'objet a-t-il une composante de refraction?
  inline bool isTransmissive() const{
    return (m_transmittance > 0);
  }

  // renvoie le coefficient ambiant
  inline vec3 ambient() const{
    return m_ambient;
  }

  // renvoie le coefficient diffus
  inline vec3 diffuse() const{
    return m_diffuse;
  }

  // renvoie le coefficient speculaire
  inline vec3 specular() const{
    return m_specular;
  }

  // renvoie le coefficient de brillance
  inline double shininess() const{
    return m_shininess;
  }
};

#endif // OBJECT_HPP
