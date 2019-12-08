
#include<iostream>
#include<queue>
using namespace std;


class stackusingqueue{


    queue <int>*a,*b;

public:

    stackusingqueue(){

        a=new queue<int>();
        b=new queue<int>();



    }

    void push(int data){


        a->push(data);
    }

    void pop(){


    /// create two queue insert all n-1 element from front to back of the other queue..
    /// create now pop the the last element in the first queue and swap back element back to queue b..


        int n=a->size();
        for(int i=0;i<n-1;i++){

            b->push(a->front());
            a->pop();

        }
        if(!a->empty()){
            a->pop();
            swap(a,b); //keeping b always empty...
        }
    }

    bool empty(){

        return a->size()==0;


    }
    int top(){
        /// here in top follow the same procedure as pop() bt store last element and then insert all elements in b and then swap to b to a queue.

        int n=a->size();
        for(int i=0;i<n-1;i++){

            b->push(a->front());
            a->pop();

        }
        int topelement=a->front();

        if(!a->empty()){
            b->push(a->front());
            a->pop();
            swap(a,b); //keeping b always empty...
        }





    return topelement;

    }





};













int main(){

    stackusingqueue s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    cout<<s.top();
    s.push(10);
    s.pop();
    s.pop();
    cout<<s.top();


return 0;
}
