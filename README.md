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
4. What are some of the advantages of a BST over a linked list?
5. What are some cases / examples of when you would use a BST?

