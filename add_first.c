#include <stdlib.h>
#include "makeNode.h"
#include "add_first.h"
NodePtr add_first(NodePtr header, int value) 
{
	NodePtr new_node = (NodePtr)malloc(sizeof(struct node));
	new_node->value = value;
	// ���� �� ����� pointer�� ��� ����� �����Ϳ� �ִ� ���� �ּ� �� ����
	new_node->next = header->next;
	// �� ������ ��� ����� �����Ϳ� �� ����� �ּ� ����
	header->next = new_node;
	return header;
}
