class Solution {
    
    public int trap(int[] height) {
        // Calculating left Maximum
        int leftMax[] = new int[height.length];

        leftMax[0]=height[0];
        for(int i=1;i<height.length;i++) {
            leftMax[i] = Math.max(height[i],leftMax[i-1]);
        }

        // Calculating right max

        int rightMax[] = new int[height.length];
        rightMax[height.length-1]=height[height.length-1];
        for(int i=height.length-2;i>=0;i--) {
            rightMax[i] = Math.max(height[i],rightMax[i+1]);
        }

        int trappedwater = 0;
        for(int i=0;i<height.length;i++) {
            // Calculating Water Level
            int waterLevel = Math.min(leftMax[i],rightMax[i]);
            // Calculating Total Trapped Water
            trappedwater += waterLevel - height[i];
        }
        return trappedwater;
    }
}
