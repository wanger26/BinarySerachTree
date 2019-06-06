//    printf("Please Enter the size of the tree: " );
//    scanf(" %d", &sizeOfTree);
//    bst= bstree_ini(sizeOfTree); //creating binary search tree
//
//    printf("\nPlease Enter parameters: ");
//
//    int moreData=1;
//    while(moreData==1){
//        printf("\nPlease Enter parameters: ");
//        scanf("%s %d %d", name, &id, &data);
//        bstree_insert(bst, key_construct(name, id), data);
//        printf("Enter 1 to enter another set of parameters: ");
//        scanf("%d", &moreData);
//    }

//
#include <stdio.h>
#include "bst.h"
int main(void) {
    BStree bst;
    int id, data, sizeOfTree;
    char name[256];

    bst=bstree_ini(1000);



    while ( scanf("%s %d %d", name, &id, &data)== 3) { //while the file or the user has more input
        bstree_insert(bst, key_construct(name, id), data);
    }

    bstree_traversal(bst);
    bstree_free(bst);


    return 0;
}