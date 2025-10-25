#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

int main() {
    LinkedList *l = create();
    for(int i = 0; i < 10; i++) appendLast(l, i);

    printf("%d\n", removeValue(l, 1));
    print(l);

    destroy(l); // sempre destruir depois de terminar
}
