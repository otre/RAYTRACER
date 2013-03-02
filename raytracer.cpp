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
  vec3 color, origin, eye, u, v;

  color.fill(255);
  eye =m_scene.position();
  out.open(file);
  m_scene.project(u, v, origin);

  if(out){
    // En-tête du fichier
    out << "P3" << std::endl;
    out << m_scene.width() << " " << m_scene.height() << std::endl;
    out << 255 << std::endl;

    for(unsigned int i=0; i<m_scene.width(); i++){
      for(unsigned int j=0; j<m_scene.height(); j++){
	m_ray =(origin + i*u + j*v) - eye;

	out << color  << " ";
      }
      out << std::endl;
    }

    out.close();
  }
}
