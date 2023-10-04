public class Main {
    static int factorial(int n)
    {
        assert n >= 0: "Negative parametr of factorial";
        int res = 1;
        while(n > 1) res *= n--;
        return res;
    }



    public static void main(String[] args) {
        System.out.println(factorial(-4));

    }
}

//java -ea Assert1.Main