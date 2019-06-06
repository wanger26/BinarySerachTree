#include <stdio.h>
#include <stdlib.h>
#include "bst.h"


void inOrder(BStree bst, int index);
void recursiveInsert(BStree bst, Key *key, int data, int index);

// Input: ’size’: size of an array
// Output: a pointer of type BStree,
// i.e. a pointer to an allocated memory of BStree_struct type
// Effect: dynamically allocate memory of type BStree_struct
// allocate memory for a Node array of size+1 for member tree_nodes
// allocate memory for an unsigned char array of size+1 for member is_free
// set all entries of is_free to 1
// set member size to ’size’;
BStree bstree_ini(int size) {
    BStree allocation = malloc(sizeof(Node)*(size+1)+sizeof(unsigned char)* (size+1));
    allocation->tree_nodes= malloc(sizeof(Node)*(size+1));
    allocation->is_free= malloc(sizeof(unsigned char)* (size+1));
    allocation->size=size;

    for (int index=0; index<=size; index++) allocation->is_free[index]='1';

    return allocation;
}
// Input: ’bst’: a binary search tree
// ’key’: a pointer to Key
// ’data’: an integer
// Effect: ’data’ with ’key’ is inserted into ’bst’
// if ’key’ is already in ’bst’, do nothing

void bstree_insert(BStree bst, Key *key, int data) {
    recursiveInsert(bst, key, data, 1); //calling on helper method to insert the node recursively
}

// Input: ’bst’: a binary search tree
// Effect: print all the nodes in bst using in order traversal
void bstree_traversal(BStree bst) {
    inOrder(bst, 1); //calling on a helper method to do the traversal of the tree recursively
}
// Input: ’bst’: a binary search tree
// Effect: all memory used by bst are freed
void bstree_free(BStree bst) {
    int index=0;
    for (index; index<=bst->size; index++){
        if (bst->is_free[index]!='1'){ //if its not 1, means the space is used therefore needs to be freed
            free(bst->tree_nodes->key->name);
            free(bst->tree_nodes->key);
        }
    }
    free(bst->is_free);
    free(bst);
}

//Helper Methods-----------------------------------------------

//Inserts a given key with its data in the bst keeping the tree's properties in tact
void recursiveInsert(BStree bst, Key *key, int data, int index){

    if (index <= bst->size){ //can only continue so long we are in bounds
         if (bst->is_free[index]=='1'){ //the base case is reached when we find an appropriate location which has not been used
            bst->tree_nodes[index].key=key;
            bst->tree_nodes[index].data=data;
            bst->is_free[index]='0';
        }
        else { //if we have not found a open location yet recurse on the appropriate side
            if (key_comp(*key, *bst->tree_nodes[index].key) <0){ //recurse on left subtree
                recursiveInsert(bst, key, data, (index*2));
            }
            else if (key_comp(*key, *bst->tree_nodes[index].key)>0) { //recurse on right subtree
                recursiveInsert(bst, key, data, (index*2+1));
            }

        }
    }


}

//Traverses a binary search tree in-order recursively
void inOrder (BStree bst, int index){

    if (index <= bst->size ) { //so long we are in bounds we can keep going
        if (bst->is_free[2 * index] != '1') { //if there is still a node to the left the recurse to it
            inOrder(bst, index * 2);
        }

        print_node(bst->tree_nodes[index]); //visit the node

        if (bst->is_free[2 * index + 1] != '1') { //visit the right subtree if there is one
            inOrder(bst, index * 2 + 1);
        }
    }

}