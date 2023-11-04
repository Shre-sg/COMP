#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;


    int count=1;
    for(int i=n; i>=1; i--)
    {
        for (int j=1; j<=i-1; j++)
        {
            cout<<" ";
        }                                           //----1
                                                    //---1 2
                                                    //--1 2 3
        for(int k=1; k<=count; k++)                 //-1 2 3 4 
        {                                           //1 2 3 4 5 
            cout<<" "<< k;
        
        }
        count++;
        cout<<endl;
    }
}
