public class Abscissa extends GraphicalObject{


    private Point begin;
    private Point end;

    public Point getBegin() {
        return begin;
    }

    public void setBegin(Point begin) {
        this.begin = begin;
    }

    public Point getEnd() {
        return end;
    }

    public void setEnd(Point end) {
        this.end = end;
    }

    public Abscissa(int color, Point begin, Point end) {
        super(color);
        setBegin(begin);
        setEnd(end);
    }

    public Abscissa(Abscissa abscissa)
    {
        super(abscissa.getColor());
        Point begin = new Point(abscissa.getColor(), abscissa.getBegin().getX(), abscissa.getBegin().getY());
        // takhle vytvorime kopie toho bodu
        Point end = new Point(abscissa.getColor(), abscissa.getEnd().getX(), abscissa.getEnd().getY());
        setBegin(begin);
        setEnd(end);
        //lokalni kopie bodu, ze kterych pak vyrobime prusecku, normalne by se mel delat u kazde veci kopirovaci konstruktor
    }

    @Override
    public String toString() {
        return super.toString() + "<" + begin.toString() + ";" + end.toString() + ">";
    }

    @Override
    public void draw()
    {
        super.draw();
        System.out.print("<" + begin.toString() + ";" + end.toString() + ">" );
    }
}
