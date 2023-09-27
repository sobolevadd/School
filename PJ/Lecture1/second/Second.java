package second;

import java.util.Scanner;
//import java.lang.*; chyba dvojnasobny import

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
        System.out.println( "Factorial of this number is " + factorial(entered));
        input.close();
    }
}





/* 
class Pomoc
{
    public static int factorial(int n)
    {
        int result = 1;
        while(n > 1) result *= n--;
        return result;
    }
}
*/



//DAEMON THREAD 
//GARBAGE COLLECTOR prohledava zasobnik oznacuje co je pouzivany a co neni. princip mark and compact

//muze byt vice nez jedna trida, ale nesmi byt public. jestli chci vice verejnych trid, musi kayda mit svuj soubor