#include <iostream>
#include <unordered_map>
#include <bits/stdc++.h>
using namespace std;

// 146. LRU Cache
// Solved
// Medium
// Topics
// Companies
// Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

// Implement the LRUCache class:

// LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
// int get(int key) Return the value of the key if the key exists, otherwise return -1.
// void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
// The functions get and put must each run in O(1) average time complexity.

// Example 1:

// Input
// ["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
// [[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
// Output
// [null, null, null, 1, null, -1, null, -1, 3, 4]

// Explanation
// LRUCache lRUCache = new LRUCache(2);
// lRUCache.put(1, 1); // cache is {1=1}
// lRUCache.put(2, 2); // cache is {1=1, 2=2}
// lRUCache.get(1);    // return 1
// lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
// lRUCache.get(2);    // returns -1 (not found)
// lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
// lRUCache.get(1);    // return -1 (not found)
// lRUCache.get(3);    // return 3
// lRUCache.get(4);    // return 4

// Constraints:

// 1 <= capacity <= 3000
// 0 <= key <= 104
// 0 <= value <= 105
// At most 2 * 105 calls will be made to get and put.

// easy code
class LRUCache
{
public:
    int cap;
    list<pair<int, int>> lst;
    //(key, {key, value})
    unordered_map<int, list<pair<int, int>>::iterator> cache;
    LRUCache(int capacity)
    {
        this->cap = capacity;
    }

    int get(int key)
    {

        if (cache.find(key) == cache.end())
        {
            return -1;
        }

        auto it = cache[key];
        int value = it->second;

        lst.erase(it);

        lst.push_front({key, value});
        cache[key] = lst.begin();

        return value;
    }

    void put(int key, int value)
    {
        if (cache.find(key) != cache.end())
        {
            auto it = cache[key];

            lst.erase(it);

            lst.push_front({key, value});
            cache[key] = lst.begin();
        }
        else
        {
            if (lst.size() == cap)
            {
                auto last = lst.back();
                cache.erase(last.first);
                lst.pop_back();
            }
            lst.push_front({key, value});
            cache[key] = lst.begin();
        }
    }
};

//
//
// FULL CODE
class LRUCache
{
public:
    class Node
    {
    public:
        int key;
        int val;
        Node *prev;
        Node *next;

        Node(int key, int val)
        {
            this->key = key;
            this->val = val;
        }
    };

    Node *head = new Node(-1, -1); // head of DLL next of head is most accessed node
    Node *tail = new Node(-1, -1); // tail of DLL prev of tail is the least accessed node to be deleted
    int cap;                       // size of LRU cache
    unordered_map<int, Node *> m;

    LRUCache(int capacity) // init
    {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addNode(Node *newnode) // add the node
    {
        Node *temp = head->next;
        newnode->next = temp;
        newnode->prev = head;
        head->next = newnode;
        temp->prev = newnode;
    }

    void deleteNode(Node *delnode) // del node
    {
        Node *prevv = delnode->prev;
        Node *nextt = delnode->next;
        prevv->next = nextt;
        nextt->prev = prevv;
    }

    // func of LRU cache
    int get(int key) // if node exist return its value and make it next to head
    {
        if (m.find(key) != m.end())
        {
            Node *resNode = m[key];
            int ans = resNode->val;
            m.erase(key);
            deleteNode(resNode);
            addNode(resNode);
            m[key] = head->next;
            return ans;
        }
        return -1;
    }

    void put(int key, int value) // in ele comes to LRU cache
    {
        if (m.find(key) != m.end())
        {
            Node *curr = m[key];
            m.erase(key);
            deleteNode(curr);
        }

        if (m.size() == cap) // cap is full del prev of tail add the new node to next of headd
        {
            m.erase(tail->prev->key);
            deleteNode(tail->prev);
        }

        addNode(new Node(key, value));
        m[key] = head->next;
    }
};

int main()
{
    LRUCache *obj = new LRUCache(2); // LRU Cache capacity of 2

    obj->put(1, 1);
    obj->put(2, 2);
    cout << obj->get(1) << endl; // returns 1

    obj->put(3, 3);              // evicts key 2
    cout << obj->get(2) << endl; // returns -1 (not found)

    obj->put(4, 4);              // evicts key 1
    cout << obj->get(1) << endl; // returns -1 (not found)
    cout << obj->get(3) << endl; // returns 3
    cout << obj->get(4) << endl; // returns 4

    delete obj;
    return 0;
}
