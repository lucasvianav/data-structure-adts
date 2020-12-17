#include <stdio.h>
#include "abb.h"

int main(){
    bst *tree = bst_new();

    bst_insert(tree, (item){135, "Titanic"});
    bst_insert(tree, (item){55, "Aladdin"});
    bst_insert(tree, (item){689, "Avatar"});
    bst_insert(tree, (item){86, "Matrix"});

    bst_print(tree);
    printf("%d\n", bst_getHeight(tree));

    printf("%s\n", bst_search(tree, 689));
    printf("%s\n", bst_search(tree, 7));

    bst_remove(tree, 86);
    bst_print(tree);
    printf("%d\n", bst_getHeight(tree));

    bst_delete(&tree);

    return 0;
}
