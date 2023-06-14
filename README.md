Exercise 1

The program takes input from a file called "index.in", where several words of the language appear in ascending order. The algorithm works by comparing the words 2 by 2 and identifying the characters that set the order of the words. Basically, it checks the letters on the same index/position until two distinct characters are found. If the words begin with different letters, it's simple, the first letter of the second word comes after the first's one in the alphabet. Otherwise, compares the second ones, third ones and so on.

Example:
ion
ana
------
(i, a) -> a comes after i

ana
adonia
-----------
(a, a)
(n, d) -> d comes after n


All the characters become nodes in a graph and an edge is represented by the two characters setting an order between words. The graph algorithm is a custom implementation made especially for this problem. The graph is displayed as an adjacency list.

Example:
o: d
d:
n: o d
a: n d
i: a

meaning: o->d, n->o, n->d, a->n, a->d, i->a.

The order of the characters is determined by using topological sorting, that is based on Kahn's algorithm. The indegree of each node/the number of edges that come in a node is computed. The indegree of a node describes the tendency of the words to be ordered sooner or later, if depending on the respective character. When the indegree of a letter is 0, it means that any other word will come after. The node will be added to a result list, be eliminated from the graph and from all the neighbours indegree will be subtracted 1. The procedure of finding the node with an indegree of 0 is repeated until the graph is emptied. If the number of letters at the beginning is not equal with the one in the final result then the input given is not valid. The final result will be written in a file named "index.out" and will represent all the characters in order.

Example:
ianod
