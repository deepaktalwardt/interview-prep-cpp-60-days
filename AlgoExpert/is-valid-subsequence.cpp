// Solution 1
// O(N): Time
// O(1): Space
using namespace std;

bool isValidSubsequence(vector<int> array, vector<int> sequence)
{
    // Write your code here.
    int arr_size = array.size();
    int seq_size = sequence.size();
    if (seq_size > arr_size)
    {
        return false;
    }
    int i = 0;
    int j = 0;
    while (i < arr_size && j < seq_size)
    {
        if (array[i] == sequence[j])
        {
            j++;
        }
        i++;
    }
    return j == seq_size;
}
