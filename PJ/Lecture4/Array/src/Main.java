
public class Main
{

    public static void print(int[] array)
    {
        for(int i : array)
        {
            System.out.print(i + " ");
        }
        System.out.println();
    }
    public static void main(String[] args)
    {
        System.out.println("Hello and welcome to our special calendar!");
        Date today = new Date(4,10,2023);
        /*for(int i: Date.numOfDaysBeforeTheBeginOfMonth)
        {
            System.out.println(i);
        }*/
        //System.out.println(Date.leapYear(2020));
        System.out.println("Depends on the day that you chose in code, today's serail number of the day in the year:");
        System.out.println(today.serialNumberOfTheDay());



        System.out.println();
        System.out.println();
        System.out.println("***** Easy examples of arrays clones *****" );
        System.out.println();
        System.out.println("You have an array and you want to make a clone, maybe change some objects in array;)");
        int[] A = {1, 2, 3, 4};
        int[] B;
        B = A.clone();
        B[1] = 8;
        System.out.println("Your array:");
        print(A);
        System.out.println("The clone array with some changes:");
        print(B);
        System.out.println("One more clone:");
        var C = java.util.Arrays.copyOf(A, A.length);
        print(C);
        int[][] Matrix = {{1,2},{3,4}};
    }
}

//private pouze metody teto tridy
//public
//defaultni/friendly pristup, sdileno v ramci baliku