
#include <iostream>
#include <stack>

using namespace std;

class queue
{

   stack<int> a, b;

public:
   void enqueue(int data)
   {

      a.push(data);
   }

   int dequeue()
   { ///enqueue efficient operation ---->>> O(1) and dequeue operation ---->>> O(n) times

      if (b.empty())
      {

         while (!a.empty())
         {

            b.push(a.top());
            a.pop();
         }
      }

      int x = b.top();
      b.pop();

      return x;
   }
};

int main()
{

   int n;
   cin >> n;
   queue q;

   for (int i = 0; i < n; i++)
   {
      q.enqueue(i);
   }
   for (int i = 0; i < n; i++)
   {

      // cout<<q.top()<<" ";
      cout << q.dequeue() << " ";
   }

   return 0;
}
