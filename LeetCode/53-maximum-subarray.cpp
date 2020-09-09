// Solution
// O(N): Time
// O(1): Space
// The choice is whether or not to include the current value in the contiguous subarray. To decide,
// choose the max between the current value and the sum of current value and previous max
class Solution
{
public:
    /**

    -2, 1, -3, 4, -1, 2, 1, -5, 4
    -2, 1, -2, 4,  3, 5, 6,  1, 5

    */
    int maxSubArray(vector<int>& nums)
    {
        int n = nums.size();
        if (n == 1)
            return nums[0];

        int maxSum = INT_MIN;
        int prevMax = 0;
        for (int i = 0; i < n; i++)
        {
            int currMax = max(nums[i], nums[i] + prevMax);
            prevMax = currMax;
            maxSum = max(currMax, maxSum);
        }
        return maxSum;
    }
};