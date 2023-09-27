namespace WinFormsApp1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private double m = 5.2;

        private void button1_Click(object sender, EventArgs e)
        {
            button1.Text = "Click again :)";
            int n = 7;
            textBox1.AppendText ("Something " + n + " " + m + "\r\n");
            m++;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            
            Form1 f = new Form1();
            f.Visible = true;
        }

        private void button3_Click(object sender, EventArgs e)
        {
            button3.Text = "Do NOT click again!!!";
        }
    }
}