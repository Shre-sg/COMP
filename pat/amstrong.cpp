#include<iostream>
using namespace std;

int main()
{
    int n, amg=0; 
    cin>>n;

    while(n>0){
        int lastdigi= n%10;
        amg= amg + lastdigi*lastdigi*lastdigi; 
        n=n/10;         // n ; ex 2345, amg_num= 2^3 + 3^# + 4^3 + 5^3; 
    }  

    cout<<amg<<endl;
}