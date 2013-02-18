#ifndef SCENE_HPP
#define SCENE_HPP

#include <list>
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
    return m_width;
  }
};

#endif // SCENE_HPP
