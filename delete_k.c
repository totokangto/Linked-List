#include <stdlib.h>
#include "makeNode.h"
#include "add_k.h"
#include "access_node.h"

NodePtr delete_k(NodePtr header, int k)
{
	NodePtr del_node = access_node(header,k);
	NodePtr prev_node = access_node(header, k - 1);
	// 지우려는 노드 포인터에 담겨있는 다음 노드의 주소를 
	// 이전 노드 포인터에 저장
	prev_node->next = del_node->next;

	return header;
}
