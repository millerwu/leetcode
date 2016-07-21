//source: https://leetcode.com/problems/simplify-path/

/*
Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"

*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    static std::string simplifyPath(std::string path) {
        if (path.size() == 0)
        {
            return path;
        }
        cout << path << endl;
        int index = 0;
        vector<std::string> fname;
        while (index < path.size())
        {
            if (path[index] == '/')
            {
                if (fname.size()==0 || fname.back().size() > 0)
                {
                    fname.push_back("");
                }
                index++;
                continue;
            }
            if (path[index] == '.')
            {
                index++;
                if (path[index] == '.')
                {
                    if (fname.size()>0)
                    {
                        fname.pop_back();
                        if (fname.size()>0)
                        {
                            fname.pop_back();
                        }
                    }
                    index++;
                }
                continue;
            }
            fname.back().insert(fname.back().end(), path[index]);
            index++;
        }
        cout << endl;
        std::string res = "";
        for (int i = 0; i < fname.size(); i++)
        {
            if (!fname[i].empty())
             res = res+"/"+fname[i];
        }
        return res;
    }
};

#define TEST(X) cout<<X << "simple path is" << Solution::simplifyPath(X) << endl;

int main ()
{
    std::string path = Solution::simplifyPath("/home//foo/");
    cout << path << endl;
	return 0;
}
