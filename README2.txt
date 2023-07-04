Description:

This program will model a Linked List. Multiple functions will incluided that can do a variety of things.
The Linked List model will consist of "nodes," or steps of a list, that point to each other creating a sort
of chain link. The front of the list will be the first "pointer" and be called "head." The program will also
undergoe a series of tests that show whether the Linked List implementation was successful or not (Hint: it was successful!).

Instructions:

1. Compile the program with

make

2. Run the program with

./linkedlist

3. The program will go through 5 different tests. After each one simply press hte enter key to continue.

The first test will say with "Test 1 Passed" or "Test 1 Failed." Test 1 checks the ability of the program
to get the length of the linked list.

Tests 2.1, 2.2, and 2.3 will show you actual and expected output. For example, for test 2.1 which tests the
function that inserts a new node at the beginning of a list, it might print:

        **********Test 2***********
        Adding nodes...
        Test 2.1: Testing push_front()
        Expected: 16 -8 0 100 5
        Actual  : 16 -8 0 100 5
        Expected length: 5
        Actual length  : 5
        Test 2.1 completed.

Test 2.2 checks the ability to add a node to the end of the list, and test 2.3 checks the abiltiy to add a node
anywhere in the middle of the list.

Likewise, tests, 3.1 and 3.2 check for the ability to sort from least to greatest (ascending) and greatest to least
(descending). Example output for test 3.1 can be as follows:

        **********Test 3***********
        Sorting...
        Test 3.1: Testing sort_ascending()
        Expected: -8 0 1 2 5 5 7 9 11 16 50 100 7919
        Actual  : -8 0 1 2 5 5 7 9 11 16 50 100 7919
        Test 3.1 completed.

To finish, test 4 will check the ability to count the prime numbers in the list, and test 5 will check the ability to
clear the entire list.

Remember, to continue after each test, press the enter key after you are prompted by:

        Press <enter> to continue...

4. Limitations:
- You cannot customize the list to what you want
- You cannot create your own tests
- No user input is needed besides the space bar
- Output will not change for each run of the program

6. (Part 2 only) Complexity analysis: For each of the following function, explain the 
algorithm you used and the Big O for runtime complexity 
a. sort_ascending()

Merge Sort:

Big O: O(nlog(n))

The merge sort function uses the divide and conquer technique, which means it has to split
up the size "n" or in this case the size of the linked list, until the split up elements are
each of size 1. How many split are there? Well, since 2 to the power of some number equals the size "n"
we can say 2^x=n. This can be written as a log like this: x=log(n) (we don't need to specify the base).
Therefore, the numer of "splits" or "levels" is log(n). How much time total do the elements within each
"split" or "level" take. Well, we can quickly find a pattern. The first "level" will be with no "split" and "n"
elements. We can use a constant "c" multiplied by "n" to show the variance by platform. The runtime will therefore
be "cn." The second "level" will be with 1 "split" and contain two sets of "n/2" elements. Combining these, we still
get "cn" since "2n/2" equals "n." The third "level" is the same run time of "cn," since "3n/3" equals "n." We quickly see that each
level has a runtime of "cn." Using this fact with the fact we found earlier that there are log(n) number of levels, we can multiply
them together to get the runtime complexity of "cnlog(n)." For our purposes we can ignore the constant, so the Big O for runtime
complexity is O(nlog(n)).

b. sort_descending()

Merge Sort:

Big O: O(nlog(n))

The descending version of this funciton has the exact same runtime complexity because the only difference is the order it sorts it.
Everything else is done the same, so the Big O for runtime complexity is O(nlog(n)).

c. count_prime()

Best case Big O: O(n)

Worst Case Big O: O(n^2)

Algorithm: My count_prime function loops through each element and checks if its prime using the is_prime function.
So, we already see that the number of times the is_prime function will be called is based on the size "n." The is_prime
function first checks if the number is less than or equal to 1, in which case it will return as not a prime number.
It will then go through each number from 2 to half of the number argument, seeing if any of those numbers divide evenly.
If for one of the numbers it divides evenly, it also returns as not a prime number. However, if it goes this part of the
function, it will return as a prime number.

We can see that the best case is where every number is 1 or less, which means only one comparison has to be done for each of
the "n" times is_prime is called - O(n). The worst case is where every number is prime, in which case (n/2 - 2) somparisons
will be done. For our purposes we can ignore the constants and coefficient here and find that the worst case is - O(n^2).