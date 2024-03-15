enum PointsOfTheCompass {North, South, East, West}

public class Main {

    static void info(PointsOfTheCompass direction)
    {
        switch(direction)
        {
            case North:
                System.out.println("It's cold outside");
                break;
            case South:
                System.out.println("It's soo hooot!");
                break;
            default:
                System.out.println("Nothing special :C");

        }
    }


    public static void main(String[] args) {
        System.out.println("Hello and welcome!");
        PointsOfTheCompass direction = PointsOfTheCompass.East;
        info(direction);
        System.out.println(direction);
        System.out.println(direction.ordinal());

    }
}