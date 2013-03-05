#include "scene.hpp"

const unsigned int Scene::WIDTH=800;
const unsigned int Scene::HEIGHT=600;

Scene::Scene():
  m_width(0),
  m_height(0)
{
}

Scene::~Scene(){
  for(m_iteObj=m_object.begin(); m_iteObj!=m_object.end(); m_iteObj++){
    delete *m_iteObj;
  }

  for(m_iteLight=m_light.begin(); m_iteLight!=m_light.end(); m_iteLight++){
    delete *m_iteLight;
  }
}

void Scene::loadDefault(){
  m_camera.move(1000,1000,1000);
  m_camera.look(100,100,100);
  m_object.push_back(new Sphere(vec3(0, 0, 0), 30));
  m_light.push_back(new Light(0, 0, 3));
  m_width =WIDTH;
  m_height =HEIGHT;
}
