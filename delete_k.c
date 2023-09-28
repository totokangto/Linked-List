#include <stdlib.h>
#include "makeNode.h"
#include "add_k.h"
#include "access_node.h"

NodePtr delete_k(NodePtr header, int k)
{
	NodePtr del_node = access_node(header,k);
	NodePtr prev_node = access_node(header, k - 1);
	// ������� ��� �����Ϳ� ����ִ� ���� ����� �ּҸ� 
	// ���� ��� �����Ϳ� ����
	prev_node->next = del_node->next;

	return header;
}
