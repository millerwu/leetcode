package FindMinimuminRotatedSortedArray;

/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).

Find the minimum element.

The array may contain duplicates.

Example 1:

Input: [1,3,5]
Output: 1
Example 2:

Input: [2,2,2,0,1]
Output: 0
 */

//TODO finish

public class FindMinimuminRotatedSortedArrayII {
    public int findMin(int[] nums) {
        int begin = 0;
        int end = nums.length - 1;
        while  (begin < end) {
            int min = (begin + end) / 2;
            if (nums[begin] > nums[min]) {
                end = min - 1;
                continue;
            }  else if (nums[min] > nums[end]) {
                begin = min + 1;
                continue;
            }
        }

        return 0;

    }

    public static void main(String[] args) {
        int[] nums = {2, 2, 2, 0, 1};

    }
}
