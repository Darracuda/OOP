// OOP, Lab 1, variant 9, Diana Kolpakova
// Figure, Triangle, Square, Rectangle

#include <iostream>
#include <vector>

#include "figure.h"
#include "triangle.h"
#include "square.h"
#include "rectangle.h"

using namespace std;

int main()
{
    cout << "oop_exercise_1 (c) Diana Kolpakova" << endl;
    vector<Figure*> figures;

    cout << "Enter triangle points:";
    Triangle triangle1(cin);
    triangle1.Print(cout);
    cout << "Number of points: " << triangle1.VertexesNumber() << endl;
    cout << "Area:" << triangle1.Area() << endl;
    figures.push_back(&triangle1);

    cout << "Enter rectangle points:";
    Rectangle rectangle1(cin);
    rectangle1.Print(cout);
    cout << "Number of points: " << rectangle1.VertexesNumber() << endl;
    cout << "Area:" << rectangle1.Area() << endl;
    figures.push_back(&rectangle1);

    cout << "Enter square points:";
    Square square1(cin);
    square1.Print(cout);
    cout << "Number of points: " << square1.VertexesNumber() << endl;
    cout << "Area:" << square1.Area() << endl;
    figures.push_back(&square1);

    cout << "Enter rectangle points:";
    Rectangle rectangle2(cin);
    rectangle2.Print(cout);
    cout << "Number of points: " << rectangle2.VertexesNumber() << endl;
    cout << "Area:" << rectangle2.Area() << endl;
    figures.push_back(&rectangle2);

    cout << "Figures in container:" << endl;
    for (int i = 0; i < figures.size(); i++)
    {
        figures[i]->Print(cout);
    }
}
