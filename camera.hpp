#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "vec3.hpp"

class Camera{
private:
  // position de la camera
  vec3 m_position;
  // objectif de la camera
  vec3 m_target;
  // distance au premier plan (zoom)
  double m_near;

  // vecteur generateur du plan de projection
  vec3 u, v;

public:
  // construit une camera standard
  Camera();
  // construit la camera a partir de position et de l'origine
  Camera(const vec3& position);
  // construit la camera a partir de position et de target 
  Camera(const vec3& position, const vec3& target);
  // destructeur
  ~Camera();

  // deplace la camera a la position indiqué
  void move(double x, double y, double z);
  void move(const vec3& position);

  // cible la camera sur la position indiqué
  void look(double x, double y, double z);
  void look(const vec3& target);

  // renvoie la position de la camera
  inline vec3& position(){
    return m_position;
  }

  // renvoie la cible de la camera
  inline vec3& target(){
    return m_target;
  }
};

#endif
