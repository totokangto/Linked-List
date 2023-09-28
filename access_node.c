#include <stdlib.h>
#include <stdio.h>
#include "makeNode.h"
#include "access_node.h"

NodePtr access_node(NodePtr header, int k) {
	NodePtr check = header;
	for (int i = 0; i < k; i++) {
		check = check->next;
		// ��� ���� ���� �ʰ�
		if (check == NULL) {
			printf("\n%d��° ���� �������� �ʽ��ϴ�.\n", k);
			exit(1);
		}
	}
	
	return check;
}
