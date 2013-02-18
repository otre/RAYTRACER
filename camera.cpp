#include "camera.hpp"

Camera::Camera():
  m_near(0)
{
}

Camera::Camera(const vec3& position):
  m_position(position),
  m_near(0)
{
}

Camera::Camera(const vec3& position, const vec3& target):
  m_position(position),
  m_target(target),
  m_near(0)
{
}

Camera::~Camera(){
  m_near =0;
}

void Camera::move(double x, double y, double z){
  m_position.set(x, y, z);
}

void Camera::move(const vec3& position){
  m_position =position;
}

void Camera::look(double x, double y, double z){
  m_target.set(x, y, z);
}

void Camera::look(const vec3& target){
  m_target =target;
}
