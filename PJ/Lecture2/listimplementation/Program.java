package PJ.Lecture2.listimplementation;

public class Program {
    
    public static void main(String[] args)
    {
        List list = new List();
        list.pushFront(5);
        list.pushFront(3.14);
        list.pushFront("Hello");
        list.print();
    }
}
