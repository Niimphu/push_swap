# push_swap
push_swap is in interesting project that dives into sorting algorithms, complexity and efficiency. The student is given a stack of random numbers labelled stack '**a**', an empty stack '**b**', and a set of commands that may be used to manipulate the values. They are then tasked to sort the numbers in stack '**a**' into ascending order using only what's given. The commands are as follows:

sa (swap a):	Swap the first 2 elements at the top of stack a.
				Do nothing if there is only one or no elements.
sb (swap b):	Swap the first 2 elements at the top of stack b.
				Do nothing if there is only one or no elements.
ss : 			sa and sb at the same time.
pa (push a): 	Take the first element at the top of b and put it at the top of a.
				Do nothing if b is empty.
pb (push b): 	Take the first element at the top of a and put it at the top of b.
				Do nothing if a is empty.
ra (rotate a):	Shift up all elements of stack a by 1.
				The first element becomes the last one.
rb (rotate b):	Shift up all elements of stack b by 1.
				The first element becomes the last one.
rr :			ra and rb at the same time.
rra (reverse rotate a):
				Shift down all elements of stack a by 1.
				The last element becomes the first one.
rrb (reverse rotate b):
				Shift down all elements of stack b by 1.
				The last element becomes the first one.
rrr :			rra and rrb at the same time.