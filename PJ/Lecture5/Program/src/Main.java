
class Result
{
    private int value;
    public Result(int value)
    {
        this.value = value;
    }
    public Result()
    {
        this(Tools.RESULT);
    }
    @Override
    public String toString()
    {
        return "" + value;
    }
}

class Tools
{
    public static final int RESULT = 42;
    public static int maximum(int ... data) //definovale funkci metodu ktera je pole, pridat bud pole, anebo hodnoty ktere to daji do pole
    {
        int result = Integer.MIN_VALUE; //const velkymi s podtrzitkem
        for(int i:data)
        {
            if(i > result)
            {
                result = i;
            }
        }
        return result;
    }
}


public class Main {
    public static void main(String[] args)
    {
        System.out.println(new Result());
        int[] array = {4, 5, 2, 8};
        System.out.println(Tools.maximum(array));
        System.out.println(Tools.maximum(20,31,5,87,99,7,-4));
    }
}