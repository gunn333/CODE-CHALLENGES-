class Solution {
    public boolean containsDuplicate(int[] nums) {
        HashSet<Integer> res_set = new HashSet<>();
        for (int i = 0; i < nums.length; i++) {
                if (res_set.contains(nums[i])) {
                    return true;
                }
                res_set.add(nums[i]);
        }
        return false;
    }
}


// Alternative Brute Force Approach 

/*
class Solution {
    public boolean containsDuplicate(int[] nums) {
        Arrays.sort(nums); 
        for (int i = 0; i < nums.length - 1; i++) {
                if (nums[i] == nums[i+1]) {
                    return true;
                }
        }
        return false;
    }
}
*/
