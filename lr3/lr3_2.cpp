#include <iostream>
#include <vector>

using namespace std;

class SquareStatic
{
protected:
    double a; // Длина стороны

public:
    SquareStatic(double a)
    {
        this->a = a;
    }

    double calculate()
    {
        return a * a;
    }

    void print()
    {
        cout << "Square: side = " << a
             << ", square = " << calculate() << endl;
    }
};

class CubeStatic : public SquareStatic
{
public:
    // Явный вызов конструктора базового класса
    CubeStatic(double a) : SquareStatic(a)
    {
    }

    double calculate()
    {
        // Площадь основания умножается на высоту
        return SquareStatic::calculate() * a;
    }

    void print()
    {
        cout << "Cube: side = " << a
             << ", volume = " << calculate() << endl;
    }
};

class Square
{
protected:
    double a;

public:
    Square(double a)
    {
        this->a = a;
    }

    virtual double calculate()
    {
        return a * a;
    }

    virtual void print()
    {
        cout << "Square: side = " << a
             << ", square = " << calculate() << endl;
    }

    virtual ~Square()
    {
    }
};

class Cube : public Square
{
public:
    Cube(double a) : Square(a)
    {
    }

    double calculate()
    {
        return Square::calculate() * a;
    }

    void print()
    {
        cout << "Cube: side = " << a
             << ", volume = " << calculate() << endl;
    }
};

int main()
{
    SquareStatic squareStatic(2); 
    CubeStatic cubeStatic(3);
    squareStatic.print();
    cubeStatic.print();
    SquareStatic *ps = &cubeStatic;
    ps->print();
    vector<SquareStatic *> staticObjects;
    staticObjects.push_back(&squareStatic);
    staticObjects.push_back(&cubeStatic);
    double staticSum = 0;
    for (int i = 0; i < 2; i++)
    {
        staticSum += staticObjects[i]->calculate();
    }
    cout << "Summ st = " << staticSum << endl;
    cout << "" << endl;

    
    Square square(2);
    Cube cube(3);
    square.print();
    cube.print();
    Square *pd = &cube;
    pd->print();
    vector<Square *> objects;
    objects.push_back(&square);
    objects.push_back(&cube);
    double sum = 0;
    for (int i = 0; i < 2; i++)
    {
        sum += objects[i]->calculate();
    }
    cout << "Summ din = " << sum << endl;
    return 0;
}