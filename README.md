# Push swap
__an algorithmic project__
## Description
The Push_swap project is a very simple and highly effective algorithm project: data will
need to be sorted. You have at your disposal a set of int values, 2 stacks and a set of
instructions to manipulate both stacks.<br/>

Your goal ? Write 2 programs in C:
* The first, named ***checker*** which takes integer arguments and reads instructions on
the standard output. Once read, checker executes them and displays OK if integers
are sorted. Otherwise, it will display KO.
* The second one called ***push_swap*** which calculates and displays on the standard
output the smallest program using Push_swap instruction language that sorts integer
arguments received.

#### Push_swap instruction language:
* `sa` - swap a - swap the first 2 elements at the top of stack a. Do nothing if there
  is only one or no elements).
* `sb` - swap b - swap the first 2 elements at the top of stack b. Do nothing if there
  is only one or no elements).
* `ss` - sa and sb at the same time.
* `pa` - push a - take the first element at the top of b and put it at the top of a. Do
  nothing if b is empty.
* `pb` - push b - take the first element at the top of a and put it at the top of b. Do
  nothing if a is empty.
* `ra` - rotate a - shift up all elements of stack a by 1. The first element becomes
  the last one.
* `rb` - rotate b - shift up all elements of stack b by 1. The first element becomes
  the last one.
* `rr` - ra and rb at the same time.
* `rra` - reverse rotate a - shift down all elements of stack a by 1. The last element
  becomes the first one.
* `rrb` - reverse rotate b - shift down all elements of stack b by 1. The last element
  becomes the first one.
* `rrr` - rra and rrb at the same time.

#### Installation:
```bash
    git clone https://github.com/sashly/Push_swap.git push_swap
    cd ./push_swap
    make bonus
```
#### Usage:
```bash
  ./push_swap [-options] <numbers_list>
   Options:       --help     - help
                  -v         - visualize via minilibx
                  -a[1,2,3]  - alterative sort algorithms (bubble, insertion and selection sort)
                  -vc[1,2,3] - visualize algorithms compare
                  -va[1,2,3] - visualize alternative algorithm
```
#### Example:
```bash
  ./push_swap 2 1 3 6 5 8
  sa
  pb
  pb
  pb
  sa
  pa
  pa
  pa
  ./push_swap 0 one 2 3
  Error
  ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG
  OK
```
#### Visualization:


