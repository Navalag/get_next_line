## get_next_line - the C function that returns a line ending with a newline, read from a file descriptor.

### Description:

It will get tricky to read data from a file descriptor if you don’t know its size beforehand.
What size should your buffer be? How many times do you need to read the file descriptor to retrieve the data?

As a programmers, we would want to read a “line” that ends with a line break from a file descriptor.
For example each command that is typed in shell or each line read from a flat file.

Thanks to the project get_next_line, it becomes possible to read a line ending with a newline character from a file descriptor.

This project is also about to learn a highly interesting concept in C programming:
static variables.

And gain a deeper understanding of allocations, whether they happen on the stack memory or in the heap memory,
the manipulation and the life cycle of a buffer, the unexpected complexity implied in the use of one or many static variables.

Please find more information about this project [here](https://github.com/Navalag/get_next_line/blob/master/get_next_line.en.pdf) in subject.

### Contact & contribute

To contact me, or fix/improve Get_Next_Line, feel free to mail me at a.galavan@icloud.com
