If reversing x causes the value to `go outside the signed 32-bit integer range [-231, 231 - 1],` then return 0.

- Use long for variables as it is indicating that values will go out during calculation;
- INT_MAX, INT_MIN for limits.

`when dealing with negative numbers` dont use x>0 as condition in while loop instead `use x!=0` 
