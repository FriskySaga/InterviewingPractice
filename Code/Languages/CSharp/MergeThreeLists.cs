/*
 * Kevin Tran
 * COP4020
    •	Implement a function called merge that does the following:
    •	Takes three sequences of numbers from 1 to 15
    •	Merge the list with members that adhere to the following requirements
    •	Any multiple of 3
    •	Is a member of all three lists
    Explanation: First get a list of multiples of three from all three lists (no repeats)
    Then combine the list of threes with the intersection of all three lists (no repeats)
 */

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    public class Program
    {
        public static IEnumerable<int> merge(IEnumerable<int> input1, IEnumerable<int> input2, IEnumerable<int> input3)
        {
            List<int> commonList = input1
              .Intersect(input2)
              .Intersect(input3)
              .Where(x => x % 3 == 0)
              .ToList();

            return commonList;
        }

        static void Main(string[] args)
        {
            Random rnd = new Random();

            var list1 = Enumerable.Range(1, 10).Select(i => (rnd.Next() % 15) + 1);
            var list2 = Enumerable.Range(1, 10).Select(i => (rnd.Next() % 15) + 1);
            var list3 = Enumerable.Range(1, 10).Select(i => (rnd.Next() % 15) + 1);

            var answer = Program.merge(list1, list2, list3);

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
