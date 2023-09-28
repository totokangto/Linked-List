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
	} // check ����� �������� ���� null�϶����� -> check : ������ ���
	check->next = new_node;

	return header;
}
