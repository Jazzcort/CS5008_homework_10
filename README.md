# Homework 10 - Binary Search Trees (BST)

Name: Chih-Tao Lee

Github Account name: jazzcort

How many hours did it take you to complete this assignment (estimate)? 
- About 2-3 hours.

Did you collaborate with any other students/TAs/Professors? If so, tell us who and in what capacity.  
- No, I completed this assignment on my own.


Did you use any external resources (you do not have to cite in class material)? (Cite them below)  
- No.


(Optional) What was your favorite part of the assignment? 

(Optional) How would you improve the assignment? 

## BST Questions

1. Given a *balanced* and *full* Binary Search Tree, what is the Big O for finding a value in the tree?
- For a balanced or full Binary Search Tree, the Big O for finding a value would depend on how many level this tree has. So the Big O would be $O(log(n))$
2. Define balanced in relation to BSTs. Remember to relate it to height. 
- A balanced Binary Search Tree means that the depth of the two subtrees of every node never differs by more than 1.
3. What is the Worst Case Big O for searching or adding to a BST?
   * What type of BST would this be? (how would it look)
   - The Worst Case Big O for searching and adding to a BST would be $O(n)$.
   - For adding, the worst case would be always adding a value that is smaller than the minimum value in the tree or always adding a value that is bigger than the maximum value in the tree. In this case, if we always add smaller value, we would end up having a BST looking like this.
   ```test
   data: [5,4,3,2,1]

            5
           /
          4
         /
        3
       /
      2
     /
    1
   ```
   - If we always add bigger values, we would end up having a BST looking like this.
   ```test
   data: [1,2,3,4,5]

    1
     \
      2
       \
        3
         \
          4
           \
            5
   ```
   - In both cases, if we want to add a new value (following the rule) to the BST, we have to traverse all the way to the most left node or the most right node of the tree, which make the Big O become $O(n)$.

   - For searching, due to we end up having a data structure similar to singly linked list, the Big O of searching would be $O(n)$.
4. What are some of the advantages of a BST over a linked list?
- In BST, the time complexity of search, insertion, and deletion is reduced to $O(log(n))$, which make it more efficient than linked list.
5. What are some cases / examples of when you would use a BST?
- Because BST is very efficient in searching and sorting data, it would mainly be implemented in the system that performs high amount of searching and sorting processes. For example, a routing table to store the IP addresses or an index table of a database.

