
## Part 1: 

Write a C/C++ language program on Linux that creates an array of 10,000 random unsigned integers in the range 1 to 1,000,000. 
These integers are then stored in a text file called numbers.txt

## Part 2: 

Write a C/C++ language program on Linux that reads the file numbers.txt and checks each number for being a prime number. 
Only the prime numbers from these are then written to a text file prime.txt. 

## Part 3: 

Modify the program of part 2 so that it takes an input argument num_jobs with a value between 1 and 8. 
E.g. if num_jobs is 3, it splits into 3 parallel processes using fork() function and each process then 
calculates prime numbers from a subset of the input data. Together these 3 jobs find prime numbers from 
all the 10,000 input integers. The overall parent process then combines the results from its children 
into a single file prime.txt

## Part 4: 

Calculate the times taken by running the program of part 3, and make a table where the time taken for 
calculation is given for each value of num_jobs from 1 to 8. A breakdown of the time should be given - 
file reading, prime number calculation, and file writing.
