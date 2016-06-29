/*
cc10.2: How would you design the data structures for a very large social network like Facebook or LinkedIn? 
        Describe how you would design an algorithm to show the connection, or path, between two people(e.g.,
        Me->Bob->Susan->Jason->You).

Step 1: Simplify the Problem—Forget About the Millions of Users
    First, let's forget that we're dealing with millions of users. Design this for the simple case. We can 
construct a graph by treating each person as a node and letting an edge between two nodes indicate that the two 
users are friends. If I wanted to find the connection between two people, I would start with one person and do a
simple breadth first search.

Step 2: Handle the Millions of Users
    When we deal with a service the size of Linkedln or Facebook, we cannot possibly keep all of our data on one 
machine. That means that our simple Person data structure from above doesn't quite work—our friends may not live
on the same machine as we do. Instead, we can replace our list of friends with a list of their IDs, and traverse
as follows:
    1. For each friend ID: int machine_index = getMachineIDForUser(personID);
    2. Go to machine #machine_index
    3. On that machine, do: Person friend = getPersonWithID(person_id);
    The code below outlines this process. We've defined a class Server, which holds a list of all the machines, 
and a class Machine which represents a single machine. Both classes have hash tables to efficiently lookup data.

class server{
	//list of machine_index
	//person to machine map
}

class machine{
	//list of person ID
	//own machine ID
}

class person{
	//list of friends ID
	//own ID
}

Optimization: Reduce Machine Jumps
    Jumping from one machine to another is expensive. Instead of randomly jumping from machine to machine with 
each friend, try to batch these jumps—e.g., if five of my friends live on one machine, I should look them up all
at once.

Optimization: Smart Division of People and Machines
    People are much more likely to be friends with people who live in the same country as they do. Rather than 
randomly dividing people up across machines, try to divide them up by country, city, state, and so on. This will
reduce the number of jumps.

Question: Breadth First Search usually requires "marking" a node as visited. How do you do that in this case?
    Usually, in BFS, we mark a node as visited by setting a flag visited in its node class. Here, we don't want to
do that. There could be multiple searches going on at the same time, so it's bad to just edit our data. Instead, 
we could mimic the marking of nodes with a hash table to look up a node id and whether or not it's been visited.

*/