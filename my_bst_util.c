/** Implementation of BST utility functions
 *
 *  @author Chih-Tao Lee
 * Semester Spring 2023
 *
*/


#include "my_bst_util.h"

/**
 * This is the helper function for sum() which would be called 
 * recursively to sum up the value in each node.
*/
int sum_helper(Node* node) {
    if (node == NULL) return 0;

    return node->data + sum_helper(node->left) + sum_helper(node->right);
}

/**
 * Returns the sum of all the values in the tree.
*/
int sum(BST *tree) {
    if (tree == NULL) return 0;

    return sum_helper(tree->root); 
}


/**
 * This is the helper function for min() which would be called
 * recursively to find the most left node and return its value.
*/
int min_helper(Node* node) {

    if (node->left == NULL) return node->data;

    return min_helper(node->left);
    
}
/**
 * Returns the minimum value in the tree. 
*/
int min(BST *tree) {
    if (tree == NULL) return -1;

    if (tree->root == NULL) return -1;

    return min_helper(tree->root);
}

/**
 * This is the helper function for max() which would be called
 * recursively to find the most right node and return its value.
*/
int max_helper(Node* node) {

    if (node->right ==NULL) return node->data;

    return max_helper(node->right);
}
/**
 * Returns the maximum value in the tree.
*/
int max(BST *tree) {
    if (tree == NULL) return -1;

    if (tree->root == NULL) return -1;

    return max_helper(tree->root);
}
