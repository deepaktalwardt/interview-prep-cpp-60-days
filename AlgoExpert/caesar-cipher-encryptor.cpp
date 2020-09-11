// Solution
// O(N): Time
// O(N): Space
using namespace std;

string caesarCypherEncryptor(string str, int key)
{
    // Write your code here.
    string toReturn = "";
    for (const char& c : str)
    {
        if (c + key > 'z')
        {
            int k = (c + key - 'z' - 1) % 26;
            toReturn += 'a' + k;
        }
        else
        {
            toReturn += c + key;
        }
    }
    return toReturn;
}
