using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace BaiTap9
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void btnGiaiPT_Click(object sender, EventArgs e)
        {
            // trường hợp PT có hệ số a = 0
            if (txtA.Text.Trim() == "0")
            {
                Form2 frmGPTB1 = new Form2(txtB.Text, txtC.Text);
                this.Hide();
                frmGPTB1.ShowDialog();
                this.Show();
                
            }
            else
            {
                double delta, a, b, c, x1, x2;
                a = double.Parse(txtA.Text);
                b = double.Parse(txtB.Text);
                c = double.Parse(txtC.Text);
                delta = b * b - 4 * a * c;

                if (delta<0)
                {
                    txtX1.Text = "Phương trình vô nghiệm trong R";
                    txtX2.Visible = false;
                    lbX2.Visible = false;
                    lbX1.Text = " Kết quả ";

                } 
                else if (delta==0)
                {
                    lbX1.Text = "X1 = ";
                    lbX2.Text = "X2 = ";
                    lbX2.Visible = true;
                    txtX2.Visible = true;

                    x1 = (-b + Math.Sqrt(delta)) / (2 * a);
                    txtX1.Text = x1.ToString();
                    txtX2.Text = x1.ToString();
                    
                }
                else
                {
                    lbX1.Text = "X1 = ";
                    lbX2.Text = "X2 = ";
                    lbX2.Visible = true;
                    txtX2.Visible = true;

                    x1 = (-b + Math.Sqrt(delta)) / (2 * a);
                    x2 = (-b - Math.Sqrt(delta)) / (2 * a);
                    txtX1.Text = x1.ToString();
                    txtX2.Text = x2 + "";
                }

            }
        }
    }
}
