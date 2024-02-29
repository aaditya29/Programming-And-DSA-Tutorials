// Comes under tag of hash table too

/*
Two strings are considered close if you can attain one from the other using the following operations:

Operation 1: Swap any two existing characters.
For example, abcde -> aecdb

Operation 2: Transform every occurrence of one existing character into another existing character, and do the same with the other character.
For example, aacabb -> bbcbaa (all a's turn into b's, and all b's turn into a's)
You can use the operations on either string as many times as necessary.

Given two strings, word1 and word2, return true if word1 and word2 are close, and false otherwise.


Example 1:
Input: word1 = "abc", word2 = "bca"
Output: true
Explanation: You can attain word2 from word1 in 2 operations.
Apply Operation 1: "abc" -> "acb"
Apply Operation 1: "acb" -> "bca"

Example 2:
Input: word1 = "a", word2 = "aa"
Output: false
Explanation: It is impossible to attain word2 from word1, or vice versa, in any number of operations.

Example 3:
Input: word1 = "cabbba", word2 = "abbccc"
Output: true
Explanation: You can attain word2 from word1 in 3 operations.
Apply Operation 1: "cabbba" -> "caabbb"
Apply Operation 2: "caabbb" -> "baaccc"
Apply Operation 2: "baaccc" -> "abbccc"

*/

class Solution
{
public:
    bool closeStrings(string word1, string word2)
    {

        vector<int> freqW1(26, 0), freqW2(26, 0);
           vector<int> IspresentW1(26, 0), IspresentW2(26, 0);
        for (char c : word1)
        {
            freqW1[c - 'a']++;
            IspresentW1[c - 'a'] = 1;
        }
        for (char c : word2)
        {
            freqW2[c - 'a']++;
            IspresentW2[c - 'a'] = 1;
        }
        sort(freqW1.begin(), freqW1.end());
        sort(freqW2.begin(), freqW2.end());
        return freqW1 == freqW2 && IspresentW1 == IspresentW2;
    }
};