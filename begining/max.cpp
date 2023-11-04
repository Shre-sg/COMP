#include<iostream>
using namespace std;

int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    if(a>b){
        if(a>c){
            cout<<"a is greater"<<endl;    
        }
        else {
            cout<<"c is greater"<<endl;
        }
    }
    else {
    cout<<"b is greater"<<endl;
    }
    return 0;
}

//for( ; ; ){} is same
//while(){} is same