
public class Main {
    private static void doCheck(Controllable controlledObject)
    {
        controlledObject.check();
        //Point p =(Point)controlledObject; //for text output error, for points works normally
    }

    private static void call(Showcase showcase)
    {
        System.out.println(showcase.calculate(5));
    }

    public static void main(String[] args)
    {
        System.out.println(Controllable.AMOUNT);
        Point p = new Point(0,0);
        File f = new File("Heeey");
        File f2 = new File(null);
        doCheck(p);
        doCheck(f);
        doCheck(f2);
        p.defaultControl();
        Controllable.message("Testing interface");
        doCheck(()->{System.out.println("The showing of lambda-function");});
        call((x)-> x+1); //call((int x)->{return x+1;});
    }
}