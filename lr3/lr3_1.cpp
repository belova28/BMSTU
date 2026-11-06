#include "Vector.h"
#include <fstream>

using namespace std;

Vector::Vector() {
  p = nullptr;
  n = 0;
}

Vector::Vector(double *arr, int n) {
  this->n = n;
  p = new double[n];
  for (int i = 0; i < n; i++) {
    p[i] = arr[i];
  }
}

Vector::Vector(int n) {
  this->n = n;
  p = new double[n];
}

Vector::Vector(const Vector &v) // Констp. копирования
{
  n = v.n;
  p = new double[n];
  for (int i = 0; i < n; i++) {
    p[i] = v.p[i];
  }
}

Vector::Vector(Vector &&v) // Констp. перемещения
{
  p = v.p;
  n = v.n;
  v.p = nullptr;
  v.n = 0;
}

Vector::~Vector() {
  if (p != nullptr)
    delete[] p;
}

double &Vector::operator[](int index) { return p[index]; }

Vector &Vector::operator=(const Vector &v) // Присв. с копированием
{
  if (p != nullptr)
    delete[] p;
  n = v.n;
  p = new double[n];
  for (int i = 0; i < n; i++) {
    p[i] = v.p[i];
  }
  return *this;
}

Vector &Vector::operator=(Vector &&v) // Присв. с перемещением
{
  if (this != &v) {
    std::swap(p, v.p);
    std::swap(n, v.n);
  }
  return *this;
}

int Vector::size() const { return n; }

Vector operator+(double *arr, const Vector &v) {
  int len = v.n;
  Vector result(2 * len);
  for (int i = 0; i < len; i++) {
    result.p[i] = arr[i];
  }
  for (int i = 0; i < len; i++) {
    result.p[len + i] = v.p[i];
  }
  return result;
}

ostream &operator<<(ostream &out, const Vector &v) // Вывод вектора в поток
{
  for (int i = 0; i < v.n; i++) {
    out << v.p[i] << " ";
  }
  return out;
}

istream &operator>>(istream &in, Vector &v) // Ввод вектора из потока
{
  in >> v.n;
  if (v.p != nullptr)
    delete[] v.p;
  v.p = new double[v.n];
  for (int i = 0; i < v.n; i++) {
    in >> v.p[i];
  }
  return in;
}

int main() {
  ifstream fin("input.txt");
  ofstream fout("output.txt");
  int n;
  fin >> n;
  double *arr = new double[n];
  for (int i = 0; i < n; i++)
    fin >> arr[i];
  Vector v1(arr, n);
  fin >> v1;

  Vector v2 = arr + v1; // Перегруженная операция +
  for (int i = 0; i < n; i++)
    fout << arr[i] << " ";
  fout << endl;
  fout << "v1:" << v1 << endl;
  fout << "arr + v1:" << v2 << endl;

  Vector v3; // Копирование
  v3 = v1;
  fout << "v1 in v3:" << v3 << endl;

  Vector v4; // Перемещение
  v4 = arr + v1;
  fout << "Moving in v4:" << v4 << endl;

  v2[0] = 100; // по индексу
  fout << "v2[0] = 100:" << endl << v2 << endl;
  delete[] arr;
  fin.close();
  fout.close();
  return 0;
}
