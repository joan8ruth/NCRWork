using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using ServiceReference1;




public partial class _Default : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {

    }

    protected void TextBox2_TextChanged(object sender, EventArgs e)
    {

    }

    protected void Button1_Click(object sender, EventArgs e)
    {
        
        ServiceReference1.Service1Client sc = new ServiceReference1.Service1Client();
        Employee emp = sc.GetEmployeeById(int.Parse(TextBox4.Text));
        TextBox2.Text = emp.Name;
        TextBox3.Text = emp.Salary;
    }

   
}