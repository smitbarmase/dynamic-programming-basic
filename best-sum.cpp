#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct best_sum_return
{
    bool not_found;
    vector<int> arr;
};

unordered_map<int, best_sum_return> map;

best_sum_return best_sum(int target_sum, vector<int> numbers)
{
    if (map.find(target_sum) != map.end())
        return map[target_sum];
    best_sum_return result;
    if (target_sum == 0)
    {
        result.not_found = false;
        return result;
    }

    if (target_sum < 0)
    {
        result.not_found = true;
        return result;
    }

    int min_length = __INT_MAX__;

    for (auto &num : numbers)
    {
        int remaining = target_sum - num;
        best_sum_return remainder_result = best_sum(remaining, numbers);
        if (remainder_result.not_found == false)
        {
            remainder_result.arr.push_back(num);
            int size = remainder_result.arr.size();
            if (size < min_length)
            {
                min_length = size;
                result = remainder_result;
            }
        }
    }

    if (min_length != __INT_MAX__)
    {
        map.insert(make_pair(target_sum, result));
        return result;
    }

    result.not_found = true;
    map.insert(make_pair(target_sum, result));
    return result;
}

int main()
{
    best_sum_return result = best_sum(8, vector<int>({2, 1, 4}));
    if (result.not_found)
    {
        cout << "NULL";
    }
    else
    {
        for (auto num : result.arr)
        {
            cout << num << " ";
        }
    }
    cout << endl;
    return 0;
}