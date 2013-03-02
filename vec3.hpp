#ifndef VEC3_H
#define VEC3_H

#include <iostream>
#include <cmath>

class vec3{
private:
  // composantes du vecteur
  double m_x, m_y, m_z;

public:
  // Cree un vecteur nul
  vec3();
  // Cree un vecteur a partir d'une reference
  vec3(const vec3& v);
  // Cree un vecteur a partir de deux coordonnees
  vec3(const vec3& a, const vec3& b);
  // Cree un vecteur composé de champs constant t
  vec3(double t);
  // Cree le vecteur v(x,y,z)
  vec3(double x, double y, double z);
  // Destructeur standard
  ~vec3();

  // approximation du zero en double
  static const double EPSILON;

  // Produit vectoriel
  static void cross(vec3& u, vec3& v, vec3& res);
  inline void cross(const vec3& v, vec3& res){
    res.m_x =m_y*v.m_z - m_z*v.m_y;
    res.m_y =m_z*v.m_x - m_x*v.m_z;
    res.m_z =m_x*v.m_y - m_y*v.m_x;
  }
  
  // Produit scalaire
  static double dot(vec3& u, vec3& v);
  inline double dot(const vec3& v){
    return m_x*v.m_x + m_y*v.m_y + m_z*v.m_z;
  }

  // renvoie un vecteur de double contigus [x|y|z] alloué dans le tas
  double* constData();
  // renvoie la version normalisée du vecteur
  void normalized(vec3& res);
  // normalise le vecteur
  inline void normalize(){
    double l;
    
    l =length();
    if(!isOne(l)){
      m_x /=l;
      m_y /=l;
      m_z /=l;
    }
  }

  // renvoie la norme du vecteur
  inline double length(){
    return sqrt(m_x*m_x + m_y*m_y + m_z*m_z);
  }

  // compose le vecteur de champs constant t
  inline void fill(double t){
    m_x =t;
    m_y =t;
    m_z =t;
  }

  // initialise le vecteur courant par le vecteur v
  vec3& operator=(const vec3& v);
  // additionne le vecteur v au vecteur courant
  vec3& operator+(const vec3& v);
  // soustraie le vecteur v au vecteur courant
  vec3& operator-(const vec3& v);
  // multiplie le vecteur courant par un scalaire
  vec3& operator*(double d);
  friend vec3& operator*(double d, vec3& v);
  // divise le vecteur courant par un scalaire
  vec3& operator/(double d);
  friend vec3& operator/(double d, vec3& v);
  // renvoie la chaine d'informations du vecteur
  friend std::ostream& operator<<(std::ostream& out, vec3& v);
  // saisie le vecteur
  friend std::istream& operator>>(std::istream& in, vec3& v);

  // teste l'approximation du zero de d 
  inline bool isZero(double d){
    return (fabs(d) < EPSILON);
  }

  // teste l'approximation du zero de d 
  inline bool isOne(double d){
    return (fabs(d-1) < EPSILON);
  }

  // renvoie la composante x du vecteur
  inline double x(){
    return m_x;
  }

  // renvoie la composante y du vecteur
  inline double y(){
    return m_y;
  }

  // renvoie la composante z du vecteur
  inline double z(){
    return m_z;
  }

  // modifie la composante x du vecteur
  inline void setX(double m_x){
    this->m_x =m_x;
  }
  // modifie la composante y du vecteur
  inline void setY(double m_y){
    this->m_y =m_y;
  }
  // modifie la composante z du vecteur
  inline void setZ(double m_z){
    this->m_z =m_z;
  }
  // modifie toutes les composantes du vecteurs
  inline void set(double x, double y, double z){
    this->m_x =x;
    this->m_y =y;
    this->m_z =z;
  }
  // arrondi toutes les composantes du vecteur
  inline void toInt(){
    m_x =floor(m_x);
    m_y =floor(m_y);
    m_z =floor(m_z);
  }
};

#endif
