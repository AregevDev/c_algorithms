#include <stdio.h>

#include "linked_list/snode.h"

int main()
{
    SNode* node = snode_create((SNodeItem){1});
    snode_push_back(&node, (SNodeItem){10});
    snode_push_front(&node, (SNodeItem){12});

    snode_print(node);

    snode_destroy(node);
    return 0;
}
