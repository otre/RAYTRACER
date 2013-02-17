#ifndef LIGHT_H
#define LIGHT_H

class Light{
private:
  double m_x, m_y, m_z;

public:
  Light();
  Light(double x, double y, double z);
  ~Light();
};

#endif
