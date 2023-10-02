import static java.lang.Math.*;
import java.util.ArrayList;

public class Main
{
    static String greeting(int n)
    {
        switch(n)
        {
            case 0: return "Hi"; //case -> "Hi"
            case 1: return "Good mo:>";
            case 2: return "Adiooos";
            //default:throw new Exception(" Undefined value");
            default:
                try {
                    throw new Exception(" Undefined value");
                } catch (Exception e) {
                    throw new RuntimeException(e);
                }
        }
    }
    static ArrayList<String> data = new ArrayList<>();
    public static void main(String[] args)
    {
        data.add("Hi");
        data.add("Good evening!");
        for (String i: data ) //projdi vsechny data v poli, prikaz ktery umoznuje projit cely kontejner
        {
            System.out.println(i);
        }
        int j = 0;
        cyklus: for (String i: data )
        {
            j++;
            System.out.println(i);
            if(j == 1) break cyklus; //pouzivame u vnorenych cyklu, ukoncuje
        }
        //System.out.println(greeting (2));
        try // za try musi byt catch nebo finally, finally jenom jednou, catch kolikrat chceme. pak proberem jak to muzeme udelat bez finally anebo catch
        {
            System.out.println(greeting (6));
            System.out.println("Nice!");
        }
        catch (Exception ex)
        {
         //Logger.getLogger(Main.src.getName () ).log(level.SEVERE, null, ex);
            System.out.println("Error " + ex.getMessage());
        }
        finally
        {
            System.out.println("End!!");
        }
        //if(podminka) {}



//        do
//        {
//
//        } while(condition)


//        int i = 8;
//        {
//            //double i = 0; NO
//        }

//        byte i = 9;
//        short j = 10;
//        int k = 90;
//        long l = 500_000L;
//        l = i;
//        i = (byte)j;
//        boolean b = true;
//        char c = '\n';
//        c = '\u0015';
//        k = c;
//        c = (char)i;
//        float x = 3.14f;
//        double y = 2.71;
//        y = sin(x);
//        Object o;
//        o = 5;
//        System.out.println(o.toString());
//        int a = (int)o;
//        int i;
//        i = 6;
//        i++;
//        {};;;;

    }
}
