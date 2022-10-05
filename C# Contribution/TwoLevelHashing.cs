using System;
using System.Collections.Generic;

namespace HashingInCSharp_b_
{
    class HASH
    {
       private Random rnd = new Random();
       private  ulong[] hashTables;
       private ulong p;
       private ulong a;
       private ulong b;
       private ulong m;
       private ulong tries;
        
       //constructor
       public HASH(ulong size)
        {
            p = 18361375334787046697;             //max 64 bit largest prime number
            a = (ulong)rnd.Next() % (p - 1) + 1;  //a in the range[1,p-1]
            b = (ulong)rnd.Next() % (p - 1);      //b in the range[0,p-1]
            m = size;
            tries = 0;
            hashTables = new ulong[m];             //individual hashtable
            for (ulong i = 0; i < m; i++)          //initially all hashtable have 0. 
            {
                hashTables[i] = 0;
            }
        }
       public void insertIntoTable(ulong[] arr, ulong x)
        {
            ulong index = ((a * arr[x] + b) % p) % m;              //getting hashed index
            Console.WriteLine("minor index: " + index + "\n");   
            if (hashTables[index] == 0)                  //this index in this hashtable does not have any value before?
            {
                hashTables[index] = arr[x];               //keep this key in hashtable
            }
            else
            {
                Console.WriteLine("\nRehashing needs::");
                reHashTable(arr, x, true);
            }
        }
       public void reHashTable(ulong[] arr, ulong x, bool collision)
        {
            //base case
            if (collision == false)
            {
                return;
            }
            else
            {
                tries++;                                        //rehashing increases one try.
               ulong maxNum = (ulong)Math.Pow(2, 64) - 1 - m;   //getting max value in 64 bit system but greater than size
                collision = false;

                //generate random numbers in the range [maxNum] untill you get prime number 
                do
                {
                   p = ((ulong)rnd.Next() % maxNum) + m;
                } while (!isPrime(p));


                //needs different a and b to reduce collision
                a = (ulong)rnd.Next() % (p - 1) + 1;
                b = (ulong)rnd.Next() % (p - 1);


                //getting all those values in temp list which has been hashed.
                //so that these values can be rehashed according to new a and b values.

                List<ulong> temp = new List<ulong>();
                for (ulong i = 0; i < m; i++)
                {
                    if (hashTables[i] != 0)
                    {
                        temp.Add(hashTables[i]);
                        hashTables[i] = 0;               //make this hashtable empty
                    }
                }
                temp.Add(arr[x]);                       //add key to be inserted in temp list 
                Console.WriteLine("after rehashing::");

                //place each value again in hashtable according to new a and b
                foreach(ulong i in temp)
                {
                    ulong index = ((a * i + b) % p) % m;        //generate new index
                    Console.WriteLine("minor index::"+index);
                    if (hashTables[index] == 0)                 //no collision?
                        hashTables[index] = i;
                    else
                    {
                        collision = true;                   //collision
                        break;
                    }
                }
                reHashTable(arr, x, collision);               //again needs to rehashing(depending on collision variable)?
            }

        }

        //checking if the generatecd random number is prime or not?
       public bool isPrime(ulong n)
        {
            for (ulong i = 2; i <= n / i; ++i)
            {
                if (n % i == 0)
                {
                    return false;
                }
            }
            return true;
        }


        //display you each hashtable individually
        public void displayTable()
        {
            for (ulong i = 0; i < m; i++)
            {
                if(hashTables[i]!=0)
                Console.Write(hashTables[i] + " -- ");
            }
            Console.WriteLine();
        }

        //how many times rehashing called?
        public ulong totalTries()
        {
            return tries;
        }
        
        //find key in constant time using hash function
        public void searchKey(ulong key)
        {
            ulong minorKeyindex = ((a * key + b) % p) % m;
            if (hashTables[minorKeyindex] == 0)
            {
                Console.WriteLine("Key not found.\n");
            }
            else
            {
                Console.WriteLine(hashTables[minorKeyindex] +" found at index " + minorKeyindex);
            }
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            ulong size;
            Console.Write("Enter size(how many random numbers you want to get?): ");
            size = ulong.Parse(Console.ReadLine());
            
            //generate random numbers
            ulong[] randomNums = new ulong[size];
            //Console.WriteLine("Random numbers::");
            Random rnd = new Random();
            for (ulong i = 0; i < size; i++)
            {
                randomNums[i] = (ulong)rnd.Next();
                //Console.WriteLine(randomNums[i]);
            }

            //making array of hashtables in which each cell has its own hashtable.
            HASH[] majorArr = new HASH[size]; 
            for(ulong i = 0; i < size; i++)
            {
                majorArr[i] = new HASH(size);
            }

            //getting parameters of hash function for major array  
            ulong p = 18361375334787046697;
            ulong a = (ulong)rnd.Next() % (p - 1) + 1;      
            ulong b = (ulong)rnd.Next() % (p - 1);

           

            Console.WriteLine("\n\nPERFECT HASH TABLE :: ");
            for (ulong i = 0; i < size; i++)
            {
                ulong index = ((a * randomNums[i] + b) % p) % size;
                Console.WriteLine("major index:" + index + "\n");
                majorArr[index].insertIntoTable(randomNums, i);
                majorArr[index].displayTable();

            }
            
            for (ulong i = 0; i < size; i++)
            {
                ulong index = ((a * randomNums[i] + b) % p) % size;
                ulong position = i + 1;
                Console.WriteLine("Total collision for hashtable present at position " + position + ": "+ majorArr[index].totalTries());
            }

            Console.WriteLine("\n\n*************SEARCHING*************");
            //searching
            ulong key;
            Console.Write("Enter key to search in hash table:");
            key = ulong.Parse(Console.ReadLine());
            ulong keyMajorIndex = ((a * key + b) % p) % size;
            majorArr[keyMajorIndex].searchKey(key);
            
        }
    }
}
