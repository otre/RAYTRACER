#ifndef SCENE_HPP
#define SCENE_HPP

#include <list>
#include <fstream>
#include "object.hpp"
#include "sphere.hpp"
#include "plane.hpp"
#include "light.hpp"
#include "camera.hpp"

class Scene{
private:
  // camera de la scene
  Camera m_camera;
  // liste des objets de la scene
  std::list<Object*> m_object;
  // liste des lumieres de la scene
  std::list<Light*> m_light;
  // dimension de la sortie
  unsigned int m_width, m_height;

public:
  // largeur par defaut de l'image
  static const unsigned int WIDTH;
  // hauteur par defaut de l'image
  static const unsigned int HEIGHT;

  // prepare une scene vide
  Scene();
  // destructeur
  ~Scene();

  // charge une scene par defaut
  void loadDefault();

  // renvoie la largeur de la sortie
  inline unsigned int width(){
    return m_width;
  }

  // renvoie la heuteur de la sortie
  inline unsigned int height(){
    return m_height;
  }

  // renvoie la position de la camera
  inline vec3& position(){
    return m_camera.position();
  }

  // renvoie le plan de projection de la camera
  inline void project(vec3& u, vec3& v, vec3& origin){
    m_camera.project(m_width, m_height, u, v, origin);
  }
};

#endif // SCENE_HPP
