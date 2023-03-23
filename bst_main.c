/**
 * Use this file to add your own tests and run a mini BST program.
 *
 * Things to test for...
 *
 * Fill a Binary Search Tree with values 1-100 and searching for nodes
 * Add 100 nodes and then check that the size is 100
 * Add 100 nodes with the value starting at 0 to 99, then check the sum of the tree to be 4950
 * etc...
 * (don't forget to check what happens in the null cases such as trying to find nodes that don't exist,
 * or any action on an empty tree...)
*/

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "my_bst.h"
#include "my_bst_util.h"


// a helper to get a range  of numbers
int *get_range_array(int start, int end) {
    int *arr = (int*) malloc(sizeof(int) * (end - start));
    int j = 0;
    for (int i = start; i < end; i++, j++) arr[j] = i;
    return arr;
}

// sample helper function to help you create random int arrays
int *get_random_array(int size) {
    int *arr = (int *)malloc(sizeof(int) * size);
    srand(time(NULL)); // seed the random number generator

    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }

    return arr;
}

// Test bst_add() and bst_size() with an arithmetic sequence 1,2,3,...,98,99,100.
int unitTest1(int status) {
    int passed = 0;

    BST* tree = create_bst();
    int* array = get_range_array(1, 101);

    for (int i = 0; i < 100; i++) {
        bst_add(tree, array[i]);
    }

    for (int i = 0; i <100; i++) {
        if (!bst_exists(tree, array[i])) {
            return passed;
        }
    }

    if (bst_size(tree) != 100) return passed;

    bst_free(tree);
    free(array);

    passed = 1;
    return passed;
}

// Test sum(), min(), max() with an arithmetic sequence 0,1,2,3,...,98,99.
int unitTest2(int status) {
    int passed = 0;

    BST* tree = create_bst();
    int * array = get_range_array(0, 100);

    for (int i =0; i < 100; i++) {
        bst_add(tree, array[i]);
    }

    if (sum(tree) != 4950) return passed;

    if(min(tree) != 0) return passed;

    if (max(tree) != 99) return passed;

    bst_free(tree);
    free(array);

    passed = 1;
    return passed;
}

// Test min() and max() with random arrays.
int unitTest3(int status) {
    int passed = 0;

    BST* tree = create_bst();
    int* array = get_random_array(50);

    int maximum = INT_MIN;
    int minimum = INT_MAX;
    for (int i = 0; i < 50; i++) {
        bst_add(tree, array[i]);
        if (array[i] > maximum) maximum = array[i];

        if (array[i] < minimum) minimum = array[i];
    }

    if (min(tree) != minimum) return passed;

    if (max(tree) != maximum) return passed;

    bst_free(tree);
    free(array);

    passed = 1;
    return passed;
}

// Test a few boundary cases (empty tree and passing null as a tree).
int unitTest4(int status) {
    int passed = 0;

    BST* tree = create_bst();

    if (!bst_is_empty(tree)) return passed;

    if (bst_exists(NULL, 1)) return passed;
    if (bst_exists(tree, 1)) return passed;

    if (bst_size(NULL) != 0) return passed;
    if (bst_size(tree) != 0) return passed;

    if (bst_add(NULL, 1) != -1) return passed;
    if (bst_add(tree, 1) != 1) return passed;
    if (bst_add(tree, 1) != 0) return passed;

    bst_free(tree);

    passed = 1;
    return passed;
}

// Test sum(), min(), and max() with boundary cases (empty tree and passing null as a tree).
int unitTest5(int status) {
    int passed = 0;

    BST* tree = create_bst();

    if (sum(NULL) != 0) return passed;
    if (sum(tree) != 0) return passed;

    if (min(NULL) != -1) return passed;
    if (min(tree) != -1) return passed;

    if (max(NULL) != -1) return passed;
    if (max(tree) != -1) return passed;

    bst_free(tree);

    passed = 1;
    return passed;
}

int (*unitTests[])(int) = {
    unitTest1,
    unitTest2,
    unitTest3,
    unitTest4,
    unitTest5,
    NULL};

int main(int argc, char const *argv[])
{
    unsigned int testsPassed = 0;
    
    int counter = 0;
    while (unitTests[counter] != NULL)
    {
        printf("========unitTest %d========\n", counter + 1);
        if (1 == unitTests[counter](1))
        {
            printf("passed test\n");
            testsPassed++;
        }
        else
        {
            printf("failed test, missing functionality, or incorrect test\n");
        }
        counter++;
    }

    printf("%d of %d tests passed\n", testsPassed, counter);
   
}
