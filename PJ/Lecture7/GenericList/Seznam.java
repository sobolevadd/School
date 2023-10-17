
public class Seznam<T>
{
    public Seznam()
    {
        hlava = zarážka = new Prvek<>(null, null);
    }
    
    public void vyprázdni()
    {
        hlava = zarážka;
    }
    
    public void vložNaZačátek(T data)
    {
        hlava = new Prvek<>(data, hlava);
    }
    
    public void výpis()
    {
        for(Prvek pom = hlava; pom != zarážka; pom = pom.getDalší())
        {
            System.out.print(pom.getData() + ", ");
        }
    }
    
    private Prvek<T> hlava;
    private Prvek<T> zarážka;
}
