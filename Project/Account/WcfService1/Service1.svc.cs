using System;
using System.Collections.Generic;
using System.Data;
using System.Data.SqlClient;
using System.Linq;
using System.Runtime.Serialization;
using System.ServiceModel;
using System.ServiceModel.Web;
using System.Text;

namespace WcfService1
{
    // NOTE: You can use the "Rename" command on the "Refactor" menu to change the class name "Service1" in code, svc and config file together.
    // NOTE: In order to launch WCF Test Client for testing this service, please select Service1.svc or Service1.svc.cs at the Solution Explorer and start debugging.
    public class Service1 : IService1
    {
        public string GetData(int value)
        {
            return string.Format("You entered: {0}", value);
        }

        public CompositeType GetDataUsingDataContract(CompositeType composite)
        {
            if (composite == null)
            {
                throw new ArgumentNullException("composite");
            }
            if (composite.BoolValue)
            {
                composite.StringValue += "Suffix";
            }
            return composite;
        }

        //This returns data set of accounts for the entered customer ID 
        public DataSet GetCustomerId(int customerEnteredId)
        {
            SqlConnection con = new SqlConnection(@"Data Source=hp-envy-4cfpq9m\sqlexpress;Initial Catalog=Bank;Integrated Security=True");
            con.Open();

           
            SqlCommand cmd = new SqlCommand("SELECT * from Account where customerId="+customerEnteredId,con);

            SqlDataAdapter sda = new SqlDataAdapter(cmd);
            DataSet ds = new DataSet();
            sda.Fill(ds);

            return ds;
            
        }

        //This add an account into database
        public bool AddAccount(string[] EnteredDetails)
        {
            SqlConnection con = new SqlConnection(@"Data Source=hp-envy-4cfpq9m\sqlexpress;Initial Catalog=Bank;Integrated Security=True");
           
            SqlCommand cmd = new SqlCommand("addDetails",con);

            cmd.CommandType = System.Data.CommandType.StoredProcedure;

            cmd.Parameters.AddWithValue("@customerId", EnteredDetails[0]);
            cmd.Parameters.AddWithValue("@accountType", EnteredDetails[1]);
            cmd.Parameters.AddWithValue("@DateOfOpen", EnteredDetails[2]);
            cmd.Parameters.AddWithValue("@status", EnteredDetails[3]);
            cmd.Parameters.AddWithValue("@dateOfEdited", EnteredDetails[4]);
            cmd.Parameters.AddWithValue("@ClosingDate", EnteredDetails[5]);
            cmd.Parameters.AddWithValue("@amount", EnteredDetails[6]);

            con.Open();
            int result = cmd.ExecuteNonQuery();
            con.Close();

            if(result==0)
            {
                return false;
            }

            else
            {
                return true;
            }

        }

        //This updates edited values into database
        public bool EditAccount(Account selectedAccount)
        {
            SqlConnection con = new SqlConnection(@"Data Source=hp-envy-4cfpq9m\sqlexpress;Initial Catalog=Bank;Integrated Security=True");

            SqlCommand cmd = new SqlCommand("editedDetails", con);

            cmd.CommandType = System.Data.CommandType.StoredProcedure;

            cmd.Parameters.AddWithValue("@accountNo", selectedAccount.accountNo);
            cmd.Parameters.AddWithValue("@customerId", selectedAccount.customerId);
            cmd.Parameters.AddWithValue("@accountType", selectedAccount.accountType);
            cmd.Parameters.AddWithValue("@DateOfOpen", selectedAccount.DateOfOpen);
            cmd.Parameters.AddWithValue("@status", selectedAccount.status);
            cmd.Parameters.AddWithValue("@dateOfEdited", selectedAccount.dateOfEdited);
            cmd.Parameters.AddWithValue("@ClosingDate", selectedAccount.ClosingDate);
            cmd.Parameters.AddWithValue("@amount", selectedAccount.amount);

            con.Open();
            int result = cmd.ExecuteNonQuery();
            con.Close();

            if (result == 0)
            {
                return false;
            }

            else
            {
                return true;
            }
        }

        //This deletes row in the database
        public bool DeleteAccount(long accountNoToDelete)
        {
            SqlConnection con = new SqlConnection(@"Data Source=hp-envy-4cfpq9m\sqlexpress;Initial Catalog=Bank;Integrated Security=True");

            SqlCommand cmd = new SqlCommand("deleteDetails", con);

            cmd.CommandType = System.Data.CommandType.StoredProcedure;

            cmd.Parameters.AddWithValue("@accountNo", accountNoToDelete);

            con.Open();
            int result = cmd.ExecuteNonQuery();
            con.Close();

            if (result == 0)
            {
                return false;
            }

            else
            {
                return true;
            }
        }
    }
}
