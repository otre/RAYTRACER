#ifndef RAYTRACER_H
#define RAYTRACER_H

#include "scene.hpp"
#include "contiguousdatamatrix.hpp"

class RayTracer{
private:
  // rayon courant
  vec3 m_ray;
  // parser de la scene
  Scene& m_scene;
  // image de rendu
  ContiguousDataMatrix<vec3> m_image;

public:
  // configure le raytracer a partir d'un parser
  RayTracer(Scene& p);
  // destructeur
  ~RayTracer();

  // calcul du rendu dans un fichier au format PPM
  void renderToPPM(char file[]);
  // calcul du rendu au sein d'une matrice
  ContiguousDataMatrix<vec3>& render();
};

#endif // RAYTRACER_H
