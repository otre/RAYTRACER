#include "vec3.hpp"

const double vec3::EPSILON=0.00000000001;

vec3::vec3():
  m_x(0),
  m_y(0),
  m_z(0)
{
}

vec3::vec3(const vec3& v):
  m_x(v.m_x),
  m_y(v.m_y),
  m_z(v.m_z)
{
}

vec3::vec3(const vec3& a, const vec3& b):
  m_x(b.m_x - a.m_x),
  m_y(b.m_y - a.m_y),
  m_z(b.m_z - a.m_z)
{
}

vec3::vec3(double t):
  m_x(t),
  m_y(t),
  m_z(t)
{
}

vec3::vec3(double x, double y, double z):
  m_x(x),
  m_y(y),
  m_z(z)
{
}

vec3::~vec3(){
  m_x =0;
  m_y =0;
  m_z =0;
}

void vec3::cross(const vec3& u, const vec3& v, vec3& res){
  res.set(u.y()*v.z() - u.z()*v.y(),
	 u.z()*v.x() - u.x()*v.z(),
	 u.x()*v.y() - u.y()*v.x());
}

double vec3::dot(const vec3& u, const vec3& v){
  return u.x()*v.x() + u.y()*v.y() + u.z()*v.z();
}

double vec3::distance(const vec3& u, const vec3& v){
  return sqrt(u.x()*v.x() + u.y()*v.y() + u.z()*v.z());
}

std::ostream& operator<<(std::ostream& out, vec3& v){

  out << v.x() << " " << v.y() << " "<<v.z();

  return out;
}

std::istream& operator>>(std::istream& in, vec3& v){
  double x, y, z;

  in >> x;
  in >> y;
  in >> z;

  v.set(x, y, z);

  return in;
}

bool vec3::isZero(double d) const{
  return (fabs(d) < EPSILON);
}

bool vec3::isOne(double d) const{
  return (fabs(d-1) < EPSILON);
}

double* vec3::constData() const{
  double* v;

  v =new double[3];
  v[0] =m_x;
  v[1] =m_y;
  v[2] =m_z;

  return v;
}

void vec3::normalized(vec3& res) const{
  res.set(m_x, m_y, m_z);
  res.normalize();
}

vec3& vec3::operator=(const vec3& v){
  m_x =v.m_x;
  m_y =v.m_y;
  m_z =v.m_z;

  return *this;
}

vec3& vec3::operator+=(const vec3& v){
  m_x +=v.m_x;
  m_y +=v.m_y;
  m_z +=v.m_z;

  return *this;
}

vec3 vec3::operator+(const vec3& v) const{
  return vec3(m_x+v.m_x, m_y+v.m_y, m_z+v.m_z);
}

vec3 vec3::operator-(const vec3& v) const{
  return vec3(m_x-v.m_x, m_y-v.m_y, m_z-v.m_z);
}

vec3 vec3::operator*(double d) const{
  return vec3(m_x*d, m_y*d, m_z*d);
}

vec3 operator*(double d, const vec3& v){
  return v*d;
}

vec3 vec3::operator/(double d) const{
  if(!isZero(d)){
    return vec3(m_x/d, m_y/d, m_z/d);
  }

  return *this;
}

vec3 operator/(double d, const vec3& v){
  return v/d;
}
