//https://www.geeksforgeeks.org/union-find-algorithm-set-2-union-by-rank/
#include<iostream>
#include<algorithm>
using namespace std;


class Edge{
    public:
        int src;
        int dest;
        int weight;

};

class Set {
    public :
        int rank;
        int parent;

};

int find(Set *set,int i){
    
    if(set[i].parent!=i){
          set[i].parent=find(set,set[i].parent);  
    }


    return set[i].parent;

}

void Union (Set *set,int v1,int v2){

    int v1_root=find(set,v1);
    int v2_root=find(set,v2);
    if(set[v1_root].rank<set[v2_root].rank){
        set[v1_root].parent=v2_root;
    }
    else if(set[v1_root].rank>set[v2_root].rank){
        set[v2_root].parent=v1_root;
    }
    else{
        set[v2_root].parent=v1_root;
        set[v1_root].rank++;
    }

}


bool cmp(Edge e1,Edge e2){
    return e1.weight<e2.weight;
}

void Kruskals(Edge *input,int n,int e){
        // sort the input array on the basis of weights of the edges..
        sort(input,input+e,cmp);
        Edge *output=new Edge[n-1]; //initialised an output array...
        Set *set=new Set[n]; // initialised the sets for all vertices..
        for(int i=0;i<n;i++){
            set[i].rank=0; //assign the rank initially as 0
            set[i].parent=i; // assigned the parent of all vertices that are initially in their  individual set as the vertex only..
        }
        int counter=0,i=0;
        while(counter<n-1){
            Edge currentEdge=input[i]; // we have taken the edge with minimum weight..
            int sourceParent=find(set,currentEdge.src); // found the parent of source vertex..
            int destinationParent=find(set,currentEdge.dest); // found the parent of destination vertex..
            if(sourceParent!=destinationParent){ // checked if both lies in the same set or not..
                output[counter]=currentEdge; //we will insert the edge in mst
                Union(set,sourceParent,destinationParent); // then we will union the set of the source and dest vertex..
                counter++; //increase the counter..
            }
            i++;
        }

       // for(int m=0;m<n-1;m++){
           // cout<<output[m].src<<"--"<<output[m].dest<<"with weight "<<output[m].weight<<endl;
       // }
        int totalWeight=0;
        for(int m=0;m<n-1;m++){

            totalWeight+=output[m].weight;
        }
        cout<<totalWeight<<endl;
}


int main(){

    int n,e;
    cin>>n>>e;
    Edge *input=new Edge[e];
    for(int i=0;i<e;i++)
    {
        int s,d,w;
        cin>>s>>d>>w;
        input[i].src=s;
        input[i].dest=d;
        input[i].weight=w;

    }

    Kruskals(input,n,e);
    return 0;
}

/*
7
8
0 3 4
0 1 6
1 2 5
3 2 7
3 4 2
4 5 4
5 6 1
4 6 3

*/