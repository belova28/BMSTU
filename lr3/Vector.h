#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
using namespace std;

class Vector {
private:
  double *p;
  int n;

public:
  Vector();
  Vector(double *arr, int n);
  Vector(int n);
  Vector(const Vector &v); // Констp. копирования
  Vector(Vector &&v);      // Констp. перемещения
  ~Vector();

  int size() const;

  double &operator[](int index);
  Vector &operator=(const Vector &v); // Присв. с копированием
  Vector &operator=(Vector &&v);      // Присв. с перемещением

  friend Vector operator+(double *arr, const Vector &v);
  friend ostream &operator<<(ostream &out,
                             const Vector &v); // Вставка объекта в поток
  friend istream &operator>>(istream &in,
                             Vector &v); // Извлечение объекта из потока
};
#endif