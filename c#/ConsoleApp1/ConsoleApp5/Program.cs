using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Net.WebRequestMethods;

namespace ConsoleApp5
{
    class Program
    {
        static void Main(string[] args)
        {

            // Program.DefferedExecution();
            // Program.AggregateMethod();
            // Program.PartitioningMethod();
            // Program.conversionMethod();
            Program.ElementMethod();
        }

        static void DefferedExecution()
        {

            List<int> numbers = new List<int> { 1, 2, 3, 4, 5, 6 };

            var result = from num in numbers
                         where num % 2 == 0
                         select num;
            numbers.Add(7);
            numbers.Add(8);

            foreach (var num in result)
            {
                Console.Write(num);
            }

        }

        static void AggregateMethod()
        {
            List<int> numbers = new List<int> { 1, 2, 3, 4, 5 };

            Console.WriteLine("Min is {0}", numbers.Min());

            Console.WriteLine("Max is {0}", numbers.Max());

            Console.WriteLine("Sum is {0}", numbers.Sum());

            Console.WriteLine("Count is {0}", numbers.Count());

            Console.WriteLine("Average is {0}", numbers.Average());

            Console.WriteLine("Aggregate is {0}", numbers.Aggregate((a, b) => a + b));

            //Console.WriteLine("Sorted is ")

        }

        static void example()
        {
            List<int> numbers = new List<int> { 1, 2, 3, 4, 5 };

            var evenResultSet = from num in numbers
                                where num % 2 == 0
                                select num;

            foreach(var evenNumber in evenResultSet)

            {
                Console.WriteLine(evenNumber.ToString());

            }

            employee e =new employee();

            var newSet = e.Where(eg => eg.gender == "Male").Select(employee => new { id = e.id, name = e.name });

        }

        static void PartitioningMethod()
        {

            List<string> strList = new List<string>(){"One","Two","Three","Hi","Four","Five"};

            var takeList = strList.Take(2);
            var skipList = strList.Skip(2);

            var takeWhileList = strList.TakeWhile(s => s.Length > 2);

            foreach (var str in takeWhileList)
            {
                Console.WriteLine(str);
            }

            foreach (var str1 in takeList)
            {
                Console.WriteLine(str1);
            }

            foreach (var str2 in skipList)
            {
                Console.WriteLine(str2);
            }

        }

        static void conversionMethod()
        {
            ArrayList list1 = new ArrayList();
            list1.Add(1);
            list1.Add(2);
            list1.Add("AA");

            var listResult = list1.OfType<int>();

            foreach(int i in listResult)
            {
                Console.WriteLine(i);

            }
        }

        public static void ElementMethod()
        {
            List<int> list = new List<int> { 1, 2, 3, 4 };

            Console.WriteLine("First element is {0}", list.First());

            Console.WriteLine("First element is {0}", list.FirstOrDefault());

            Console.WriteLine("First element is {0}", list.ElementAt(0));

            Console.WriteLine("First element is {0}", list.First());


        }

        public static void Quantifier()
        {
            List<int> list = new List<int> { 1, 2, 3, 6, 7 };


        }

        //static void groupingMethod()
        //{

        //    employee e = new employee();

        //    var groupSet = e.

        //}

    }



   public class employee
    {
        
        public string name { get; set; }
        public string gender { get; set; }
        public int id { get; set; }

        internal IEnumerable<employee> Where(Func<employee, bool> p)
        {
            throw new NotImplementedException();
        }
    }

    public class employeeList
    {
        public List<employee> employess = new List<employee>();

        public employeeList()
        {
            //employess.Add();
        }
    }
}
