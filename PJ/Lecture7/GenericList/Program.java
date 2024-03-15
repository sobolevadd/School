

public class Program 
{
    public static void main(String[] args) 
    {
        /*Prvek<Integer> prvek = new Prvek<>(8, null);
        System.out.println(prvek.getData());
//        Object o = new Object(); 
//        prvek.setData(o);    // Nelze
        */
        Seznam<Integer> seznam = new Seznam<>();
        seznam.vložNaZačátek(2);
        seznam.vložNaZačátek(3);
        seznam.vložNaZačátek(4);
        seznam.výpis();
    }
    
}
