// Solution 1
// O(N): Time
// O(N): Space
// You can either choose to include the current value in the sum, or choose to ignore it and use the
// max sum at the last index. To decide, choose the max between (the current value + sum at last to
// last index) and (the sum at last index).
#include <vector>
using namespace std;

int maxSubsetSumNoAdjacent(vector<int> array)
{
    // Write your code here.
    if (array.size() == 0)
    {
        return 0;
    }
    int maxSum = 0;
    vector<int> sums(array.size(), 0);
    sums[0] = array[0];
    sums[1] = max(sums[0], array[1]);
    for (int i = 2; i < array.size(); i++)
    {
        sums[i] = max(array[i] + sums[i - 2], sums[i - 1]);
    }
    return sums[array.size() - 1];
}

// Solution 2
// O(N): Time
// O(1): Space
#include <vector>
using namespace std;

int maxSubsetSumNoAdjacent(vector<int> array)
{
    // Write your code here.
    int n = array.size();
    if (n == 0)
        return 0;
    if (n == 1)
        return array[0];
    int lastMaxSum = array[0];
    int lastToLastMaxSum = 0;
    for (int i = 1; i < n; i++)
    {
        int currMaxSum = max(array[i] + lastToLastMaxSum, lastMaxSum);
        lastToLastMaxSum = lastMaxSum;
        lastMaxSum = currMaxSum;
    }
    return lastMaxSum;
}
