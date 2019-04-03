using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp2
{
    class Program
    {
        static void Main(string[] args)
        {
            //creating a class
            example e = new example(2,"hi");
            e.printing();

            //out parameters
            int sum = AddSum(2, 3,5,1);

            Console.WriteLine("The value of sum with out parameter is "+sum);

            //reference type
            int x2 = 0;
            Adding(ref x2);
            Console.WriteLine("The value of ref is "+x2);

            //default parameters1
            int x3 = Adding1(2,8);
            Console.WriteLine("The value for default params is "+x3);

            //default parameters2
            int x4 = Adding2(2, 2,z:3);
            Console.WriteLine("The value for default params2 is " + x4);

            //inheritance
            FullTimeEmployee fe1 = new FullTimeEmployee();
            fe1.fName = "Joanna";
            fe1.lName = "Ruth";
            fe1.print();

            ContractEmployee c1 = new ContractEmployee();
            c1.fName = "J";
            c1.lName = "R";
            c1.print();

            Employee e1 = new FullTimeEmployee();
            e1.fName = "Jo";
            e1.lName = "Ru";
            e1.print();

            Employee e2 = new ContractEmployee();
            e2.fName = "Joey";
            e2.lName = "Ru";
            e2.print();

            Console.Read();
            
        }

        static int AddSum(int x, int y,params int[] ValueSet)
        {
            int sum = 0;
            if (ValueSet != null)

            {
                foreach(int items in ValueSet)
                {
                    sum = sum + items;
                }
            }
            
            return x + y + sum;
        }

        static int Adding1(int x,int y=0)
        {
            return x + y;
        }

        static int Adding2(int x, int y = 0,int z=0)
        {
            return x + y + z;
        }

        static void Adding(ref int y)
        {
            y = 10;
        }
    }

    class example
    {
        int num1;
        string s1;

        public example(int n,string s)
        {
            num1 = n;
            s1 = s;
        }

       public void printing()
        {
            Console.WriteLine(num1);
            Console.WriteLine(s1);
        }
    }

    class Employee
    {
        public string fName;
        public string lName;

       virtual public void print()
        {
            Console.WriteLine("The name is " + fName +" "+lName);
            

        }
    }

    class FullTimeEmployee : Employee
    {
        int salary;

        override 
        public void print()
        {
            Console.WriteLine("The name is " + this.fName + " " + this.lName + " --Full Time");

        }

    }

    class ContractEmployee : Employee
    {
        int salary;

        public void print()
        {
            Console.WriteLine("The name is " +this.fName + " " + this.lName + " -- Contract");


        }

    }


}
