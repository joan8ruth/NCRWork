using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using ConsoleApp1;


namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {

            Creator[] creators = new Creator[2];
            creators[0] = new ConcreteCreatorA();
            creators[1] = new ConcreteCreatorB();

            foreach(Creator creator in creators)
            {
                Product product = creator.FactoryMethod();
                Console.WriteLine("Created " + product.GetType().Name);
            }

            Console.Read();



        }
    }

    
}
