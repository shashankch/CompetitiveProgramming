

#include<iostream>
#include<vector>

using namespace std;

template<typename T>
class stack{

private:
    vector<T> v;
    T currmin;

public :
            /// if data is greater than currmin then push data else set currmin=data
            /// and push 2*data-currmin value.
    void push(T data){

        if(empty()){
            currmin=data;
            v.push_back(data);
        }
        else if(data>=currmin){
        v.push_back(data);}
        else{
            currmin=data;
            v.push_back((2*data)-currmin);
        }

    }

    void pop(){

    /// if y is greater than equal to currmin simply pop..else update currmin=(2*currmin-y) and pop the stack value...
         int y=v[v.size()-1];
            if(y>=currmin){
                 v.pop_back();
            }
            else if(y<currmin){
                    currmin=(2*currmin)-y;
                v.pop_back();

            }



    }

    T  top(){

        return v[v.size()-1];



    }
    bool empty(){

    return v.size()==0;

    }

    T getmin(){

    return currmin;
    }






};


int main(){
stack<int> s;
s.push(3);
s.push(5);
cout<<s.getmin();
s.push(2);
s.push(1);
cout<<s.getmin();
s.pop();
cout<<s.getmin();
s.pop();
cout<<s.getmin();

//while(!s.empty()){
   // cout<<s.top()<<" ";
    //s.pop();
//}
return 0;
}


