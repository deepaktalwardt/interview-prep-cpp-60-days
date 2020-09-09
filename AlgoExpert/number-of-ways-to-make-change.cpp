// Solution
// O(ND): Time (D -> number of denominations)
// O(N): Space
// Think: Can I use this denomination to make change for this value? If yes, remove that amount from
// the value, and look for however many ways exist for the remainder, and add the current number of
// ways with the number of ways of the remainder
#include <vector>
using namespace std;
/**

values  ->  0	1	2	3	4	5   6

ways(1) ->	1   1   1   1   1   1   1
ways(5) ->  1   1   1   1   1   2   2

ways[i] = ways[i] + ways[value - denom]

*/

int numberOfWaysToMakeChange(int n, vector<int> denoms)
{
    // Write your code here.
    vector<int> ways(n + 1, 0);
    ways[0] = 1;
    for (const int& denom : denoms)
    {
        for (int value = 1; value < n + 1; value++)
        {
            if (denom <= value)
            {
                ways[value] += ways[value - denom];
            }
        }
    }
    return ways[n];
}
