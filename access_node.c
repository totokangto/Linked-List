#include <stdlib.h>
#include "makeNode.h"
#include "access_node.h"

NodePtr access_node(NodePtr header, int k) {
	NodePtr check = header;
	for (int i = 0; i < k; i++) {
		check = check->next;
	}
	
	return check;
}
