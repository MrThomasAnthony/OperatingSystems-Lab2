Documentation for Boss and Worker Programs

Overview
This project implements a boss-worker computing model in C, where the boss process creates multiple worker processes. The workers are responsible for finding prime numbers within specific ranges, while the boss divides the range and delegates tasks to the workers.

Files:
boss.c: The boss program that creates worker processes and assigns ranges for each worker.
worker.c: The worker program that finds prime numbers in a given range of integers.

  1. boss.c
Purpose:
The boss program is responsible for:

Dividing the range from 1 to a specified upper bound into equal parts.
Creating a specified number of worker processes using fork() and execl().
Assigning each worker a distinct subset of the range to search for prime numbers.
The boss program terminates after creating the workers and does not participate in further calculations.

How It Works:
The program takes two command-line arguments:

number_of_workers: How many worker processes to create.
upper_bound: The upper limit of the range (starting from 1) to search for prime numbers.
Each worker receives a subset of the range, calculated based on the number of workers.

The boss uses the execl() system call to start each worker process, passing the range (lower and upper bounds) as arguments to the worker.

Compilation:
To compile boss.c, use the following command:

    gcc boss.c -o boss -lm
    ./boss <number_of_workers> <upper_bound>

Example:
To create 4 workers to find primes from 1 to 300:

    ./boss 4 300
This will divide the range from 1 to 300 across 4 workers as follows:

    Worker 1: 1 to 75
    Worker 2: 76 to 150
    Worker 3: 151 to 225
    Worker 4: 226 to 300

2. worker.c
Purpose:
The worker program calculates and prints all prime numbers within a specified range of integers.

How It Works:
The worker program takes two command-line arguments:

lower_bound: The lower bound of the range.
upper_bound: The upper bound of the range.
The worker checks each number in this range to determine whether it is prime, using a basic prime-checking algorithm that tests divisibility up to the square root of the number.

Compilation:
To compile worker.c, use the following command:

    gcc worker.c -o worker -lm
    ./worker <lower_bound> <upper_bound>

Example:
To find all prime numbers between 1 and 10:

    ./worker 1 10
This will output:

    Primes: 2 3 5 7
