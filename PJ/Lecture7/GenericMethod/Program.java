

class Nástroje
{
    public void pozdrav()
    {
        System.out.println("Nazdar");
    }
    public static <T> T medián(T[] data)
    {
        return data[data.length/2];
    }
    public static <T extends Comparable /*& Cloneable*/> T maximum(T a, T b)
    { 
        return a.compareTo(b) >= 0 ? a : b;
    }
}

public class Program 
{
    public static void main(String[] args) 
    {
        Integer[] pole={1,2,3,4,5};
        System.out.println(Nástroje.medián(pole));
        System.out.println(Nástroje.maximum(5, 9));
        System.out.println(Nástroje.maximum(5.9, 9.5));
        System.out.println(Nástroje.maximum("Nazdar", "Ahoj"));
    }
    
}
