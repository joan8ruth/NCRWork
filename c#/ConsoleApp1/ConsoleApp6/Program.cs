using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp6
{
    class Program
    {
        static void Main(string[] args)
        {

            SqlConnection con = new SqlConnection(@"Data Source=HP-ENVY-4CFPQ9M\SQLEXPRESS;Initial Catalog=ncrdb;Integrated Security=True");
            con.Open();


        }
    }
}
