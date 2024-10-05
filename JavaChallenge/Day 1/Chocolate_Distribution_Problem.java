class Solution
{
    public long findMinDiff (ArrayList<Integer> a, int n, int m)
    {
        int min_diff = Integer.MAX_VALUE;
        Collections.sort(a);
        for(int i =0; i<n; i++){
        // i+m-1 -> Maximum Element of ArrayList
            if(i+m-1 < n){
                int curr_diff = (a.get(i) - a.get(i+m-1));
                int absolute_diff = Math.abs(curr_diff);
                min_diff = Math.min(min_diff , absolute_diff);
            }
        }
        return min_diff;
    }
}
