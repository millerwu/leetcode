//source: https://leetcode.com/problems/median-of-two-sorted-arrays/
//H
// TAG  Binary Search Array Divide and Conquer
/*
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

Example 1:
nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:
nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
*/

#include <iostream>
#include <vector>

using namespace std;

int findKthNum(vector<int>& nums1, vector<int>::iterator nums1start, vector<int>& nums2, vector<int>::iterator nums2start, int k)
{
	if (nums1.end() == nums1start) {
		return *(nums2start+k);
	}
	if (nums2.end() == nums2start) {
		return *(nums1start+k);
	}
	if (k == 0) {
		return min(*nums1start, *nums2start);
	}
	if (*nums1start <= *nums2start) {
		return findKthNum(nums1, ++nums1start, nums2, nums2start, k-1);
	} else {
		return findKthNum(nums1, nums1start, nums2, ++nums2start, k-1);
	}
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
  int total_size = nums1.size() + nums2.size();
  if (total_size & 0x1) {
    return findKthNum(nums1, nums1.begin(), nums2, nums2.begin(), total_size/2);
  } else {
    int res1 = findKthNum(nums1, nums1.begin(), nums2, nums2.begin(), (total_size-1)/2);
    int res2 = findKthNum(nums1, nums1.begin(), nums2, nums2.begin(), total_size/2);
    return ((double)(res1+res2))/2;
  }
}

int main ()
{
  vector<int> v1 = {1, 2};
  vector<int> v2 = {3, 4};

  double res = findMedianSortedArrays(v1, v2);
  cout << "res = " << res << endl;
	return 0;
}
