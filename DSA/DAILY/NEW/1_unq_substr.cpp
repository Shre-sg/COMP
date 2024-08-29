#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

// You have a string of length n and given q queries. In each query, you will be given a length k and you have to find the first index of a special substring of length k.  A special substring is a substring which hasn’t repeated itself.

// The problem you've described resembles a type of string problem that could be related to finding unique substrings within a larger string, particularly in competitive programming. It is likely inspired by problems that focus on substring uniqueness and handling multiple queries efficiently.

// However, based on your description, the problem closely aligns with a well-known problem called "Finding the First Unique Substring of Given Length in a String". This is not a standard problem from well-known coding platforms but is a variant that could be asked in coding interviews or competitive programming contests.

// Example:
// Given String: "abacabad"

// Queries:

// k = 2
// k = 3
// k = 4
// Objective: For each query, find the first index of a special substring of length k. A special substring is a substring that does not repeat anywhere else in the string.

// Step-by-Step Explanation:
// Query 1: k = 2

// All substrings of length 2:
// "ab" (index 0)
// "ba" (index 1)
// "ac" (index 2)
// "ca" (index 3)
// "ab" (index 4)
// "ba" (index 5)
// "ad" (index 6)
// Substrings that do not repeat: "ac", "ca", "ad"
// First index: The first special substring is "ac" at index 2.
// Query 2: k = 3

// All substrings of length 3:
// "aba" (index 0)
// "bac" (index 1)
// "aca" (index 2)
// "cab" (index 3)
// "aba" (index 4)
// "bad" (index 5)
// Substrings that do not repeat: "bac", "aca", "cab", "bad"
// First index: The first special substring is "bac" at index 1.
// Query 3: k = 4

// All substrings of length 4:
// "abac" (index 0)
// "baca" (index 1)
// "acab" (index 2)
// "caba" (index 3)
// "abad" (index 4)
// Substrings that do not repeat: All the substrings are unique in this case.
// First index: The first special substring is "abac" at index 0.
// Summary of Results:
// For k = 2: First special substring starts at index 2 ("ac").
// For k = 3: First special substring starts at index 1 ("bac").
// For k = 4: First special substring starts at index 0 ("abac").
// This example demonstrates how to identify the first unique substring for different values of k. The process involves generating all possible substrings of a given length, checking for their uniqueness, and then determining the first occurrence.

// Problem Breakdown:
// Input:
// A string of length n.
// q queries, each with a length k.
// Output:
// For each query, find the first index of a special substring of length k in the given string. A special substring is defined as one that has not repeated itself in the string.

// Function to find the first index of a unique substring of length k
int findFirstUniqueSubstring(const string &s, int k)
{
    unordered_map<string, int> substringCount;  // Map to store the count of each substring
    unordered_map<string, int> firstOccurrence; // Map to store the first occurrence of each substring

    int n = s.length();

    // Sliding window to generate all substrings of length k
    for (int i = 0; i <= n - k; i++)
    {
        string substring = s.substr(i, k); // Get the substring of length k starting at index i
        substringCount[substring]++;       // Increment the count of this substring

        // Record the first occurrence of the substring
        if (substringCount[substring] == 1)
        {
            firstOccurrence[substring] = i;
        }
    }

    // Find the first unique substring by checking the counts
    int firstIndex = -1;
    for (auto &pair : substringCount)
    {
        if (pair.second == 1)
        { // Check if the substring is unique
            if (firstIndex == -1 || firstOccurrence[pair.first] < firstIndex)
            {
                firstIndex = firstOccurrence[pair.first]; // Update the first index of the unique substring
            }
        }
    }

    return firstIndex; // Return the first index of the unique substring, or -1 if none found
}

// Function to handle multiple queries and return results in a vector
vector<int> processQueries(const string &s, const vector<int> &queries)
{
    vector<int> results;
    for (int k : queries)
    {
        int index = findFirstUniqueSubstring(s, k);
        results.push_back(index);
    }
    return results;
}

int main()
{
    string s = "abacabad";
    vector<int> queries = {2, 3, 4}; // Array of queries

    // Get the results for all queries
    vector<int> results = processQueries(s, queries);

    // Output the results
    for (int i = 0; i < results.size(); i++)
    {
        cout << "First unique substring of length " << queries[i]
             << " starts at index: " << results[i] << endl;
    }

    return 0;
}
