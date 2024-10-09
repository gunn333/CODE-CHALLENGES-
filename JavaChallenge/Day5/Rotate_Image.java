
class Solution {
    public void rotate(int[][] arr) {
        int m = arr.length;
        int n = arr[0].length;
        // transpose of matrix
           for (int i = 0; i < m; i++) {
            for (int j = 0; j < i; j++) {  
                int temp = arr[i][j];
                arr[i][j] = arr[j][i];
                arr[j][i] = temp;
            }            
        }
        // for reversing the row of transposed matrix 
       
        for(int i = 0 ; i<m;i++){
             int a =0 ; 
             int b=m-1;
            while(a<b){
                int temp = arr[i][a];
                arr[i][a]= arr[i][b];
                arr[i][b]= temp;
                a++;
                b--;
            }
        }
    }     
}
