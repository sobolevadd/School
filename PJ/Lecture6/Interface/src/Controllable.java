public interface Controllable
{
    final int AMOUNT = 21;
    void check();

    default void defaultControl()
    {
        System.out.println("Default control has been done!");
    }

    static void message(String text)
    {
        System.out.println("Jupii!!! The message was delivered: " + text + ".");
    }
}

interface Showcase
{
    int calculate(int m);
}