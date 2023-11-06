#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;

    int reverse=0, lastdig=0;
    while(n>0)
    {   
        lastdig=n%10;   ////to get the last digi of input number
        reverse=reverse*10 + lastdig;  //ex: 4 init; 40+3; 43; 430 +lastdigi soon on
        n=n/10;  //to continue the loop
    }

    cout<<reverse<<endl;
}