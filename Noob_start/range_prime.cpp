#include<iostream>
using namespace std;
int main()
{
    int l,u;
    cin>>l>>u;

    int num,i;
    for(num=l;num<=u;num++) //start at l to n i am going one ny one checking to print or not
    {
        for(i=2;i<num;i++)   
        {
            if(num%i==0)  //dive from 2 to num n; i am checking by dividing each number
            break;
        }

        if(i==num)
        cout<<num<<endl;
    }

    return 0;
}


///switch works the same
