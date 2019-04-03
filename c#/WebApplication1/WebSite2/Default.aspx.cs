using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Net.Http;


public partial class _Default : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {

    }

    protected void Button1_Click(object sender, EventArgs e)
    {
        using (HttpClient client = new HttpClient())
        {

            var response = client.GetAsync("");
            response.Wait();

            //var result = response.result.Content.ReadAsStringAsync();
            //TextBox1.Text = result.Result;

           
            

        }
    }

    protected void TextBox1_TextChanged(object sender, EventArgs e)
    {

    }
}