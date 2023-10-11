public class File implements Controllable
{
    public File (String text)
    {
        this.text = text;
    }

    @Override
    public void check()
    {
        if(text == null)
        {
            System.out.println("Text is not provided...");
        }
    }

    @Override
    public void defaultControl()
    {
        System.out.println("Default control of file.");
    }

    private String text;
}
