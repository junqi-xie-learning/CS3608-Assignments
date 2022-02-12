#include "../leetcode.h"

int minDistance(string word1, string word2)
{
    vector<int> prev, current;
    iota(current.begin(), current.end(), word2.size() + 1);

    for (int i = 0; i < word1.size(); ++i)
    {
        prev = current;
        current = {i + 1};
        for (int j = 0; j < word2.size(); ++j)
        {
            current.push_back(
                min({prev[j + 1] + 1, current[j] + 1,
                    prev[j] + (word1[i] != word2[j])}));
        }
    }
    return current[word2.size()];
}

int main()
{
    string word1, word2;
    cin >> word1 >> word2;
    cout << minDistance(word1, word2) << endl;
    return 0;
}
