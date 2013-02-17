#ifndef RAYTRACER_H
#define RAYTRACER_H

#include "parser.hpp"
#include "contiguousdatamatrix.hpp"

class RayTracer{
private:
  // rayon courant
  vec3 m_ray;
  // parser de la scene
  Parser& m_parser;
  // image de rendu
  ContiguousDataMatrix<vec3> m_image;

public:
  // largeur par defaut de l'image
  static const unsigned int WIDTH;
  // hauteur par defaut de l'image
  static const unsigned int HEIGHT;

  // configure le raytracer a partir d'un parser
  RayTracer(Parser& p);
  // destructeur
  ~RayTracer();

  // calcul du rendu
  ContiguousDataMatrix<vec3>& render();
};

#endif // RAYTRACER_H
