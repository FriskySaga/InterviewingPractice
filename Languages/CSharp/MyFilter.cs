// Kevin Tran

/*
    •	Implement a function called myFilter that does the following:
    •	Takes a sequence of integers with values from 0 to 100
    •	Remove all multiples of 5 greater than 50
    •	Then cube each number
    •	Finally, remove any resulting integer that is even
*/

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Filter
{
    public class Program
    {
        public static IEnumerable<int> myFilter(IEnumerable<int> input)
        {
            var ret = input.Where(n => n % 5 != 0 && n <= 50).Select(y => y * y * y).Where(z => z % 2 == 1);
            return ret;
        }

        static void Main(string[] args)
        {
            Random rnd = new Random();
            var listForProblem =
                Enumerable.Range(1, 100).Select(i => rnd.Next() % 101);
            var answer = TestProblem1.myFilter(listForProblem);
            foreach (int i in answer)
            {
                Console.WriteLine(i);
            }
            // Keep the console window open in debug mode.
            Console.WriteLine("Press any key to exit.");
            Console.ReadKey();
        }
    }
}
