using System;
using System.Collections.Generic;
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

        public Employee GetEmployeeById(int id)
        {

            SqlConnection con = new SqlConnection(@"Data Source=hp-envy-4cfpq9m\sqlexpress;Initial Catalog=ncrdb;Integrated Security=True");
            Employee e = new Employee();
            con.Open();
            String command = "Select * from emp where id =" + id;
            SqlCommand cmd = new SqlCommand(command, con);
            //cmd.ExecuteNonQuery();
            e.Id = id;
            using (SqlDataReader oReader = cmd.ExecuteReader())
            {
                while (oReader.Read())
                {
                    e.Name = oReader["name"].ToString();
                    e.Salary = oReader["salary"].ToString();
                }

                con.Close();
            }
            
            return e;
        }
       
    }

    
}
