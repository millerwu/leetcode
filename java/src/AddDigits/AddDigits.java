package AddDigits;

public class AddDigits {
    public int getNum(int num) {
        int n = 0;
        while (num >= 10) {
            n += num % 10;
            num /= 10;
        }
        n += num;
        return n;
    }

    public int addDigits(int num) {
        while (num >= 10) {
            num = getNum(num);
        }
        return num;
    }

    public static void main(String[] args) {
        AddDigits addDigits = new AddDigits();
        int res = addDigits.addDigits(38);
        System.out.println(res);
        return;
    }
}
