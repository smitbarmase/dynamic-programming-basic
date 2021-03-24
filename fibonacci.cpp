#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<int, long long> map;

long long fib(int n)
{
    if (map.find(n) != map.end())
        return map[n];
    if (n < 2)
        return 1;
    long long result = fib(n - 1) + fib(n - 2);
    map.insert(make_pair(n, result));
    return result;
}

int main()
{
    cout << fib(6) << endl;
    cout << fib(50) << endl;
    return 0;
}