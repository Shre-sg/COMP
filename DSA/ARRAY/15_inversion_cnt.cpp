#include <iostream>
#include <vector>

using namespace std;


// Given an array of integers. Find the Inversion Count in the array. 

// Inversion Count: For an array, inversion count indicates how far (or close) the array is from 
//being sorted. If the array is already sorted then the inversion count is 0.
// If an array is sorted in the reverse order then the inversion count is the maximum. 
// Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.
 

// Example 1:
// Input: N = 5, arr[] = {2, 4, 1, 3, 5}
// Output: 3
// Explanation: The sequence 2, 4, 1, 3, 5 
// has three inversions (2, 1), (4, 1), (4, 3).

// Example 2:
// Input: N = 5
// arr[] = {2, 3, 4, 5, 6}
// Output: 0
// Explanation: As the sequence is already 
// sorted so there is no inversion count.

// Example 3:
// Input: N = 3, arr[] = {10, 10, 10}
// Output: 0
// Explanation: As all the elements of array 
// are same, so there is no inversion count.

//https://youtu.be/AseUmwVNaoY?si=Jas1plhphoTJJ3sK


class Solution {
public:
    void merge(long long arr[], long long n, long long l, long long h, long long mid, long long int &count) {
        long long i = l;
        long long j = mid+1;  //rember this mid is point to ennding of first array
        vector<long long>v;
        
        while(i <= mid && j <= h) {
            if(arr[i]<=arr[j]) {
                v.push_back(arr[i]);
                i++;
            }
            else {
                count += mid-i+1;   //count =count + ((mid+1)-i); as mid is pointing to last oif array 1
                v.push_back(arr[j]);//else count =count + (mid-i); mid is pointing to start of second array 
                j++;                //explain take you forward
            }
        }
        
        while(i<=mid) {
            v.push_back(arr[i]);
            i++;
        }
        while(j<=h) {
            v.push_back(arr[j]);
            j++;
        }
        
        long long k = l;
        for(long long l = 0; l<v.size() ; l++) {
            arr[k++] = v[l];
        }
    }
    
    void merge_sort(long long arr[], long long n, long long l, long long h, long long int &count) {
        if(l<h) {
            int mid = (l+h)/2;
            merge_sort(arr,n,l,mid,count);
            merge_sort(arr,n,mid+1,h,count);
            merge(arr,n,l,h,mid,count);
        }
    }
    
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        long long int count = 0;
        
        merge_sort(arr,N,0,N-1,count);
        
        return count;
    }
};

int main() {
    long long arr[] = { 1, 20, 6, 4, 5 };
    long long N = sizeof(arr) / sizeof(arr[0]);
    Solution sol;
    long long int count = sol.inversionCount(arr, N);
    cout << "Number of inversions: " << count << endl;
    return 0;
}
