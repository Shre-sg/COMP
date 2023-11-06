#include<iostream>
using namespace std;
int main()
{
    int i,n,j;
    cin>>n;

    // for(i=n;i>=1;i--)
    // {
    //     for(j=1;j<=i;j++)     // ****
    //     {                     // ***
    //         cout<<"*";        // **
    //     }                     // *
    //     cout<<endl;
    // }



    // for(i=1;i<n;i++)
    // {
    //     for(j=1;j<=n;j++)
    //     {
    //         if(j<=n-i)               //    *
    //         cout<<" ";              //    **
    //         else                    //   ***
    //         cout<<"*";              //  ****
    //     }
    //     cout<<endl;
    // }


    // for(i=1;i<=n;i++)
    // {
    //     for(j=1;j<=i;j++)          //1
    //     {                          //22
    //        cout<<i;                //333
    //     }                          //4444
    //     cout<<endl;
    // }

    
    // int count=1;
    //  for(i=1;i<=n;i++)
    // {
    //     for(j=1;j<=i;j++)          //1
    //     {                          //23
    //        cout<<count++;          //4567
    //     }                          //891011
    //     cout<<endl;
    // }

    // for(int i=n; i>=1; i--)
    // {
    //     for(int j=1; j<=i; j++)        //1234
    //       cout<<j;                     //123
    //                                    //12
    //     cout<<endl;                    //1
    // }


      for(int i=1; i<=n; i++)
    {                                       //i+j even thn print 1
        for(int j=1; j<=i; j++)       
        {
            if((i+j)%2==0)                  //1
            {                               //01
                cout<<"1";                  //101
            }                               //0101
            else{
                cout<<"0";
            }
        }                       
                                      
        cout<<endl;                   
    }


    return 0;
}
