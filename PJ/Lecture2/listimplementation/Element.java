package PJ.Lecture2.listimplementation;

public class Element 
{
    public Element(Object data, Element next)
    {
        //vzdycky implementovat funkci v tele (rozdil od cpp)
        //this.data = data; //vem slozku (ignoruje parametr ktery je nahore)
        //this.next = next;

        setData(data);
        setNext(next);
    }

public Element() {this(null, null);};

    public final Object getData()
    {
        return data;
    }

    public final void setData(Object data)
    {
        this.data = data;
    }
    
    public final Element getNext()
    {
        return next;
    }

    public final void setNext (Element next)
    {
        this.next = next;
    }

    private Element next;
    private Object data;
    
}
