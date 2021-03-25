#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct how_sum_return
{
    bool not_found;
    vector<int> arr;
};

unordered_map<int, how_sum_return> map;

how_sum_return how_sum(int target_sum, vector<int> numbers)
{
    if (map.find(target_sum) != map.end())
        return map[target_sum];
    how_sum_return result;
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

    for (auto &num : numbers)
    {
        int remaining = target_sum - num;
        how_sum_return remainder_result = how_sum(remaining, numbers);
        if (remainder_result.not_found == false)
        {
            remainder_result.arr.push_back(num);
            map.insert(make_pair(target_sum, remainder_result));
            return remainder_result;
        }
    }

    result.not_found = true;
    map.insert(make_pair(target_sum, result));
    return result;
}

int main()
{
    how_sum_return result = how_sum(300, vector<int>({7, 14}));
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