//source: 

/*

*/

#include <iostream>
#include <deque>

using namespace std;

class Solution {
public:
    int x;
    Solution()
    {
    	x = 0;
    }
};

int main ()
{
	deque<Solution> q;
	Solution s;

	q.push_back(s);
	s.x++;
	q.push_back(s);
	s.x++;
	q.push_back(s);

	for (int i = 0; i < q.size(); ++i)
	{
		printf("%d\n", q[i].x);
	}

	return 0;
}
