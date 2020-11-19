#include <stdio.h>

#include "linked_list/snode.h"
#include "stack/stack.h"

int main()
{
    SNode* node = snode_create((SNodeItem){1});
    snode_push_sorted(&node, (SNodeItem){10});
    snode_push_sorted(&node, (SNodeItem){12});

    snode_print(node);
    snode_delete_at(&node, 1);
    snode_print(node);

    Stack* s = stack_create(10);
    stack_push(s, (StackItem){1});
    stack_push(s, (StackItem){2});
    stack_push(s, (StackItem){3});
    stack_push(s, (StackItem){4});

    stack_print(s);

    stack_destroy(s);
    snode_destroy(node);
    return 0;
}
