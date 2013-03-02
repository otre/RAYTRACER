#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "vec3.hpp"

class Camera{
private:
  // position de la camera
  vec3 m_position;
  // objectif de la camera
  vec3 m_target;
  // z-direction
  vec3 m_up;
  // direction d'observation
  vec3 m_view;
  // distance au premier plan (zoom)
  double m_distance;
  // la direction d'observation est-elle initialisée?
  bool m_isViewInitialized;

  // vecteurs generateurs du plan de projection
  vec3 m_u, m_v;

  // construit le plan de projection
  void computeUV();

public:
  // construit une camera standard
  Camera();
  // construit la camera a partir de position et de l'origine
  Camera(const vec3& position);
  // construit la camera a partir de position et de target 
  Camera(const vec3& position, const vec3& target);
  // construit la camera a partir de position, de target et de la z-direction
  Camera(const vec3& position, const vec3& target, const vec3& up);
  // construit la camera a partir de position, de view et de distance
  Camera(const vec3& position, const vec3& view, double distance);
  // construit la camera a partir de position, de view, de up et de distance
  Camera(const vec3& position, const vec3& view, const vec3& up, double distance);
  // destructeur
  ~Camera();

  // deplace la camera a la position indiqué
  void move(double x, double y, double z);
  void move(const vec3& position);

  // cible la camera sur la position indiqué
  void look(double x, double y, double z);
  void look(const vec3& target);

  // renvoie le plan de projection
  void project(unsigned int width, unsigned int height, vec3& u, vec3& v, vec3& origin);

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
