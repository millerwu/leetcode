//source: https://leetcode.com/problems/merge-sorted-array/

/*
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2. The number of elements initialized in nums1 and nums2 are m and n respectively.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
      int i1 = m-1;
      int i2 = n-1;
      int size = m+n-1;
      for ( size = m+n-1; size >= 0; --size)
       {
       	if(i1 >= 0 && i2 <0)
       	{
       		break;
       	}
       	if (i1 < 0 && i2 >= 0)
       	{
       		nums1[size] = nums2[i2--];
       		continue;
       	}
       	if (i1>=0 && i2>=0)
       	{
       		if (nums1[i1] >= nums2[i2])
       		{
       			nums1[size] = nums1[i1--];
       		} else{
       			nums1[size] = nums2[i2--];
       		}
       	}
       } 
        return;
    }
};

int main ()
{
	return 0;
}
