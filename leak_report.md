# Leak report


Within check_whitespace.sh: 

*strip creates the *char variable result, which grabs some memory.
After it does some stuff to result. It returns result.

This means that the memory is never unallocated.

To unallocate it, we have to free it up.
But result's memory address is kept a const, therefore to free it, we need to free the variable form of its address.


Within check_whitespace_test.sh:

Since *strip creates that memory using variable...

We have to free that memory.

So for each of the tests, they need to create a variable that stores the result
This result is then freed once we do the specific test.
