#include "scene.hpp"

const unsigned int Scene::WIDTH=800;
const unsigned int Scene::HEIGHT=600;

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
  m_object.push_back(new Sphere());
  m_light.push_back(new Light(3, 0, 0));
  m_width =WIDTH;
  m_height =HEIGHT;
}
