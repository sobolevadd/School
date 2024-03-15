
public class Program 
{
    public static int faktoriál(int n) throws Exception
    {
        if(n<0) throw new Exception("Záporná parametr faktoriálu");
        int výsledek = 1;
        while(n>1)výsledek *= n--;
        return výsledek;
    }
    public static void main(String[] args) 
    {
        try
        {
            System.out.println(faktoriál(5));
        }
        catch(Exception ex)
        {
            System.out.println(ex.getMessage());
        }
        finally
        {
            System.out.println("Hotovo");
        }
            
    }
    
}
