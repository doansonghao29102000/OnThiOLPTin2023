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
    public partial class Form2 : Form
    {
        public Form2(string b, string c)
        {
            InitializeComponent();
            txtA.Text = b;
            txtB.Text = c;
        }

        private void btnGiaiPT_Click(object sender, EventArgs e)
        {
            double a, b;
            a = double.Parse(txtA.Text);
            b = double.Parse(txtB.Text);
            if (a == 0)
                if (b==0)
                txtKetQua.Text = "Phương trình vô số nghiệm";
                else
                    txtKetQua.Text = "Phương trình vô nghiệm";
            else
                txtKetQua.Text = -b/a+"";
        }

        private void Form2_Load(object sender, EventArgs e)
        {

        }
    }
}
