// Solution 1 (Using a Set)
// O(N): Time
// O(N): Space
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> twoNumberSum(vector<int> array, int targetSum)
{
    // Write your code here.
    unordered_set<int> s;
    for (const int& elem : array)
    {
        if (s.find(targetSum - elem) != s.end())
        {
            return {elem, targetSum - elem};
        }
        s.insert(elem);
    }
    return {};
}

// Solution 2 (Using sorting + two pointers)
// O(NlogN): Time
// O(1): Space
#include <vector>
#include <algorithm>
using namespace std;

vector<int> twoNumberSum(vector<int> array, int targetSum)
{
    // Write your code here.
    sort(array.begin(), array.end());
    int i = 0;
    int j = array.size() - 1;
    while (i < j)
    {
        if (array[i] + array[j] == targetSum)
        {
            return {array[i], array[j]};
        }
        else if (array[i] + array[j] < targetSum)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    return {};
}
