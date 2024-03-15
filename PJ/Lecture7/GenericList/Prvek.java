

public class Prvek<T> 
{
    private T data;
    private Prvek další;
    
    public Prvek(T data, Prvek další)
    {
        setDalší(další);
        setData(data);
    }

    public Prvek getDalší() 
    {
        return další;
    }

    public void setDalší(Prvek další) 
    {
        this.další = další;
    }

    public T getData() 
    {
        return data;
    }

    public void setData(T data) 
    {
        this.data = data;
    }
    
}
