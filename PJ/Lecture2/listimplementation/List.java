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
        Element tmp = head;
        while (tmp !=tail)
        {
            System.out.print(tmp.getData() + ", ");
            tmp = tmp.getNext();
        }
    }
    private Element head;
    private Element tail;
}
