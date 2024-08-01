#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

class LFUCache
{
public:
    // Data Structure Requirements
    unordered_map<int, pair<int, int>> avl_keys;     // key -> {value, freq}
    unordered_map<int, list<int>> freq_bucket;       // freq -> {list of keys}
    unordered_map<int, list<int>::iterator> key_pos; // key -> iterator in freq_bucket

    int curr_size = 0, total_cap = 0, min_freq = 0;

    LFUCache(int capacity)
    {
        total_cap = capacity;
    }

    int get(int key)
    {
        if (avl_keys.find(key) == avl_keys.end())
            return -1;

        int curr_freq = avl_keys[key].second;
        freq_bucket[curr_freq].erase(key_pos[key]);

        avl_keys[key].second += 1;
        int new_freq = avl_keys[key].second;

        freq_bucket[new_freq].push_back(key);
        key_pos[key] = --freq_bucket[new_freq].end();

        if (freq_bucket[min_freq].empty())
            min_freq += 1;

        return avl_keys[key].first;
    }

    void put(int key, int value)
    {
        if (total_cap == 0)
            return;

        int prev_value = get(key);

        if (prev_value != -1)
        {
            avl_keys[key].first = value;
            return;
        }

        if (curr_size >= total_cap)
        {
            int lr_key = freq_bucket[min_freq].front();
            avl_keys.erase(lr_key);
            key_pos.erase(lr_key);
            freq_bucket[min_freq].pop_front();
            curr_size -= 1;
        }

        avl_keys[key] = {value, 1};
        min_freq = 1;
        freq_bucket[min_freq].push_back(key);
        key_pos[key] = --freq_bucket[min_freq].end();
        curr_size += 1;
    }
};

int main()
{
    // Create an LFUCache with a capacity of 2
    LFUCache cache(2);

    // Add some key-value pairs
    cache.put(1, 10); // Cache is {1=10}
    cache.put(2, 20); // Cache is {1=10, 2=20}

    // Get the value for key 1 (this will increase its frequency)
    cout << "Get key 1: " << cache.get(1) << endl; // Returns 10, Cache is {2=20, 1=10}

    // Add another key, this will evict key 2 because it has the lowest frequency
    cache.put(3, 30); // Cache is {1=10, 3=30}

    // Get the value for key 2 (this will return -1 as key 2 was evicted)
    cout << "Get key 2: " << cache.get(2) << endl; // Returns -1 (not found)

    // Add another key, this will evict key 1 because key 3 has higher frequency
    cache.put(4, 40); // Cache is {3=30, 4=40}

    // Get the value for key 1 (this will return -1 as key 1 was evicted)
    cout << "Get key 1: " << cache.get(1) << endl; // Returns -1 (not found)

    // Get the value for key 3
    cout << "Get key 3: " << cache.get(3) << endl; // Returns 30

    // Get the value for key 4
    cout << "Get key 4: " << cache.get(4) << endl; // Returns 40

    return 0;
}
