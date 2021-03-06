package RangeSumQuery2D;

/*
Given a 2D matrix matrix, find the sum of the elements inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).

Range Sum Query 2D
The above rectangle (with the red border) is defined by (row1, col1) = (2, 1) and (row2, col2) = (4, 3), which contains sum = 8.

Example:
Given matrix = [
  [3, 0, 1, 4, 2],
  [5, 6, 3, 2, 1],
  [1, 2, 0, 1, 5],
  [4, 1, 0, 1, 7],
  [1, 0, 3, 0, 5]
]

sumRegion(2, 1, 4, 3) -> 8
sumRegion(1, 1, 2, 2) -> 11
sumRegion(1, 2, 2, 4) -> 12
Note:
You may assume that the matrix does not change.
There are many calls to sumRegion function.
You may assume that row1 ≤ row2 and col1 ≤ col2.

 */

public class RangeSumQuery2D {

    int[][] dp;

    public RangeSumQuery2D(int[][] matrix) {
        if (matrix.length == 0 || (matrix[0].length == 0)) {
            dp = new int[0][0];
            return;
        }
        dp = new int[matrix.length][matrix[0].length];
        dp[0][0] = matrix[0][0];
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[i].length; j++) {
                if (i == 0 && j > 0) {
                    dp[i][j] = dp[i][j-1] + matrix[i][j];
                }
                if (i > 0 && j == 0) {
                    dp[i][j] = dp[i-1][j] + matrix[i][j];
                }
                if (i > 0 && j > 0) {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + matrix[i][j];
                }
            }
        }
    }

    public int sumRegion(int row1, int col1, int row2, int col2) {
        int res = 0;
        if (row1 == 0 && col1 == 0) {
            res = dp[row2][col2];
        } else if (row1 == 0) {
            res = dp[row2][col2] - dp[row2][col1-1];
        } else if (col1 == 0) {
            res = dp[row2][col2] - dp[row1-1][col2];
        } else {
            res = dp[row2][col2] - dp[row1-1][col2] - dp[row2][col1-1] + dp[row1-1][col1-1];
        }
        return res;
    }

    static public void main(String[] args) {
        int[][] matrix = {
                        {3, 0, 1, 4, 2},
                        {5, 6, 3, 2, 1},
                        {1, 2, 0, 1, 5},
                        {4, 1, 0, 1, 7},
                        {1, 0, 3, 0, 5}};
        RangeSumQuery2D rangeSumQuery2D = new RangeSumQuery2D(matrix);
        int res1 = rangeSumQuery2D.sumRegion(2, 1, 4, 3);
        int res2 = rangeSumQuery2D.sumRegion(1, 1, 2, 2);
        int res3 = rangeSumQuery2D.sumRegion(1, 2, 2, 4);
        System.out.println(res1);
        System.out.println(res2);
        System.out.println(res3);
    }
}
