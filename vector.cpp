#include <bits/stdc++.h>
using namespace std;

//Let us define a Vector Class(User defined Vector)
class Vector
{
    //Data Members and some functions
    int *arr;
    int cs;
    int maxSize;

public:
    Vector(int defaultSize = 4)
    {
        maxSize = defaultSize;
        cs = 0;
        arr = new int[maxSize];
    }

    void push_back(int data)
    {
        if (cs == maxSize)
        {
            //Doubling Operations
            int *oldArr = arr;
            arr = new int[2 * maxSize];
            maxSize = 2 * maxSize;

            for (int i = 0; i < cs; i++)
            {
                arr[i] = oldArr[i];
            }
            //Delete the oldArr
            delete[] oldArr;
        }
        arr[cs] = data;
        cs++;
    }
    bool empty()
    {
        return cs == 0;
    }
    int getSize()
    {
        return cs;
    }
    int getMaxSize()
    {
        return maxSize;
    }
    void pop_back()
    {
        if (!empty())
        {
            cs--;
        }
    }
    void print()
    {
        for (int i = 0; i < cs; i++)
        {
            cout << arr[i] << ",";
        }
    }
    int at(int i)
    {
        return arr[i];
    }
    int &operator[](int i)
    {

        return arr[i];
    }

    void operator()(string s)
    {

        cout << s;
    }
};

/// these ostream and istream are classes for input and output and cin and cout are special objects
/// of these classes.overloading of these can be done outside class as global functions.
/// otherwise we have to make changes in the header files of these classes.
/// can be done inside class if case: v>>cin something like this..
/// return type is ostream for cascading to work so it returns cin or cout.. for eg.cout<<he<<pe;
ostream &operator<<(ostream &os, Vector &v)
{

    v.print();
    return;
}
void operator>>(istream &is, Vector &v)
{
}
int main()
{
    Vector v(1000);
    v("hello"); ///
    vector fun;
    fun("bye"); /// looking like function but it is an object (functor:functional objects)
    for (int i = 0; i <= 3; i++)
    {
        v.push_back(i * i);
    }
    cout << v.getMaxSize() << endl;
    v.push_back(7);
    cout << v.getMaxSize() << endl;
    v.print();

    return 0;
}
