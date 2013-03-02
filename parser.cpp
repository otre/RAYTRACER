#include "parser.hpp"

Parser::Parser(char file[]){
  std::ifstream in(file);

  in.close();
}

Parser::~Parser(){
}



