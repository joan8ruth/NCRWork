using System;
using System.Collections.Generic;
using System.Data;
using System.Diagnostics;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using ServiceReference1;


public partial class _Default : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
        Label2.Text = "";
        AccountTypeLabel.Visible = false;
        AccountTypeTextBox.Visible = false;
        DateOfOpeneningLabel.Visible = false;
        DateOfOpeneningTextBox.Visible = false;
        StatusLabel.Visible = false;
        StatusTextBox.Visible = false;
        DateOfEditedLabel.Visible = false;
        DateOfEditedTextBox.Visible = false;
        ClosingDateLabel.Visible = false;
        ClosingDateTextBox.Visible = false;
        AmountLabel.Visible = false;
        AmountTextBox.Visible = false;
        DetailsSubmitButton.Visible = false;
        EditedDetailsSubmitButton.Visible = false;
        
    }



    protected void Button1_Click(object sender, EventArgs e)
    {

        ServiceReference1.Service1Client sc = new ServiceReference1.Service1Client();
        DataSet ds = sc.GetCustomerId(int.Parse(CustomerIdTextBox.Text));

        if (ds.Tables[0].Rows.Count == 0)
        {
            Label2.Text = "No Accounts available";
            GridView1.DataSource = ds;
            GridView1.DataBind();

        }

        else
        {
            Label2.Text = "Accounts available are";
            GridView1.DataSource = ds;
            GridView1.DataBind();
            
        }


    }
    

    protected void Button2_Click(object sender, EventArgs e)
    {

        if (string.IsNullOrWhiteSpace(CustomerIdTextBox.Text))
        {
            Label2.Text = "Please enter customer Id to add account";
        }
        else
        {
            AccountTypeLabel.Visible = true;
            AccountTypeTextBox.Visible = true;
            DateOfOpeneningLabel.Visible = true;
            DateOfOpeneningTextBox.Visible = true;
            StatusLabel.Visible = true;
            StatusTextBox.Visible = true;
            DateOfEditedLabel.Visible = true;
            DateOfEditedTextBox.Visible = true;
            ClosingDateLabel.Visible = true;
            ClosingDateTextBox.Visible = true;
            AmountLabel.Visible = true;
            AmountTextBox.Visible = true;
            DetailsSubmitButton.Visible = true;
        }


    }

    protected void DetailsSubmitButton_Click(object sender, EventArgs e)
    {
        bool returnValue;
        string[] Details = {CustomerIdTextBox.Text,
                            AccountTypeTextBox.Text,
                            DateOfOpeneningTextBox.Text,
                            StatusTextBox.Text,
                            DateOfEditedTextBox.Text,
                            ClosingDateTextBox.Text,
                            AmountTextBox.Text};

        ServiceReference1.Service1Client sc = new ServiceReference1.Service1Client();
        returnValue = sc.AddAccount(Details);
        
        

        if(returnValue)
        {
             Label2.Text = "Account Added";
        }

        else
        {
            Label2.Text = "Account not Added";
        }
  
    }

    protected void EditButton_Click(object sender, EventArgs e)
    {
        string selectedRecord;

        selectedRecord = GetSelectedRecord();
        if(selectedRecord==null)
        {
            Label2.Text = "Please select an account to edit!!";
        }

        else
        {
           
            Label2.Text = selectedRecord;
            
            AccountTypeLabel.Visible = true;
            AccountTypeTextBox.Visible = true;
            DateOfOpeneningLabel.Visible = true;
            DateOfOpeneningTextBox.Visible = true;
            StatusLabel.Visible = true;
            StatusTextBox.Visible = true;
            DateOfEditedLabel.Visible = true;
            DateOfEditedTextBox.Visible = true;
            ClosingDateLabel.Visible = true;
            ClosingDateTextBox.Visible = true;
            AmountLabel.Visible = true;
            AmountTextBox.Visible = true;
            EditedDetailsSubmitButton.Visible = true;
           
        }

    }

    private string GetSelectedRecord()
    {
        string returnValue;
        for (int i = 0; i < GridView1.Rows.Count; i++)
        {
            RadioButton rb = (RadioButton)GridView1.Rows[i].Cells[0].FindControl("RadioButton1");
            if (rb != null)
            {
                if (rb.Checked)
                {
                    returnValue = GridView1.Rows[i].Cells[1].Text;
                    return returnValue.Replace("$", "");
                }
            }
        }

        return null;
    }

    protected void EditedDetailsSubmitButton_Click(object sender, EventArgs e)
    {
        string accountNo;
        bool returnValue;
        Account editedAccount = new Account();


        accountNo = Label2.Text;
        editedAccount.accountNo = Convert.ToInt64(Label2.Text) ;
        editedAccount.customerId = int.Parse(CustomerIdTextBox.Text);
        editedAccount.accountType = AccountTypeTextBox.Text;
        editedAccount.DateOfOpen = DateOfOpeneningTextBox.Text;
        editedAccount.status = StatusTextBox.Text;
        editedAccount.dateOfEdited = DateOfEditedTextBox.Text;
        editedAccount.ClosingDate = ClosingDateTextBox.Text;
        editedAccount.amount = int.Parse(AmountTextBox.Text);
        



        ServiceReference1.Service1Client sc = new ServiceReference1.Service1Client();
        returnValue = sc.EditAccount(editedAccount);
        
        if (returnValue)
        {
            Label2.Text = "Account Edited successfully";
        }

        else
        {
            Label2.Text = "Account not edited!!";
        }

    }
}