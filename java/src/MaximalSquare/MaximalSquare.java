package MaximalSquare;

/*
Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

Example:

Input:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

Output: 4
 */

public class MaximalSquare {
    public int maximalSquare(char[][] matrix) {
        if (matrix.length == 0) {
            return 0;
        }
        int[][] dp = new int[matrix.length][matrix[0].length];
        int max_length = 0;
        for (int i = 0; i < dp.length; i++) {
            for (int j = 0; j < dp[i].length; j++) {
                if (matrix[i][j] == '1') {
                    dp[i][j] = 1;
                    max_length = Math.max(dp[i][j], max_length);
                } else {
                    continue;
                }
                if (i > 0 && j > 0) {
                    if (dp[i-1][j-1] > 0) {
                        for (int k = 1; k <= dp[i-1][j-1]; k++) {
                            if (matrix[i-k][j] == '1' && matrix[i][j-k] == '1') {
                                dp[i][j]++;
                            } else {
                                break;
                            }
                        }
                    }
                    max_length = Math.max(dp[i][j], max_length);
                }
            }
        }
        for (int i = 0; i < dp.length; i++) {
            for (int j = 0; j < dp[0].length; j++) {
                System.out.print(dp[i][j]);
                System.out.print(' ');
            }
            System.out.println();
        }
        return max_length * max_length;
    }
    public static void main(String[] args) {
        char[][] maxtrix = { {'1', '0', '1', '0', '0'}, {'1', '0', '1', '1', '1'}, { '1', '1', '1', '1', '1'}, {'1', '0', '0', '1', '0'}};
        char[][] maxtrix1 = { {'0','0','0','1'},{'1','1','0','1'},{'1','1','1','1'},{'0','1','1','1'},{'0','1','1','1'}};
        MaximalSquare maximalSquare = new MaximalSquare();
        int res = maximalSquare.maximalSquare(maxtrix);
        System.out.print(res);
    }
}
