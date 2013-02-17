#ifndef MATRICE_H
#define MATRICE_H

#include <iostream>

template <class T>
class ContiguousDataMatrix{
private: 
  T* m_data;
  unsigned int m_width;
  unsigned int m_height;
  bool m_allocated;

  unsigned int i, j; 

public:
 
  ContiguousDataMatrix():
    m_data(NULL),
    m_width(0),
    m_height(0),
    m_allocated(false),
    i(0),
    j(0)
  {
  }

  ContiguousDataMatrix(unsigned int n):
    m_data(NULL),
    m_width(0),
    m_height(0),
    m_allocated(false),
    i(0),
    j(0)
  { 
    if(n > 0){
      m_data =new T[n*n];
      if(m_data != NULL){
	m_width =n;
	m_height =n;
	m_allocated =true;
      }
    }
  }

  ContiguousDataMatrix(unsigned int w, unsigned int h):
    m_data(NULL),
    m_width(0),
    m_height(0),
    m_allocated(false),
    i(0),
    j(0)
  {
    if(w > 0 && h > 0){
      m_data =new T[w*h];
      if(m_data != NULL){
	m_width =w;
	m_height =h;
	m_allocated =true;
      }
    }
  }

  ContiguousDataMatrix(const ContiguousDataMatrix<T>& m):
    m_data(NULL),
    m_width(0),
    m_height(0),
    m_allocated(false),
    i(0),
    j(0)
  {
    m_data =new T[m.m_width * m.m_height];
    if(m_data != NULL){
      m_width =m.m_width;
      m_height =m.m_height;
      m_allocated =true;
    }
  }

  ~ContiguousDataMatrix(){
    if(m_allocated){
      delete[] m_data;
      m_data =NULL;
      m_width =0;
      m_height =0;
      m_allocated =false;
      i =0;
      j =0;
    }
  }

  void fill(T t){
    if(m_allocated){
      for(i=0; i<m_width; i++){
	for(j=0; j<m_height; j++){
	  m_data[j+i*m_width] =t;
	}
      }
    }
  }

  ContiguousDataMatrix<T>& operator=(const ContiguousDataMatrix<T>& m){
    if(m_allocated && m_width == m.m_width && m_height == m.m_height){
      for(i=0; i<m_width; i++){
	for(j=0; j<m_height; j++){
	  m_data[j+i*m_width] =m.m_data[j+i*m_width];
	}
      }
    }
    else{
      if(m_allocated){
	delete[] m_data;
	m_data =NULL;
	m_width =0;
	m_height =0;
	m_allocated =false;
      }

      m_data =new T[m.m_width * m.m_height];
      if(m_data){
	m_width =m.m_width;
	m_height =m.m_height;
	m_allocated =true;

	for(i=0; i<m_width; i++){
	  for(j=0; j<m_height; j++){
	    m_data[j+i*m_width] =m.m_data[j+i*m_width];
	  }
	}
      }
    }

    return *this;
  }

  ContiguousDataMatrix<T>& operator+(const ContiguousDataMatrix<T>& m){
    if(m_allocated && m_width == m.m_width && m_height == m.m_height){
      for(i=0; i<m_width; i++){
	for(j=0; j<m_height; j++){
	  m_data[j+i*m_width] =m_data[j+i*m_width] + m.m_data[j+i*m_width];
	}
      }
    }
    else{
      if(m_allocated){
	delete[] m_data;
	m_data =NULL;
	m_width =0;
	m_height =0;
	m_allocated =false;
      }

      m_data =new T[m.m_width * m.m_height];
      if(m_data){
	m_width =m.m_width;
	m_height =m.m_height;
	m_allocated =true;

	for(i=0; i<m_width; i++){
	  for(j=0; j<m_height; j++){
	    m_data[j+i*m_width] =m_data[j+i*m_width] + m.m_data[j+i*m_width];
	  }
	}
      }
    }

    return *this;
  }

  ContiguousDataMatrix<T>& operator-(const ContiguousDataMatrix<T>& m){
    if(m_allocated && m_width == m.m_width && m_height == m.m_height){
      for(i=0; i<m_width; i++){
	for(j=0; j<m_height; j++){
	  m_data[j+i*m_width] =m_data[j+i*m_width] - m.m_data[j+i*m_width];
	}
      }
    }
    else{
      if(m_allocated){
	delete[] m_data;
	m_data =NULL;
	m_width =0;
	m_height =0;
	m_allocated =false;
      }

      m_data =new T[m.m_width * m.m_height];
      if(m_data){
	m_width =m.m_width;
	m_height =m.m_height;
	m_allocated =true;

	for(i=0; i<m_width; i++){
	  for(j=0; j<m_height; j++){
	    m_data[j+i*m_width] =m_data[j+i*m_width] - m.m_data[j+i*m_width];
	  }
	}
      }
    }

    return *this;
  }
  
  template <class K>
  ContiguousDataMatrix<T>& operator*(K k){
    if(m_allocated){
      for(i=0; i<m_width; i++){
	for(j=0; j<m_height; j++){
	  m_data[j+i*m_width] = m_data[j+i*m_width] * k;
	}
      }
    }
    
    return *this;
  }

  template <class K>
  friend ContiguousDataMatrix<T>& operator*(K k, ContiguousDataMatrix<T>& m){    
    return m*k;
  }

  template <class K>
  ContiguousDataMatrix<T>& operator/(K k){
    if(m_allocated){
      for(i=0; i<m_width; i++){
	for(j=0; j<m_height; j++){
	  m_data[j+i*m_width] = m_data[j+i*m_width] / k;
	}
      }
    }
    
    return *this;
  }

  template <class K>
  friend ContiguousDataMatrix<T>& operator/(K k, ContiguousDataMatrix<T>& m){    
    return m/k;
  }

  friend std::ostream& operator<<(std::ostream& out, ContiguousDataMatrix<T>& m){
    if(m.isAllocated()){
      for(unsigned i=0; i<m.width(); i++){
	for(unsigned int j=0; j<m.height(); j++){
	  out << m.get(i,j);
	}
      }
    }

    return out;
  }

  inline bool isAllocated(){
    return m_allocated;
  }

  inline unsigned int width(){
    return m_width;
  }

  inline unsigned int height(){
    return m_height;
  }

  inline T& get(unsigned int i, unsigned int j){
    return m_data[j+i*m_width];
  }

  inline void set(unsigned int i, unsigned int j, const T& t){
    m_data[j+i*m_width] =t;
  }
};

#endif // MATRICE_H
