package RangeSumQueryMutable;

import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Arrays;

public class RangeSumQueryMutable {

    int[] mNums;

    public RangeSumQueryMutable(int[] nums) {
        mNums = new int[nums.length];
        mNums = Arrays.copyOf(nums, nums.length);
    }

    public void update(int i, int val) {
        mNums[i] = val;
    }

    public int sumRange(int i, int j) {
        int sum = 0;
        for (int k = i; k <= j; k++) {
            sum += mNums[k];
        }
        return sum;
    }

    public static void main(String[] args) {
        int[] nums = {1, 3, 5};
        RangeSumQueryMutable rangeSumQueryMutable = new RangeSumQueryMutable(nums);
        rangeSumQueryMutable.update(1, 2);
        int res = rangeSumQueryMutable.sumRange(0, 2);
        System.out.println(res);
    }
}
