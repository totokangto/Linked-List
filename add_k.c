#include <stdlib.h>
#include "makeNode.h"
#include "add_k.h"
#include "access_node.h"

NodePtr add_k(NodePtr header, int value, int k)
{
	NodePtr prev_node = access_node(header, k-1);
	NodePtr new_node = (NodePtr)malloc(sizeof(struct node));
	new_node->value = value;
	// ���� �� ����� pointer�� ���� ����� �����Ϳ� �ִ� ���� �ּ� �� ����
	new_node->next = prev_node->next;
	// �� ������ ���� ����� �����Ϳ� �� ����� �ּ� ����
	prev_node->next = new_node;

	return header;
}
