package PJ.Lecture2.listimplementation;

public class List {
    public List ()
    {
        head = tail = new Element();
    }
    public void pushFront (Object data)
    {
        head = new Element(data, head);
    }
    public boolean empty()
    {
        return head == tail;
    }
    public void print ()
    {
        if(empty())
        {
            System.out.println("Empty list :(");
            return;
        }
        Element actual = head;
        while (actual !=tail)
        {
            System.out.print(actual.getData() + ", ");
            actual = actual.getNext();
        }
    }
    private Element head;
    private Element tail;
}
