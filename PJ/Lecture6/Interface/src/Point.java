public class Point implements Controllable
{
    public Point(int x, int y) {
        setX(x);
        setY(y);
    }

    @Override
    public void check()
    {
        if((x <= 0) || (y <= 0))
        {
            System.out.println("The point is not OKAAY :((");
            System.out.println(AMOUNT);
        }
    }

    public int getX() {
        return x;
    }

    public void setX(int x) {
        this.x = x;
    }

    public int getY() {
        return y;
    }

    public void setY(int y) {
        this.y = y;
    }

    private int x;
    private int y;
}
