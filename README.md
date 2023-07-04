# Linked List and Recursion Project

## Description

Linked List & Recursion is a program that demonstrates various operations on a linked list data structure using recursion. It includes functionalities such as inserting nodes, sorting the list in ascending or descending order, counting prime numbers within the list, and printing fractal patterns.

## Function Behaviors

- `get_length()`: Returns the length of the linked list.
- `print()`: Prints the elements of the linked list.
- `clear()`: Clears the linked list.
- `push_front()`: Inserts a node at the front of the list.
- `push_back()`: Inserts a node at the back of the list.

## insert()

- Able to insert a node in the middle of the list.
- Able to insert a node at the front of the list (index 0).
- Able to insert a node at the back of the list (index equal to the list's length).
- Does not insert the node if the provided index is invalid (greater than the size).

## Sorting

- `sort_ascending()`: Uses recursive merge sort algorithm to sort the list in ascending order.
- `sort_descending()`: Uses recursive selection sort algorithm to sort the list in descending order.

## count_prime()

- Counts the number of prime numbers within the linked list.

## Fractals

- `pattern(int n, int col)`: Recursively prints n stars starting at column col. Works for the `pattern(7,0)` call.
- Prints fractals for any positive number of stars shifted over col columns (no error handling needed).

## Running the Program

1. Clone the repository or download the source code files.
2. Ensure that you have a C++ compiler installed on your system.
3. Open a terminal or command prompt and navigate to the project directory.
4. Compile the program using the provided makefile.
5. Run the compiled executable.

## Limitations

- The program assumes valid input for function calls and does not perform extensive error handling.

## Algorithm and Complexity

- `sort_ascending()`: Implements the recursive merge sort algorithm. The runtime complexity is O(n log n) in the average and worst case scenarios.
- `sort_descending()`: Implements the recursive selection sort algorithm. The runtime complexity is O(n^2) in the average and worst case scenarios.
- `count_prime()`: Iterates through the linked list and checks the primality of each element. The runtime complexity is O(n^2) in the worst case scenario.
