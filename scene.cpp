#include "scene.hpp"

Scene::Scene():
  m_width(0),
  m_height(0)
{
}

Scene::~Scene(){
  std::list<Object*>::iterator iteObj;
  for(iteObj=m_object.begin(); iteObj!=m_object.end(); iteObj++){
    delete *iteObj;
  }

  std::list<Light*>::iterator iteLight;
  for(iteLight=m_light.begin(); iteLight!=m_light.end(); iteLight++){
    delete *iteLight;
  }
}

void Scene::loadDefault(){
  m_camera.move(3,3,3);
  m_object.push_back(new Sphere());
  m_light.push_back(new Light(3, 0, 0));
  m_width =800;
  m_height =600;
}
