#include "camera.hpp"

Camera::Camera():
  m_position(3,3,3),
  m_up(0,0,1),
  m_distance(0),
  m_isViewInitialized(false)
{
  computeUV();
}

Camera::Camera(const vec3& position):
  m_position(position),
  m_up(0,0,1),
  m_distance(0),
  m_isViewInitialized(false)
{
  computeUV();
}

Camera::Camera(const vec3& position, const vec3& target):
  m_position(position),
  m_target(target),
  m_up(0,0,1),
  m_distance(0),
  m_isViewInitialized(false)
{
  computeUV();
}

Camera::Camera(const vec3& position, const vec3& target, const vec3& up):
  m_position(position),
  m_target(target),
  m_up(up),
  m_distance(0),
  m_isViewInitialized(false)
{
  computeUV();
}

Camera::Camera(const vec3& position, const vec3& view, double distance):
  m_position(position),
  m_view(view),
  m_distance(distance),
  m_isViewInitialized(true)
{
  m_view.normalize();
  computeUV();
}

Camera::Camera(const vec3& position, const vec3& view, const vec3& up, double distance):
  m_position(position),
  m_up(up),
  m_view(view),
  m_distance(distance),
  m_isViewInitialized(true)
{
  m_view.normalize();
  computeUV();
}


Camera::~Camera(){
  m_distance =0;
  m_isViewInitialized =false;
}

void Camera::computeUV(){
  if(m_isViewInitialized == false){
    m_view =m_target - m_position,
    m_distance =m_view.length();
    m_view.normalize();
  }
  else{
    m_target =m_position + m_distance * m_view;
  }

  m_view.cross(m_up, m_u);
  m_view.cross(m_u, m_v);
}

void Camera::move(double x, double y, double z){
  m_position.set(x, y, z);
  computeUV();
}

void Camera::move(const vec3& position){
  m_position =position;
  computeUV();
}

void Camera::look(double x, double y, double z){
  m_target.set(x, y, z);
  computeUV();
}

void Camera::look(const vec3& target){
  m_target =target;
  computeUV();
}

void Camera::project(unsigned int width, unsigned int height, vec3& u, vec3& v, vec3& origin){
  u =m_u;
  v =m_v;
  origin =m_target - (width/2)*u - (height/2)*v;
}
