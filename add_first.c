#include <stdlib.h>
#include "makeNode.h"
#include "add_first.h"
NodePtr add_first(NodePtr header, int value) 
{
	NodePtr new_node = (NodePtr)malloc(sizeof(struct node));
	new_node->value = value;
	// 먼저 새 노드의 pointer에 헤더 노드의 포인터에 있던 다음 주소 값 저장
	new_node->next = header->next;
	// 그 다음에 헤더 노드의 포인터에 새 노드의 주소 저장
	header->next = new_node;
	return header;
}
