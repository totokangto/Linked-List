#include <stdlib.h>
#include "makeNode.h"
#include "add_last.h"
NodePtr add_last(NodePtr header, int value)
{
	NodePtr new_node = (NodePtr)malloc(sizeof(struct node));
	new_node->value = value;
	new_node->next = NULL;
	NodePtr check = header;
	while (check->next != NULL) {
		check = check->next;
	} // check 노드의 포인터의 값이 null일때까지 -> check : 마지막 노드
	check->next = new_node;

	return header;
}
