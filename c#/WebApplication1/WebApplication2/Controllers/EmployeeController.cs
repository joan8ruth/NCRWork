using System;
using System.Collections.Generic;
using System.Data;
using System.Data.SqlClient;
using System.Linq;
using System.Net;
using System.Net.Http;
using System.Web.Http;

namespace WebApplication2.Controllers
{
    public class EmployeeController : ApiController
    {
        

        public Employee Get(int id)
        {
            SqlConnection con = new SqlConnection(@"Data Source=hp-envy-4cfpq9m\sqlexpress;Initial Catalog=ncrdb;Integrated Security=True");
            Employee e = new Employee();
            con.Open();
            String command = "Select * from emp where id =" + id;
            SqlCommand cmd = new SqlCommand(command, con);
            //cmd.ExecuteNonQuery();
            e.ID = id;
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

        public void Get()
        {
           

        }

        public void Post([FromBody] Employee emp)
        {

        }

    }

    public class Employee
    {
        public int ID { get; set; }

        public string Name { get; set; }

        public string Salary { get; set; }
    }
}
