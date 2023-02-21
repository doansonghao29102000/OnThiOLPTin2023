using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace BaiTap5
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void btnCong_Click(object sender, EventArgs e)
        {

            //txtKetQua.Text = int.Parse(txtA.Text) 
            //    + int.Parse(txtB.Text)+"";

            //int a, b;
            //a = int.Parse(txtA.Text);
            //b = int.Parse(txtB.Text);
            //txtKetQua.Text = (a + b).ToString();

            int a=0, b=0;
            int.TryParse(txtA.Text, out a);
            int.TryParse(txtB.Text, out b);
            if ((a==0)&&(txtA.Text.Trim()!="0"))
            {
                MessageBox.Show(" Vui lòng nhập lại số thứ nhất",
                    "Thông báo", MessageBoxButtons.OK, MessageBoxIcon.Error);
                txtA.Focus();
                txtA.SelectAll();
            }
            else if ((b == 0) && (txtB.Text.Trim() != "0"))
            {
                MessageBox.Show(" Vui lòng nhập lại số thứ hai",
                    "Thông báo", MessageBoxButtons.OK, MessageBoxIcon.Error);
                txtB.Focus();
                txtB.SelectAll();
            } else

            txtKetQua.Text = (a + b).ToString();
        }

        private void txtA_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Enter)
                txtB.Focus();
        }

        private void txtB_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode==Keys.Enter)
            btnCong.Focus();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            cbToanTu.Items.Add("+");
            cbToanTu.Items.Add("-");
            cbToanTu.Items.Add("*");
            cbToanTu.Items.Add("/");

            cbToanTu.SelectedIndex = 0;
        }
        private void Tinh()
        {
            int a = 0, b = 0;
            int.TryParse(txtA.Text, out a);
            int.TryParse(txtB.Text, out b);
            if ((a == 0) && (txtA.Text.Trim() != "0"))
            {
                MessageBox.Show(" Vui lòng nhập lại số thứ nhất",
                    "Thông báo", MessageBoxButtons.OK, MessageBoxIcon.Error);
                txtA.Focus();
                txtA.SelectAll();
            }
            else if ((b == 0) && (txtB.Text.Trim() != "0"))
            {
                MessageBox.Show(" Vui lòng nhập lại số thứ hai",
                    "Thông báo", MessageBoxButtons.OK, MessageBoxIcon.Error);
                txtB.Focus();
                txtB.SelectAll();
            }

            if (cbToanTu.Text.Trim() == "+")
                txtKetQua.Text = (a + b).ToString();
            else if (cbToanTu.Text.Trim() == "-")
                txtKetQua.Text = (a - b).ToString();
            else if (cbToanTu.Text.Trim() == "*")
                txtKetQua.Text = (a * b).ToString();
            else if (b != 0)
                txtKetQua.Text = ((double)a / b).ToString();
        }
        private void btnTinh_Click(object sender, EventArgs e)
        {
            Tinh();
        }

        private void cbToanTu_SelectedIndexChanged(object sender, EventArgs e)
        {
            if ((txtA.Text.Trim()!="")&&(txtB.Text.Trim()!=""))
            Tinh();
        }

        private void btnThoat_Click(object sender, EventArgs e)
        {
            MessageBox.Show(int.MaxValue.ToString());
        }
    }
}
