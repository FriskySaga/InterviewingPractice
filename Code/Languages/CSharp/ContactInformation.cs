/*
 * Kevin Tran
 * COP4020
    Create a C# console application.
    Use the following data structure(you may amend this structure as needed):
    public struct contactInfo
    {
        public string firstName, lastName;
        public string address, city, state;
    }
    Ask the user to enter contact information.Populate a newly-instantiated contactInfo data structure as the
    user enters the information.Use a method named askForContactInfo().
    Add the data structure to a linked list.
    After the user enters each contact information, tell them to enter either “quit” or anything else to continue.
    After they are done (they entered quit), display all of the contacts in a method named displayContacts().
 */

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GettingStartedWithCSharp
{
    public struct contactInfo
    {
        public string firstName, lastName;
        public string address, city, state;

        public contactInfo (string first, string last, string addr, string town, string st)
        {
            firstName = first;
            lastName = last;
            address = addr;
            city = town;
            state = st;
        }
    }

    public class Node
    {
        public contactInfo data;
        public Node next;

        public Node (contactInfo i)
        {
            data = i;
            next = null;
        }

        public void AddToEnd(contactInfo data)
        {
            if (next == null)
            {
                next = new Node(data);
            }
            else
            {
                next.AddToEnd(data);
            }
        }

        public void Print()
        {
            Console.Write("{" + data.firstName + ", " + data.lastName + ", " +
                data.address + ", " + data.city + ", " + data.state + "} -> ");
            if (next != null)
            {
                next.Print();
            }
            else
            {
                Console.Write("NULL");
            }
        }
    }

    public class MyList
    {
        public Node headNode;

        public MyList()
        {
            headNode = null;
        }

        public void AddToEnd(contactInfo data)
        {
            if (headNode == null)
            {
                headNode = new Node(data);
            }
            else
            {
                headNode.AddToEnd(data);
            }
        }

        public void Print()
        {
            if (headNode != null)
            {
                headNode.Print();
            }
        }
    }

    class ContactInformation
    {
        public static void askForContactInfo(MyList list)
        {
            ConsoleKeyInfo quitSentinel;
            do
            {
                // Get user input for contact information.
                Console.WriteLine("==========================");
                Console.WriteLine("Please enter your contact information!\n");

                Console.Write("Enter your first name: ");
                String firstName = Console.ReadLine();
                
                Console.Write("Enter your last name: ");
                String lastName = Console.ReadLine();

                Console.Write("Enter your address: ");
                String address = Console.ReadLine();

                Console.Write("Enter your city: ");
                String city = Console.ReadLine();

                Console.Write("Enter your state: ");
                String state = Console.ReadLine();

                // Populate contactInfo data structure.
                contactInfo contacts = new contactInfo(firstName, lastName, address, city, state);

                // Add newly instantiated data structure to the back of the linked list.
                list.AddToEnd(contacts);

                Console.WriteLine("\nIf you would like to stop entering contact information, press the Escape button." +
                    "\nOtherwise, press any button to continue.");
                quitSentinel = Console.ReadKey();
            } while (quitSentinel.Key != ConsoleKey.Escape);
            Console.WriteLine("\n");
        }

        public static void displayContacts(MyList list)
        {
            list.Print();
        }

        static void Main()
        {
            MyList list = new MyList();
            askForContactInfo(list);
            displayContacts(list);

            // Keep the console window open in debug mode.
            Console.WriteLine();
            Console.WriteLine("Press any key to exit.");
            Console.ReadKey();
        }
    }
}
