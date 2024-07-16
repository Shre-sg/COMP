#include<iostream>
#include<climits>
using namespace std;

//case 1 :: noraml  to find max of subarry using kadene algo
//{-1,4,-6,7,5,-4} === max 12

//case 2 if its circular ex
//{4,-4,6,-6,10,-11,12} ===max 22 
//to do this, we need to remove element which we should not include inour arry

// max of subarr sum = total sum of array - sum of non contributing ele;
// sum of non contibuting subarry = make arr ele change its sign then call kidane algo
// kadane(-arr[n])


int kadane(int arr[], int n){
     int Maxsm=INT_MIN;
     int currsum=0;
     for(int i=0; i<n; i++){
        currsum=currsum+arr[i];
        if(currsum<0){
            currsum=0;
        }
        Maxsm=max(Maxsm,currsum);  
     }
     return Maxsm;
}

int main(){
    
    int n;
    cin>>n;
    int arr[n]; 

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int wrapsum, nonwrapsum;

    nonwrapsum=kadane(arr,n);  //normal max sum of sub arry


    //now we do to find out the max sum of circular subaray

    //to find total sum and changeing sings
    int totalsum=0;
    for(int i=0; i<n; i++){
        totalsum=totalsum+arr[i];
        arr[i]=-arr[i];
    }


     //max of subarr sum = total sum of array - (- sum of non contributing ele);

    wrapsum = totalsum + kadane(arr, n); //this kadae will give ele which should not be in the sum ie most -ve number
    cout<<max(wrapsum, nonwrapsum)<<endl;
}   

//example
// 7
// 4 -4 6 -6 10 -11 12
// 22