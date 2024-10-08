class Solution {
    public List<Integer> spiralOrder(int[][] sprialMaxtix) {
       ArrayList<Integer> sprial = new ArrayList<Integer>();
		int top,bottom,left,right;
		top = left = 0;
		right = sprialMaxtix[0].length-1;
		bottom = sprialMaxtix.length-1;

		while(left <= right && top <= bottom) {
			for(int i=left; i<=right; i++) {
				sprial.add(sprialMaxtix[top][i]);
			}
			top++;

			for(int i=top; i<=bottom; i++) {
				sprial.add(sprialMaxtix[i][right]);
			}
			right--;

			if(top <= bottom) {
				for(int i=right; i>=left; i--) {
					sprial.add(sprialMaxtix[bottom][i]);
				}
				bottom--;
			}

			if(left <= right) {
				for(int i=bottom; i>=top; i--) {
					sprial.add(sprialMaxtix[i][left]);
				}
				left++;
			}
		}

		return sprial;
    }
}
