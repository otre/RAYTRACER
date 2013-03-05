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
  static void cross(const vec3& u, const vec3& v, vec3& res);
  inline void cross(const vec3& v, vec3& res) const{
    res.m_x =m_y*v.m_z - m_z*v.m_y;
    res.m_y =m_z*v.m_x - m_x*v.m_z;
    res.m_z =m_x*v.m_y - m_y*v.m_x;
  }
  
  // Produit scalaire
  static double dot(const vec3& u, const vec3& v);
  inline double dot(const vec3& v) const{
    return m_x*v.m_x + m_y*v.m_y + m_z*v.m_z;
  }

  // renvoie la distance entre deux points
  static double distance(const vec3& u, const vec3& v);
  inline double distance(const vec3& v){
    return sqrt(m_x*v.m_x + m_y*v.m_y + m_z*v.m_z);
  }

  // renvoie un vecteur de double contigus [x|y|z] alloué dans le tas
  double* constData() const;
  // renvoie la version normalisée du vecteur
  void normalized(vec3& res) const;
  // normalise le vecteur
  inline void normalize(){
    double l;
    
    l =length();
    if(l != 1){
      m_x /=l;
      m_y /=l;
      m_z /=l;
    }
  }

  // renvoie la norme du vecteur
  inline double length() const{
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
  vec3& operator+=(const vec3& v);
  // renvoie l'addition entre le vecteur v et le vecteur courant
  vec3 operator+(const vec3& v) const;
  // renvoie la soustraction entre le vecteur v et le vecteur courant
  vec3 operator-(const vec3& v) const;
  // renvoie la multiplication du vecteur courant par un scalaire
  vec3 operator*(double d) const;
  friend vec3 operator*(double d, const vec3& v);
  // renvoie la division du vecteur courant par un scalaire
  vec3 operator/(double d) const;
  friend vec3 operator/(double d, const vec3& v);
  // renvoie la chaine d'informations du vecteur
  friend std::ostream& operator<<(std::ostream& out, vec3& v);
  // saisie le vecteur
  friend std::istream& operator>>(std::istream& in, vec3& v);

  // teste l'approximation du zero de d 
  bool isZero(double d) const;

  // teste l'approximation du zero de d 
  bool isOne(double d) const;
  
  // renvoie la composante x du vecteur
  inline double x() const{
    return m_x;
  }

  // renvoie la composante y du vecteur
  inline double y() const{
    return m_y;
  }

  // renvoie la composante z du vecteur
  inline double z() const{
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
