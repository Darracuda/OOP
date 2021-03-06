// OOP, Lab 2 variant 9, Diana Kolpakova
// Triangle, TLinkedList

#include <iostream>

#include "figure.h"
#include "triangle.h"
#include "tlinkedlist.h"

using namespace std;

int main()
{
    cout.setf(ios_base::boolalpha);
    cout << "oop_exercise_2 (c) Diana Kolpakova" << endl;
    cout << "Triangles, TLinkedList" << endl;

    TLinkedList list = TLinkedList();

    for (;;)
    {
        cout << endl;
        cout << "Select an action for the linked list of triangles" << endl;
        cout << "1) Is the list empty?" << endl;
        cout << "2) Get number of triangles in the list" << endl;
        cout << "3) Show the first triangle from the list" << endl;
        cout << "4) Show the last triangle from the list" << endl;
        cout << "5) Show the triangle at a specified position in the list" << endl;
        cout << "6) Show areas of all triangles in the list" << endl;
        cout << "7) Add a new triangle to the beginning of the list" << endl;
        cout << "8) Add a new triangle to the end of the list" << endl;
        cout << "9) Add a new triangle to a specified position in the list" << endl;
        cout << "a) Remove the new first triangle from the list" << endl;
        cout << "b) Remove the new last triangle from the list" << endl;
        cout << "c) Remove the triangle at a specified position in the list" << endl;
        cout << "d) Remove all triangles from the list" << endl;
        cout << "x) End the program" << endl;

        try
        {
            Triangle triangle;
            size_t position;

            char ch;
            cin >> ch;
            switch (ch)
            {
                case '1':
                    cout << "Is the list empty: " << list.Empty() << endl;
                    break;
                case '2':
                    cout << "Length of the list: " << list.Length() << endl;
                    break;
                case '3':
                    triangle = list.First();
                    cout << triangle << endl;
                    break;
                case '4':
                    triangle = list.Last();
                    cout << triangle << endl;
                    break;
                case '5':
                    cout << "Enter position in the list:";
                    cin >> position;
                    triangle = list.GetItem(position);
                    cout << triangle << endl;
                    break;
                case '6':
                    cout << "Triangle areas:" << endl;
                    if (list.Empty())
                    {
                        cout << "Empty list" << endl;
                    }
                    else
                    {
                        cout << list << endl;
                    }
                    break;
                case '7':
                    cout << "Enter 3 points of triangle (6 numbers):";
                    cin >> triangle;
                    list.InsertFirst(triangle);
                    cout << triangle << endl;
                    break;
                case '8':
                    cout << "Enter 3 points of triangle (6 numbers):";
                    cin >> triangle;
                    list.InsertLast(triangle);
                    cout << triangle << endl;
                    break;
                case '9':
                    cout << "Enter 3 points of triangle (6 numbers):";
                    cin >> triangle;
                    cout << "Enter position in the list:";
                    cin >> position;
                    list.Insert(triangle, position);
                    cout << triangle << endl;
                    break;
                case 'a':
                case 'A':
                    list.RemoveFirst();
                    cout << "Removed the first triangle" << endl;
                    break;
                case 'b':
                case 'B':
                    list.RemoveLast();
                    cout << "Removed the last triangle" << endl;
                    break;
                case 'c':
                case 'C':
                    cout << "Enter position in the list:";
                    cin >> position;
                    list.Remove(position);
                    cout << "Removed the triangle at specified position" << endl;
                    break;
                case 'd':
                case 'D':
                    list.Clear();
                    cout << "Removed all" << endl;
                    break;
                case 'l':
                case 'L':
                    cout << "Triangles:" << endl;
                    if (list.Empty())
                    {
                        cout << "Empty list" << endl;
                    }
                    else
                    {
                        for (size_t i = 0; i < list.Length(); i++)
                        {
                            triangle = list.GetItem(i);
                            cout << "#" << i << " " << triangle << endl;
                        }
                    }
                    break;
                case 'q':
                case 'Q':
                case 'x':
                case 'X':
                    cout << "Exiting" << endl;
                    return 0;
                default:
                    cout << "Error: invalid action selected" << endl;
                    break;
            }
        }
        catch (exception& ex)
        {
            cout << "Exception: " << ex.what() << endl;
        }
    }
}
