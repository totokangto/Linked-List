#include <stdlib.h>
#include "makeNode.h"
#include "add_k.h"
#include "access_node.h"

NodePtr add_k(NodePtr header, int value, int k)
{
	NodePtr prev_node = access_node(header, k-1);
	NodePtr new_node = (NodePtr)malloc(sizeof(struct node));
	new_node->value = value;
	// 먼저 새 노드의 pointer에 이전 노드의 포인터에 있던 다음 주소 값 저장
	new_node->next = prev_node->next;
	// 그 다음에 이전 노드의 포인터에 새 노드의 주소 저장
	prev_node->next = new_node;

	return header;
}
