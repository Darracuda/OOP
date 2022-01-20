// OOP, Lab 6 variant 9, Diana Kolpakova
// Triangle, TLinkedList, allocator in TVector

#include <iostream>

#include "triangle.h"
#include "tlinkedlist.h"
#include "titterator.h"
#include "tvector.h"

using namespace std;

int main()
{
    cout.setf(ios_base::boolalpha);
    cout << "oop_exercise_6 (c) Diana Kolpakova" << endl;
    cout << "Triangles, TLinkedList, allocator in TVector" << endl;

    //test vector
    TVector<int> v;
    size_t l = v.Length();
    v.InsertLast(0);
    v.InsertLast(1);
    v.InsertLast(2);
    v.InsertLast(3);
    v.InsertLast(4);
    v.InsertLast(5);
    v.InsertLast(6);
    v.InsertLast(7);
    v.InsertLast(8);
    v.InsertLast(9);
    int p9 = v.Last();
    int p0 = v[0];
    v[3] = 33;
    int p3 = v[3];
    size_t b7 = v.Find(7);
    size_t b77 = v.Find(77);
    int done = 0;
    // test done;

    shared_ptr<TLinkedList<Triangle>> pList(new TLinkedList<Triangle>());

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
        cout << "a) Remove the first triangle from the list" << endl;
        cout << "b) Remove the last triangle from the list" << endl;
        cout << "c) Remove the triangle at a specified position in the list" << endl;
        cout << "d) Remove all triangles from the list" << endl;
        cout << "l) Show all triangles from the list" << endl;
        cout << "x) End the program" << endl;

        try
        {
            shared_ptr<Triangle> pTriangle;
            size_t position;

            char ch;
            cin >> ch;
            switch (ch)
            {
                case '1':
                    cout << "Is the list empty: " << pList->Empty() << endl;
                    break;
                case '2':
                    cout << "Length of the list: " << pList->Length() << endl;
                    break;
                case '3':
                    pTriangle = pList->First();
                    cout << *pTriangle << endl;
                    break;
                case '4':
                    pTriangle = pList->Last();
                    cout << *pTriangle << endl;
                    break;
                case '5':
                    cout << "Enter position in the list:";
                    cin >> position;
                    pTriangle = pList->GetItem(position);
                    cout << *pTriangle << endl;
                    break;
                case '6':
                    cout << "Triangle areas:" << endl;
                    if (pList->Empty())
                    {
                        cout << "Empty list" << endl;
                    }
                    else
                    {
                        cout << *pList << endl;
                    }
                    break;
                case '7':
                    pTriangle = shared_ptr<Triangle>(new Triangle());
                    cout << "Enter 3 points of triangle (6 numbers):";
                    cin >> *(pTriangle);
                    pList->InsertFirst(pTriangle);
                    cout << *pTriangle << endl;
                    break;
                case '8':
                    pTriangle = shared_ptr<Triangle>(new Triangle());
                    cout << "Enter 3 points of triangle (6 numbers):";
                    cin >> *(pTriangle);
                    pList->InsertLast(pTriangle);
                    cout << *pTriangle << endl;
                    break;
                case '9':
                    pTriangle = shared_ptr<Triangle>(new Triangle());
                    cout << "Enter 3 points of triangle (6 numbers):";
                    cin >> *(pTriangle);
                    cout << "Enter position in the list:";
                    cin >> position;
                    pList->Insert(pTriangle, position);
                    cout << *pTriangle << endl;
                    break;
                case 'a':
                case 'A':
                    pList->RemoveFirst();
                    cout << "Removed the first triangle" << endl;
                    break;
                case 'b':
                case 'B':
                    pList->RemoveLast();
                    cout << "Removed the last triangle" << endl;
                    break;
                case 'c':
                case 'C':
                    cout << "Enter position in the list:";
                    cin >> position;
                    pList->Remove(position);
                    cout << "Removed the triangle at specified position" << endl;
                    break;
                case 'd':
                case 'D':
                    pList->Clear();
                    cout << "Removed all" << endl;
                    break;
                case 'l':
                case 'L':
                    cout << "Triangles:" << endl;
                    if (pList->Empty())
                    {
                        cout << "Empty list" << endl;
                    }
                    else
                    {
                        for (auto pItem : *pList)
                        {
                            std::cout << *pItem << std::endl;
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
