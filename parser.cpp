#include "parser.hpp"

Parser::Parser(){
}

Parser::Parser(char file[]){
}

void Parser::load(char file[]){
}

Parser::~Parser(){
  std::list<Object*>::iterator iteObj;
  for(iteObj=m_object.begin(); iteObj!=m_object.end(); iteObj++){
    delete *iteObj;
  }

  std::list<Light*>::iterator iteLight;
  for(iteLight=m_light.begin(); iteLight!=m_light.end(); iteLight++){
    delete *iteLight;
  }
}

void Parser::loadDefault(){
  m_eye.fill(3);
  m_object.push_back(new Sphere());
  m_light.push_back(new Light(3, 0, 0));
}
