package PJ.Lecture2.excercise2.help;

public class Help {
    public static int factorial(int n)
    {
        int result = 1;
        while(n > 1) result *= n--;
        return result;
    }
}
