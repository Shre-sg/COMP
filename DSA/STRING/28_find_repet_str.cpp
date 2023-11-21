// Cpp program to find first repeated word in a string
#include<bits/stdc++.h>
using namespace std;


// Given a string, Find the 1st repeated word in a string

// Examples: 

// Input : "Ravi had been saying that he had been there"
// Output : had
// Input : "Ravi had been saying that"
// Output : No Repetition
// Input : "he had had he"
// Output : he



void solve(string s)
{
	unordered_map <string,int> mp; // to store occurrences of word
	string t="",ans="";
	// traversing from back makes sure that we get the word which repeats first as ans
	for(int i=s.length()-1;i>=0;i--)  //we are reading char by char in reverse
	{
		// if char present , then add that in temp word string t
		if(s[i]!=' ')
		{
			t+=s[i];   //t holds  if word is"he"  t= "eh"
			
		}
		// if space is there then this word t needs to stored in map 
		else
		{
			mp[t]++;  //if we encounter space we add t to mapp
			// if that string t has occurred previously then it is a possible ans
			if(mp[t]>1)
			    ans=t;
			// set t as empty for again new word 
			t="";	//t is agin reset
		}
	}
	
	// first word like "he" needs to be mapped
	mp[t]++;  //as loop breaks when ir reads last word its in t , ie it is manually again loaded
    if(mp[t]>1) // again ans is chechked 
		ans=t; 
						
	if(ans!="")
	{
		// reverse ans string as it has characters in reverse order
		reverse(ans.begin(),ans.end());  //as mapp holds word in reverse oder we do this
		cout<<ans<<'\n';
	}
	else
	cout<<"No Repetition\n";
}

int main()
{
	string u="Ravi had been saying that he had been there";
	string v="Ravi had been saying that";
	string w="he had had he";
	
    solve(u);
	solve(v);
	solve(w);
	
	return 0;
}
