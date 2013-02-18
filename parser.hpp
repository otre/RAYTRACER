#ifndef PARSER_HPP
#define PARSER_HPP

#include <fstream>
#include "scene.hpp"

class Parser{
private:
  // parse le contenu du fichier pour le stocker dans la m_scene
  Scene m_scene;

public:
  // construit le parser a partir du fichier file
  Parser(char file[]);
  // destructeur
  ~Parser();
  
  // renvoie la scene
  inline Scene& scene(){
    return m_scene;
  }
};

#endif // PARSER_HPP
