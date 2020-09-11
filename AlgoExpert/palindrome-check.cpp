// Solution
// O(N): Time
// O(1): Space
using namespace std;

bool isPalindrome(string str)
{
    // Write your code here.
    int i = 0;
    int j = str.size() - 1;
    while (i < j)
    {
        if (str[i] == str[j])
        {
            i++;
            j--;
        }
        else
        {
            return false;
        }
    }
    return true;
}
