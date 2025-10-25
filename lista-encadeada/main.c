#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

int main() {
    LinkedList *l = create();
    for(int i = 100; i > 0; i--) appendLast(l, i);

    printf("%d", length(l));

    destroy(l); // sempre destruir depois de terminar
}
