using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using ClassLibrary1;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {

            int? num1 = null;
            int? num2 = 45;
            Boolean b;

            int[] array1 = new int[] {4,5,6};

            Console.Write("Enter the values for array\n");

            foreach(int items in array1)
            {
                Console.WriteLine(items);
            }

            b = num2 == 45 ? true : false;

            Console.WriteLine(b);

            Console.WriteLine("values are " + num1 + " " + num2);

            Console.WriteLine("welcome");
            
            Class1.PrintToConsole();

            Console.WriteLine("the max is "+System.Int32.MaxValue);
            Console.WriteLine(System.Int32.MinValue);
            Console.WriteLine(System.Boolean.FalseString);
            Console.WriteLine(System.Boolean.TrueString);

            Console.Read();
        }

        private void TestMethod()
        {
            Console.WriteLine("welcome in the method");
            Console.Read();
        }
    }
}
