package PackageProblem;

public class Backtrace {
    private int maxW = Integer.MIN_VALUE;
    private int[] weight = {2, 2, 4, 6, 3};
    private int n = 5;
    private int w = 9;
    private boolean[][] mem = new boolean[5][10];
    public void f(int i, int cw) {
        if (cw == w || i == n) {
            if (cw > maxW)
                maxW = cw;
            return;
        }
        if (mem[i][cw] ==  true) return;
        mem[i][cw] = true;
        f(i+1, cw);
        if (cw + weight[i] < w) {
            f(i+1, cw + weight[i]);
        }
    }
    public int getMaxW() {
        return maxW;
    }
    static public void main(String[] args) {
        Backtrace backtrace = new Backtrace();
        backtrace.f(0, 0);
        System.out.println(backtrace.getMaxW());
    }
}

