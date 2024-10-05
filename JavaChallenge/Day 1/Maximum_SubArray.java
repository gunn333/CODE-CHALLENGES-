class Solution {
    public int maxSubArray(int[] nums) {
        int sum = nums[0];
        int maxsum = sum;
        for(int i = 1; i<nums.length ; i++){
            if(sum<0){
                sum = 0;
            }
            sum +=nums[i];
            maxsum = Math.max(maxsum,sum);
        }
        maxsum = Math.max(maxsum,sum);
        return maxsum;
    }
}
