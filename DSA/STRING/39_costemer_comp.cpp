#include<bits/stdc++.h> //OPTIONAL
#include<iostream>
#include<cstring>
#include <unordered_map>

using namespace std;


// Function to find Number of customers who could not get a computer

// Write a function “runCustomerSimulation” that takes following two inputs 

// An integer ‘n’: total number of computers in a cafe and a string: 
// A sequence of uppercase letters ‘seq’: Letters in the sequence occur in pairs. The first occurrence indicates the arrival of a customer; the second indicates the departure of that same customer. 
// A customer will be serviced if there is an unoccupied computer. No letter will occur more than two times. 
// Customers who leave without using a computer always depart before customers who are currently using the computers. There are at most 20 computers per cafe.

// For each set of input the function should output a number telling how many customers, if any walked away without using a computer. Return 0 if all the customers were able to use a computer.
// runCustomerSimulation (2, “ABBAJJKZKZ”) should return 0
// runCustomerSimulation (3, “GACCBDDBAGEE”) should return 1 as ‘D’ was not able to get any computer
// runCustomerSimulation (3, “GACCBGDDBAEE”) should return 0
// runCustomerSimulation (1, “ABCBCA”) should return 2 as ‘B’ and ‘C’ were not able to get any computer.
// runCustomerSimulation(1, “ABCBCADEED”) should return 3 as ‘B’, ‘C’ and ‘E’ were not able to get any computer.



int runCustomerSimulation (int max_PCs,string str)
{
	int n=str.length(),occupied=0;
	int key,value;
	int frequency=1,ans_count=0;
	
	//store the characters in hash map on the go
	unordered_map<char,int> m;
	
	  //chalte chalte values insert karo map me
    for(int i=0;i<n;i++)
    {
    	key=str[i];
    	value=frequency;   //frequency is always at most 2 as per given in question
    	
    	// if map is empty or Key is not present, insert key and the value and occuppied mark karo
    	if (m.find(key)==m.end())
    	{
    		//pair(mapping) bnaye
    		m[key]++;
    		occupied++;
    		
    		//agar computer bache hi nhi to..
    		if(occupied>max_PCs)
    		{
    			ans_count++;
			}
    		
		}
		// Key is already present to matlab customer ab bahar jaa raha hai to PC khaali karo
		else if(m.find(key)!=m.end())
		{
			occupied--;
		}
	}
	
	return ans_count++;
	
}

int main()
{
	string str="ABCBCADEED";
	int max_PCs=1;
	
	cout<<"\nNumber of customers who didn't get any PC => "<<runCustomerSimulation(max_PCs,str);
	
return 0;
}