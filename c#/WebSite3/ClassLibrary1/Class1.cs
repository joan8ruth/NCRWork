using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Entities;

namespace ClassLibrary1
{
    public class Class1
    {

        SqlConnection con = new SqlConnection(@"Data Source=hp-envy-4cfpq9m\sqlexpress;Initial Catalog=Register;Integrated Security=True");

        public User passwordValidation(int id, string password)
        {
            con.Open();
            User user = new User();
            String command = "Select * from user where id =" + id;
            SqlCommand cmd = new SqlCommand(command, con);

            user.Id = id;
            user.Password = null;
            using (SqlDataReader oReader = cmd.ExecuteReader())
            {
                while (oReader.Read())
                {
                    user.Name = oReader["name"].ToString();
                    user.Password = oReader["password"].ToString();
                    user.isEnabled= int.Parse(oReader["isEnabled"].ToString());
                    user.roleId = int.Parse(oReader["roleId"].ToString());
                    user.lastLogin = oReader["lastLogin"].ToString();
                }

                con.Close();
            }

            if(string.Equals(password, user.Password))

            {
                return user;
            }

            else
            {
                return null;
            }

        }

    }

    
}
