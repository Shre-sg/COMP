#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minGenerations(vector<int> &layer)
{
    int max_ = *max_element(layer.begin(), layer.end());
    int _needed = 0;

    for (int neurons : layer)
    {
        _needed += max_ - neurons;
    }

    int generations = 1;
    while (_needed > 0)
    {
        if (generations % 2 == 0)
        {
            if (_needed - 2 < 0)
            {
                generations++;
                continue;
            }
            _needed -= 2;
        }
        else
        {
            if (_needed - 1 < 0)
            {
                generations++;
                continue;
            }
            _needed -= 1;
        }
        generations++;
    }

    return generations;
}

int main()
{
    vector<int> layer = {1, 1, 2, 4};
    cout << "Minimum generations required: " << minGenerations(layer) << endl;
    return 0;
}
