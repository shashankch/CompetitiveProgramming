

#include<iostream>
#include<cstring>
using namespace std;


void rotate(char *a,int k){

    int i=strlen(a);   ///here strlen or length returns no.of character in the string not null character
    ///size is 5 not 6
    ///sizeof in char array returns length including null char..here size is 6
    cout<<i;
    while(i>=0){
        a[i+k]=a[i];
        i--;
    }

    i=strlen(a); ///now length is 7
    int j=i-k; /// 5
    int s=0;
    while(j<i){

        a[s]=a[j];
        s++;
        j++;
    }

a[i-k]='\0'; ///index 5..
}




int main(){

char a[100]="hello";
int k=2;
rotate(a,k);
cout<<a;

return 0;
}
