using System;
using System.Collections.Generic;
using System.Data;
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



    protected void Button1_Click(object sender, EventArgs e)
    {

        ServiceReference1.Service1Client sc = new ServiceReference1.Service1Client();
        DataSet ds = sc.GetCustomerId(int.Parse(TextBox1.Text));

        if (ds.Tables.Count == 0)
        {
            
        }


    }
}