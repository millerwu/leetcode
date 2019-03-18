package ContainsDuplicate;

import java.util.HashSet;

public class ContainsDuplicateII {
    public boolean containsNearbyDuplicate(int[] nums, int k) {
        HashSet<Integer> s = new HashSet<Integer>();
        if (nums.length - 1 <= k) {
            k = nums.length - 1;
        }
        for (int i = 0; i <= k; i++) {
            if (s.contains(nums[i])) {
                return true;
            }
            s.add(nums[i]);
        }
        for (int i = k + 1; i < nums.length; i++) {
            s.remove(nums[i - 1 - k]);
            if (s.contains(nums[i])) {
                return true;
            }
            s.add(nums[i]);
        }
        return false;
    }

    public static void main(String[] args) {
        int[] nums = {1,2,3,1};
        ContainsDuplicateII containsDuplicateII = new ContainsDuplicateII();
        boolean res = containsDuplicateII.containsNearbyDuplicate(nums, 3);
        System.out.print(res);
    }
}
