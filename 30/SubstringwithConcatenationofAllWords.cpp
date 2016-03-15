//https://leetcode.com/problems/substring-with-concatenation-of-all-words/

/*
You are given a string, s, and a list of words, words, that are all of the same length. Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.

For example, given:
s: "barfoothefoobarman"
words: ["foo", "bar"]

You should return the indices: [0,9].
(order does not matter).
*/

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <sys/time.h>

using namespace std;

static long long getcurrenttime() 
{
    struct timeval tv;
    gettimeofday(&tv, NULL);

    long long time = tv.tv_sec*1000000 + tv.tv_usec;
    return time;
}

class Solution {
public:
    static vector<int> findSubstring(string s, vector<string>& words) {
    	int wordslen = words[0].size();
    	int totallen = wordslen*words.size();
        int wordsize = words.size();

    	vector<int> res;
        int s_length = s.length();
    	if (totallen > s_length)
    		return res;

    	map<string, int> dict;

        // add all words to map
    	for (int i = 0; i < words.size(); i++)
    	{
            if (dict.find(words[i]) != dict.end())
                dict[words[i]]++;
            else
                dict[words[i]] = 1;
    	}

        for (int i = 0; i < wordslen; i++) {

            map<string, int> actual;
            int count = 0;
            int left = i;

            for (int j = i; j < s_length; j += wordslen)
            {
                string word = s.substr(j, wordslen);

                //if not find word, then restart search from j + wordslen
                if (dict.find(word) == dict.end())
                {
                    actual.clear();
                    count = 0;
                    left = j + wordslen;
                    continue;
                }
                count++;

                if (actual.find(word) != actual.end()) {
                    actual[word]++;
                }
                else {
                    actual[word] = 1;
                }
                
                // word is over flow, delete word before this word
                if (actual[word] > dict[word])
                {
                    string tmp;
                    do {
                        tmp = s.substr(left, wordslen);
                        actual[tmp]--;
                        count--;
                        left += wordslen;
                    } while (tmp != word);
                }

                // fit condition, add left; then delete front word and search word from left + wordslen
                if (count == wordsize)
                {
                    res.push_back(left);
                    string tmp = s.substr(left, wordslen);
                    actual[tmp]--;
                    left += wordslen;
                    count--;
                }
            }
        }
        return res;
    }
};

int main()
{
    string s = "barfoofoobarthefoobarman";
    std::vector<string> words;
    words.push_back("bar");
    words.push_back("foo");
    words.push_back("the");


    long long begin_time = getcurrenttime();

    std::vector<int> result = Solution::findSubstring(s, words);

    long long cost_time = getcurrenttime() - begin_time;

    cout << "findSubstring cost " << cost_time << " \n";

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }

    cout<< endl;

	return 0;
}