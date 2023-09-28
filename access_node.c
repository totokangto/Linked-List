#include <stdlib.h>
#include <stdio.h>
#include "makeNode.h"
#include "access_node.h"

NodePtr access_node(NodePtr header, int k) {
	NodePtr check = header;
	for (int i = 0; i < k; i++) {
		check = check->next;
		// 노드 개수 범위 초과
		if (check == NULL) {
			printf("\n%d번째 노드는 존재하지 않습니다.\n", k);
			exit(1);
		}
	}
	
	return check;
}
