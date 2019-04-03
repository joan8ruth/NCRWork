using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using ClassLibrary1;
using Entities;

namespace Business
{
    public class UserBIZ
    {
        public User vlidateUser(int userid,string password)
        {
            Class1 obj = new Class1();
            User objuser=obj.passwordValidation(userid, password);
            return objuser;

        }
    }
}
