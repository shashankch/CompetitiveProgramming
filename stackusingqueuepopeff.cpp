
#include<iostream>
#include<queue>
using namespace std;

class stack{

    queue<int>a,b;


    int curr_size;

public :
    stack(){

    curr_size=0;

    }

    void pop(){


       if(!a.empty()){
        a.pop();

        curr_size--;
       }
    }

    void push(int data){


        curr_size++;

        b.push(data);

        while(!a.empty()){

            b.push(a.front());
            a.pop();

        }
     swap(a,b);



    }

    int top(){


        if(!a.empty()){


            return a.front();
        }


    }


};


int main(){


    stack s;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        s.push(i);
    }

    for(int i=0;i<n;i++){

        cout<<s.top()<<" ";
        s.pop();


    }



return 0;
}
