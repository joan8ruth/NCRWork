
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data;
using System.Data.SqlClient;



public partial class _Default : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {

    }

    protected void Button1_Click(object sender, EventArgs e)
    {
        SqlConnection con = new SqlConnection(@"Data Source=HP-ENVY-4CFPQ9M\SQLEXPRESS;Initial Catalog=ncrdb;Integrated Security=True");
        con.Open();
        String command = "INSERT INTO [dbo].[studentinfo]([sid],[snam],[pno],[email],[addr]) VALUES " + "('" +
            TextBox1.Text + "','" + TextBox2.Text + "','" + TextBox3.Text + "','" + TextBox4.Text + "','" + TextBox5.Text + "')";
        SqlCommand cmd = new SqlCommand(command, con);
        cmd.ExecuteNonQuery();
        con.Close();


    }
    

    protected void Button2_Click1(object sender, EventArgs e)
    {
        TextBox1.Text = string.Empty;
        TextBox2.Text = string.Empty;
        TextBox3.Text = string.Empty;
        TextBox4.Text = string.Empty;
        TextBox5.Text = string.Empty;

    }

    protected void Button3_Click(object sender, EventArgs e)
    {
        SqlConnection con = new SqlConnection(@"Data Source=HP-ENVY-4CFPQ9M\SQLEXPRESS;Initial Catalog=ncrdb;Integrated Security=True");
        String query = "retrieve_details";
        SqlCommand command1 = new SqlCommand(query, con);
        command1.CommandType = System.Data.CommandType.StoredProcedure;
        SqlDataAdapter da = new SqlDataAdapter(command1);
        DataSet ds = new DataSet(); 
        da.Fill(ds);
        GridView1.DataSource = ds.Tables[0];
        GridView1.DataBind();

    }

    protected void Button4_Click(object sender, EventArgs e)
    {
        SqlConnection con = new SqlConnection(@"Data Source=HP-ENVY-4CFPQ9M\SQLEXPRESS;Initial Catalog=ncrdb;Integrated Security=True");
        con.Open();
        String query = "delete_detail";
        
        SqlCommand command1 = new SqlCommand(query, con);

        SqlParameter p1 = new SqlParameter("@deleteId", TextBox1.Text);

        command1.Parameters.Add(p1);

        command1.CommandType = System.Data.CommandType.StoredProcedure;

        command1.ExecuteNonQuery();

        con.Close();

    }
}