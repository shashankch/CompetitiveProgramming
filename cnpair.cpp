#include <iostream>
using namespace std;

template <typename T, typename V>
class Pair
{

    T x;
    V y;

public:
    void setX(T x)
    {
        this->x = x;
    }

    T getX()
    {
        return x;
    }

    void setY(V y)
    {
        this->y = y;
    }

    V getY()
    {
        return y;
    }
};

int main()
{

    // Pair<int, double> p1;
    // p1.setX(10);
    // p1.setY(20.0);
    // Pair<double, int> p2;
    // p2.setX(10.0);

    Pair<Pair<int, int>, int> p2;
    Pair<int, int> p3;
    p2.setX(p3);
    p2.setY(39);

    cout << p2.getX().getX() << p2.getX().getY();

    return 0;
}
