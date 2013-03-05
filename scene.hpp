#ifndef SCENE_HPP
#define SCENE_HPP

#include <list>
#include <fstream>
#include "object.hpp"
#include "sphere.hpp"
#include "plane.hpp"
#include "light.hpp"
#include "camera.hpp"
#include "color.hpp"

class Scene{
private:
  // camera de la scene
  Camera m_camera;

  // liste des objets de la scene
  std::list<Object*> m_object;
  std::list<Object*>::iterator m_iteObj;

  // liste des lumieres de la scene
  std::list<Light*> m_light;
  std::list<Light*>::iterator m_iteLight;

  // dimensions de la sortie
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
  inline unsigned int width() const{
    return m_width;
  }

  // renvoie la heuteur de la sortie
  inline unsigned int height() const{
    return m_height;
  }

  // renvoie la position de la camera
  inline void cameraPosition(vec3& eye){
    eye =m_camera.position();
  }

  // renvoie le plan de projection de la camera
  inline void cameraProjection(vec3& u, vec3& v, vec3& origin){
    m_camera.project(m_width, m_height, u, v, origin);
  }

  // renvoie le point d'intersection i du plus proche objet o par start et ray
  inline Object* intersect(const vec3& ray, const vec3& start, const Object* exception,vec3& intersection, double& distance){
    double t;
    vec3 i;
    Object* o;

    distance =-1;
    o =NULL;
    t =m_camera.far();

    for(m_iteObj=m_object.begin(); m_iteObj!=m_object.end(); m_iteObj++){
      if(exception == NULL || (*m_iteObj) != exception){
	distance =(*m_iteObj)->isIntersected(ray, start, i);
	if(distance > 0 && distance < t){
	  t =distance;
	  o =(*m_iteObj);
	  intersection =i;
	}
      }
    }

    return o;
  }

  // renvoie la coloration pour le point d'intersection
  inline vec3 shade(const vec3& ray, const vec3& intersection, const Object* object){
    vec3 shadowRay, color, normal, i;
    double t;

    for(m_iteLight=m_light.begin(); m_iteLight!=m_light.end(); m_iteLight++){
      shadowRay =(*m_iteLight)->position() -intersection;
      shadowRay.normalize();

      if(intersect(shadowRay, intersection, object, i, t) == NULL){
	normal =object->normal(ray, intersection);

	color +=Color::computePhongBRDF(shadowRay, normal, m_camera.view(), object, (*m_iteLight));
      }
    }

    return color;
  }
};

#endif // SCENE_HPP
