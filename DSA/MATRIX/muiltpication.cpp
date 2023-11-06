#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    
    int n1,n2,n3;
    cin>>n1>>n2>>n3;

    int a[n1][n2], b[n2][n3];  //n1 row of mat1 & n2 is col of mat1 
                                 //n2 row of mat1 & n3 is col of mat1 

    for(int i=0; i<n1;i++){        //input for mat1
        for(int j=0; j<n2; j++)
            cin>>a[i][j];
    }

    for(int i=0; i<n2;i++){       //input for mat2
        for(int j=0; j<n3; j++)
            cin>>b[i][j];
    }

    int ans[n1][n3];
     for(int i=0; i<n1;i++){       //init ans mat to 0
        for(int j=0; j<n3; j++)
            ans[i][j]=0;
    }

    for(int i=0;i<n1;i++)
    {
        for(int j=0; j<n3; j++){
            for(int k=0; k<n2; k++) //k< n2 row of mat and mat2 are always equal 
            {                           //k iter thru col of mat1 and row of mat2 as they mul and addd
                ans[i][j]+=a[i][k]*b[k][j];   //main cal
            }    
        }
    }

    for(int i=0; i<n1;i++){        // printing all the ans mat
        for(int j=0; j<n3; j++)
            cout<<ans[i][j]<<" ";
        cout<<"\n";
    }
        
}