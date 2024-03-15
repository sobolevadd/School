public class Date {
    public Date(int day, int month, int year)
    {
        //this.day = day;
        setDay(day);
        setMonth(month);
        setYear(year);
    }

    public static boolean leapYear(int year)
    {
        return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
    }
    int serialNumberOfTheDay()
    {
        var result = numOfDaysBeforeTheBeginOfMonth[month] + day;
        if(leapYear(year) && month > 2) result++;
        return result;
    }

    public int getDay()
    {
        return day;
    }

    public final void  setDay(int day)
    {
        this.day = day;
    }

    public int getMonth()
    {
        return month;
    }

    public final void  setMonth(int month)
    {
        this.month = month;
    }

    public int getYear()
    {
        return year;
    }

    public final void setYear(int year)
    {
        this.year = year;
    }


    private int day, month, year;
    private static final int DAYSINMONTH[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    private static int[] numOfDaysBeforeTheBeginOfMonth = new int[13];
    static
    {
        numOfDaysBeforeTheBeginOfMonth[0] = 0;
        numOfDaysBeforeTheBeginOfMonth[1] = 0; //pocet dnu do zacatku ledna je nula
        for(int i =2; i <=12; i++)
        {
            numOfDaysBeforeTheBeginOfMonth[i] = numOfDaysBeforeTheBeginOfMonth[i-1] + DAYSINMONTH[i-1];

        }
    }
}
