//source: https://leetcode.com/problems/maximal-rectangle/

/*
Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing all ones and return its area.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static int largestRectangleArea(vector<int> &length)
    {
        if (length.size() == 0)
        {
            return 0;
        }
        vector<int> stack;

        length.push_back(0);
        int i = 0;
        int maxArea = 0;
        while (i < length.size())
        {
            if (stack.empty() || length[i] > length[stack.back()])
            {
                stack.push_back(i);
                i++;
                continue;
            } else {
                int l = stack.back();
                stack.pop_back();
                maxArea = std::max(maxArea, length[l]*(stack.empty() ? i : i-stack.back()-1));
            }
        }
        return maxArea;
    }

    static int maximalRectangle(vector<vector<char> >& matrix) 
    {
        if (matrix.size() == 0)
        {
            return 0;
        }
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int> > height(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == '0')
                {
                    height[i][j] = 0;
                } else {
                    height[i][j] = (i==0) ? 1 : height[i-1][j] + 1;
                }
            }
        }

        int maxArea = 0;
        
        for (int i = 0; i < m; i++)
        {
            maxArea = std::max(maxArea, largestRectangleArea(height[i]));
        }
        return maxArea;
    }
};

void printArray(vector<int> &v)
{
    cout << "{";
    for(int i=0; i<v.size(); i++) {
        cout << " " << v[i];
    }
    cout << "}" << endl;
}

void test(int a[], int n)
{
    vector<int> v(a, a + n);
    printArray(v);
    cout << Solution::largestRectangleArea(v) << endl;
}

int main ()
{
    #define TEST(a) test(a, sizeof(a)/sizeof(int))

    int a0[] = {2,1,3,1};
    TEST(a0);
    int a1[] = {2,1,5,6,2,3};
    TEST(a1);
    cout << "------------------" << endl; 
    srand(time(0));

    int r = 3;
    int c = 3;
    // if (argc>2){
    //     r = atoi(argv[1]);
    //     c = atoi(argv[2]);
    // }

    vector< vector<char> > matrix;
    for(int i=0; i<r; i++){
        vector<char> v;
        cout << "[";
        for(int j=0; j<c; j++) {
            char ch = random()%2+'0';
            v.push_back(ch);
            cout << " " << ch;
        }
        matrix.push_back(v);
        cout << " ]" << endl;
    }
    cout << "------------------" << endl; 
    cout << "maxArea = " << Solution::maximalRectangle(matrix)<< endl;


	return 0;
}
