class Solution {
    public int maxProfit(int[] prices) {
		    // Keeps the track of Lowest price encountered so far.
        int left_min = Integer.MAX_VALUE;
        // Since negetive profit is not a profit, so we initialize profit variable with 0
        int profit = 0;
        for (int i = 0; i < prices.length; i++) {
            if (prices[i] < left_min) {
                left_min = prices[i];
            }
            // potential profit p is calculated as the difference between the current price (prices[i]) and the lowest price found so far (left_min).
            int p = prices[i] - left_min;
            if (profit <= p) {
                profit = p;
            }
        }
        return profit;
    }
}
