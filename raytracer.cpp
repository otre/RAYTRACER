#include "raytracer.hpp"

RayTracer::RayTracer(Scene& p):
  m_scene(p)
{
}

RayTracer::~RayTracer(){
}

ContiguousDataMatrix<vec3>& RayTracer::render(){
  return m_image;
}

void RayTracer::renderToPPM(char file[]){
  std::ofstream out;
  Object* o;
  double t;
  vec3 background, color, origin, eye, u, v;
  vec3 i;

  out.open(file);
  m_scene.cameraPosition(eye);
  m_scene.cameraProjection(u, v, origin);

  if(out){
    // En-tête du fichier
    out << "P3" << std::endl;
    out << m_scene.width() << " " << m_scene.height() << std::endl;
    out << 255 << std::endl;

    for(unsigned int ligne=0; ligne<m_scene.height(); ligne++){
      background =Color::computeBackgroundColor(ligne, m_scene.height());
      for(unsigned int colonne=0; colonne<m_scene.width(); colonne++){
	m_ray =(origin + colonne*u + ligne*v) - eye;
	m_ray.normalize();

	o =m_scene.intersect(m_ray, eye, NULL, i, t);
	if(o != NULL){
	  color =m_scene.shade(m_ray, i, o);
	  color =color * 255;
	  color.toInt();
	  out << color  << " ";
	}
	else{
	  out << background  << " ";
	}
      }
      out << std::endl;
    }

    out.close();
  }
}
