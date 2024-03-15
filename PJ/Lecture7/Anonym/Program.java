
interface Zpracování
{
    void zpracuj(int n);
}

class Nástroj
{
    public void vypiš(int n){}
    public void vypiš2(int n){}
}

public class Program 
{
    public static void práce(Zpracování zpracování, int n)
    {
        zpracování.zpracuj(n);
    }
    
    public static void main(String[] args) 
    {
        Zpracování pokus = new Zpracování() 
        {
            @Override
            public void zpracuj(int n) 
            {
                System.out.println(n);
            }
        };
        práce(pokus, 5);
        práce((n)->{System.out.println(n);}, 6);
        Nástroj nástroj = new Nástroj()
        {
           @Override
           public void vypiš(int n)
           {
               System.out.println("Toto je parametr: " + n);
           }
        };
        nástroj.vypiš(6);
    }
    
}
