#include <iostream>
#include <vector>

using namespace std;

// choose their favourite number once they turn 10 But if you are a descendant of one the world's greatest Mathematicians, you are not allowed to choose any random number right?

// Aleksandra is turning 18 next month, but the problem is she

// is very bad at Math So she approaches you with the conditions to choose a favourite number for her. The secret rule is that the chosen number must berg Parent Mask of Child Mask of at least one of the numbers listed down in a secret scroll passed through generations Parent Mask of number X is defined as a number that can be obtained by flipping zero or more unvet bits of X, Similarly Child Masi of X can be obtained by flipping zero or more set bits of X. As a reminder set bite refer to is in the binary representation of the number and unset bits refer to the Os ts binary representation

// For example 3(11 in binary) a Parent Mask of 2 (10 in binary ) as we change the least significant bit of 2 from 0 to 1 , similarly logic 2 is child mask of 3

// integer X is both Parent Mask and Child Mask of itself As stated before, Aleksandra is bad at mathematics(her family's genes missed her) so she stole the secret scroll with the list of numbers and gave it to you. The scroll contains N numbers A1, Az AN Aleksandra has Q queries, each containing a single integer X. Your task is to deterrnine if X can potentially be Aleksandra's favourite number or not. In short, determine if X is either a Parent Mask or Child Mask of at least one of the numbers A1, A2....,AN

// Input Format:
// • The first line contains two space separated integers N and O denoting the count of numbers in the ret scroll and the number of queries Aleksandra has respectively.
// Second ine contains space separated integers A. Az Anumbers as mentioned the

// Function to check if X is a Parent Mask or Child Mask of A

// exmaple
//  Dry run for
// 2 3
//  1 3
//  2
//  4
//  5

// Initial Setup:

// Number of numbers 𝑁=2
// Number of queries 𝑄=3
// Numbers list: [1, 3]
// Queries list: [2, 4, 5]
// //output
// YES
// NO
// YES

bool isParentOrChildMask(int x, int a)
{
    bool isParent = (x & a) == a;
    bool isChild = (a & x) == x;
    return isParent || isChild;
}

// Function to process queries and determine the result for each
vector<string> processQueries(const vector<int> &numbers, const vector<int> &queries)
{
    vector<string> results;

    for (int x : queries)
    {
        bool found = false;
        for (int a : numbers)
        {
            if (isParentOrChildMask(x, a))
            {
                results.push_back("YES");
                found = true;
                break;
            }
        }
        if (!found)
        {
            results.push_back("NO");
        }
    }

    return results;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    vector<int> numbers(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> numbers[i];
    }

    vector<int> queries(Q);
    for (int i = 0; i < Q; ++i)
    {
        cin >> queries[i];
    }

    // Process queries and get results
    vector<string> results = processQueries(numbers, queries);

    // Output results
    for (const string &result : results)
    {
        cout << result << "\n";
    }

    return 0;
}
