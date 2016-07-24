Given any binary tree, populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Example : 

```
Input Tree :
   	    1
       /  \
      2    3
     / \    \
    4   5    7

Resultant Tree : 

	    1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL

         
```
LeetCode : https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/