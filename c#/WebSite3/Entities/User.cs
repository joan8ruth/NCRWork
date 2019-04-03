using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entities
{
    public class User
    {
        public int Id { get; set; }
        public string Password { get; set; }
        public string Name { get; set; }
        public int isEnabled { get; set; }
        public int roleId { get; set; }
        public string lastLogin { get; set; }
    }
}
