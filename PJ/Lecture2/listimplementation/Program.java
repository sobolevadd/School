package PJ.Lecture2.listimplementation;

public class Program {
    
    public static void main(String[] args)
    {
        List list = new List();
        list.pushFront(5);
        list.pushFront(3.14);
        list.pushFront("Hello");
        list.pushFront(new Numero(10));
        list.print();
    }
}

class Numero
{
    private int numero;
    public Numero(int n)
    {
        numero = n;
    }

    @Override       //anotace
    public String toString ()
    {
        return "" + numero;
    }
}