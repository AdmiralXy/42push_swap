## push_swap

### About

This program sorts data in a stack with a limited set of instructions using the least possible number of steps. To be successful, it can manipulate different types of algorithms and choose the most appropriate solution for optimized data sorting.

The push_swap is a very simple and highly effective algorithm project: data will need to be sorted. We have at disposal a set of int values, 2 stacks and a set of instructions to manipulate both stacks.

External functions: write, read, malloc, free, exit.

All functions are created in accordance with [Norm](https://github.com/42School/norminette) - the bunch of rules how code should be formatted.

### Rules

We have 2 stacks named 'a' and 'b'.
* To start with:
  * Stack 'a' contains a random number of either positive or negative numbers without
  any duplicates.
  * Stack 'b' is empty
  * The goal is to sort in ascending order numbers into stack a.
* To do this we have the following operations at disposal:
  * sa : swap a - swap the first 2 elements at the top of stack a. Do nothing if there
  is only one or no elements).
  * sb : swap b - swap the first 2 elements at the top of stack b. Do nothing if there
  is only one or no elements).
  * ss : sa and sb at the same time.
  * pa : push a - take the first element at the top of b and put it at the top of a. Do
  nothing if b is empty.
  * pb : push b - take the first element at the top of a and put it at the top of b. Do
  nothing if a is empty.
  * ra : rotate a - shift up all elements of stack a by 1. The first element becomes
  the last one.
  * rb : rotate b - shift up all elements of stack b by 1. The first element becomes
  the last one.
  * rr : ra and rb at the same time.
  * rra : reverse rotate a - shift down all elements of stack a by 1. The last element
  becomes the first one.
  * rrb : reverse rotate b - shift down all elements of stack b by 1. The last element
  becomes the first one.
  * rrr : rra and rrb at the same time.

The program display the smallest list of instructions possible to sort the stack 'a', the smallest number being at the top.

### Requirements & usage
Project requires:
* C Lang compiler: **gcc** or **clang**
* Possibility to work with Makefile

Tested on:
* MacOS 10.15
* Linux Ubuntu 20.04

Run:
```
$> make all
$> ./push_swap 2 1 3 6 5 8
sa
pb
pb
pb
sa
pa
pa
pa
```

### Makefile commands

* make / make all / make push_swap - compile project
* make *.o - compile specific source file
* make clean - clean all object files
* make fclean - clean all object files & library
* make norme - check that all functions are created in accordance with Norm