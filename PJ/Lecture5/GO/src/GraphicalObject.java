public abstract class GraphicalObject
{
    private int color;

    public GraphicalObject(int color) {
        setColor(color);
    }

    public final int getColor() {
        return color;
    }

    public final void setColor(int color) {
        this.color = color;
    }

    @Override
    public String toString()
    {
        return "[" + getColor() + "]";
    }

    public abstract void draw();
//    {
//        //System.out.println(this);
//        System.out.print("[" + getColor() + "]");
//    }

}
