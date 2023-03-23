/** Implementation of the BST data structure 
 * 
 * @author Chih-Tao Lee
 * Semester Spring 2023
*/

#include "my_bst.h"


/**
 * This function would malloc a heap memory for a pointer of
 * Node with given value and return the address of this pointer.
*/
Node* create_node(int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) return NULL;

    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

/**
 * Checks to see if the tree is empty
 * by looking at the tree size.
 * returns true if the tree is empty.
 * False otherwise.
*/
bool bst_is_empty(BST *tree) {
    if (tree->size == 0) return true;

    return false;
}

/**
 * This is the helper function for bst_exists() which would be called
 * recursively to check if the given value exists in the given bst.
*/
bool bst_exists_helper(Node* node, int val) {
    if (node == NULL) return false;

    if (val > node->data) {
        return bst_exists_helper(node->right, val);
    } else if (val < node->data) {
        return bst_exists_helper(node->left, val);
    } else return true;
}

/**
 * Checks to see if the value exists in the tree.
 * returns true if the value exists in the tree.
 * False otherwise.
*/
bool bst_exists(BST *tree, int value)
{
    if (tree == NULL) return false;

    return bst_exists_helper(tree->root, value);
}

/**
 * Returns the size of the tree.
*/
unsigned int bst_size(BST *tree) {
    if (tree == NULL) return 0;
    return tree->size;
}

/**
 * This is the helper function for bst_add() which would be called
 * recursively until it find the proper spot to add a new node.
*/
int bst_add_helper(Node* node, int val) {
    if (val > node->data) {
        if (node->right == NULL) {
            node->right = create_node(val);
            if (node->right == NULL) return -1;
            return 1;
        } else {
            return bst_add_helper(node->right, val);
        }
    } else if (val < node->data) {
        if (node->left == NULL) {
            node->left = create_node(val);
            if (node->left == NULL) return -1;
            return 1;
        } else {
            return bst_add_helper(node->left, val);
        }
    } else {
        return 0;
    }
    
}

/**
 * Adds a value to the tree.
 * returns 1 if the value was added successfully.
 * returns 0 if the value already exists in the tree.
 * returns -1 if the value could not be added due to errors. (malloc failed)
*/
int bst_add(BST *tree, int value) {
    if (tree == NULL) return -1;

    if (bst_is_empty(tree)) {
        tree->root = create_node(value);
        if (tree->root == NULL) return -1;
        tree->size += 1;
        return 1;
    } else {
        int success = bst_add_helper(tree->root, value);
        if (success == 1) {
            tree->size += 1;
            return 1;
        } else return success;
    }
}

/**
 * This function would be called recursively to free the heap memory
 * of the given node and all its descendants.
*/
void free_node(Node* node) {
    if (node == NULL) return;

    free_node(node->left);
    free_node(node->right);
    free(node);
}

/**
 * Frees the memory allocated for the tree.
 * hint: Think about which order works for traversal (pre, in, post) and how that
 * can help you free the memory
*/
void bst_free(BST *tree) {
    if (tree == NULL) return;

    free_node(tree->root);
    free(tree);
}

/**
 * Creates a new BST.
 * returns a pointer to the new BST.
 * The root node will still be NULL until the first bst_add is called
*/
BST *create_bst() {
    BST* newBST = (BST*)malloc(sizeof(BST));
    if (newBST == NULL) return NULL;

    newBST->size = 0;
    newBST->root = NULL;

    return newBST;
}

