package PJ.Lecture2.excercise2.second;

import java.util.Scanner;


public class Second
{
    public static int factorial(int n)
    {
        int result = 1;
        while(n > 1) result *= n--;
        return result;
    }

    public static void main(String[] args) 
    {
        Scanner input = new Scanner (System.in);
        System.out.print( "Enter number: ");
        int entered = input.nextInt ();
        System.out.println( "Factorial of this number is " + PJ.Lecture2.excercise2.help.Help.factorial(entered));
        input.close();
    }
}


class Help
{
    
}
