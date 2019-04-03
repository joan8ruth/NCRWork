using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp3
{
    class Program
    {
        static void Main(string[] args)
        {
            //calling parameterised super from base
            Base b = new Base();
            
            //using properties
            TimePeriod tp = new TimePeriod();
            tp.Hours = 2;
            Console.WriteLine("the seconds is " +tp.Hours);

            Console.Read();

        }
    }

    class Parent
    {
        public Parent()
        {
            Console.WriteLine("In parent constructor");
        }

        public Parent(String s)
        {
            Console.WriteLine("in parameterised constructor");

        }

    }

    class Base : Parent
    {
        public Base() : base("called from derived")
        {
            Console.WriteLine("In child constructor");
        }

    }

    class TimePeriod
    {
        private double _seconds;

        public double Hours
        {
            get
            {
                return _seconds/3600 ;
            }
            set
            {
                    _seconds = value * 3600;
                
            }
        }
    }
}
