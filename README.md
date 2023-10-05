# Push_swap

## Overview

Push_swap is a sorting program that aims to efficiently sort data on a stack using a limited set of instructions while minimizing the number of actions. This project offered me the chance to manipulate various sorting algorithms and choose the most suitable solution for an optimized data sorting algorithm.

## Problem Description

- **Stacks**: The program operates with two stacks, namely `a` and `b`. These two stacks could be implemented as dynamically allocated arrays or as linked lists.
- **Initial State**:
  - Stack `a` contains a collection of negative and/or positive numbers, with no duplicates.
  - Stack `b` starts empty.
- **Objective**: Sort the numbers in stack `a` in ascending order.
- **Available Sorting Operations**:
  - `sa` (swap a): Swap the first two elements at the top of stack `a`.
  - `sb` (swap b): Swap the first two elements at the top of stack `b`.
  - `ss`: Perform `sa` and `sb` simultaneously.
  - `pa` (push a): Move the first element at the top of stack `b` to the top of stack `a`.
  - `pb` (push b): Move the first element at the top of stack `a` to the top of stack `b`.
  - `ra` (rotate a): Shift all elements of stack `a` up by one, making the first element the last.
  - `rb` (rotate b): Shift all elements of stack `b` up by one, making the first element the last.
  - `rr`: Perform `ra` and `rb` simultaneously.
  - `rra` (reverse rotate a): Shift all elements of stack `a` down by one, making the last element the first.
  - `rrb` (reverse rotate b): Shift all elements of stack `b` down by one, making the last element the first.
  - `rrr`: Perform `rra` and `rrb` simultaneously.

## Usage

To use the push_swap program, follow these instructions:

1. Compile the program.
2. Provide a list of integers as arguments to the program. The first argument should be at the top of stack `a`.

```shell
./push_swap 4 2 7 1 3
```

3. The program will display the smallest list of instructions needed to sort the stack a, with the smallest number at the top.

```shell 
sa
ra
...
```

4. Each instruction is separated by a newline (\n).

## Error Handling

- If no parameters are specified, the program will not display anything and return the prompt.
- In case of errors, such as non-integer arguments, values exceeding integer limits, or duplicate values, the program will display an "Error" message followed by a newline (\n) on the standard error.
