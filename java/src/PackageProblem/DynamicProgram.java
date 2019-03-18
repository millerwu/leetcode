package PackageProblem;

public class DynamicProgram {
    public int knapsack3(int[] weight, int[] value, int n, int w) {
        int[][] dp = new int[n][w+1];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < w+1; j++) {
                dp[i][j] = -1;
            }
        }
        dp[0][0] = 0;
        dp[0][weight[0]] = value[0];
        for (int i = 1; i < n ; i++) {
            for (int j = 0; j <= w; j++) {
                dp[i][j] = dp[i-1][j];
            }
            for (int j = 0; j + weight[i] <= w; j++) {
                if (dp[i-1][j] >= 0) {
                    int v = dp[i-1][j] + value[i];
                    if (v > dp[i][weight[i]+j]){
                        dp[i][j+weight[i]] = v;
                    }
                }
            }
        }
        int v = Integer.MIN_VALUE;
        for (int i = 0; i <n; i++) {
            for (int j = 0; j <= w; j++) {
                v = v < dp[i][j] ? dp[i][j] : v;
            }
        }
        return v;

    }

    static public void main(String[] args) {
        int[] value = {7, 4, 5};
        int[] weight = {2, 3, 2};
        DynamicProgram dynamicProgram = new DynamicProgram();
        int res = dynamicProgram.knapsack3(weight, value, 3, 5);
        System.out.println(res);
        return;
    }
}
