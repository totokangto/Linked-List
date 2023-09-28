#include <stdio.h>
#include <stdlib.h>
#include "makeNode.h"
#include "add_first.h"
#include "add_last.h"
#include "access_node.h"
#include "add_k.h"
#include "delete_k.h"


int main(void) {
	
	// 1. Make Linked-List(one header, three nodes) 
	NodePtr header;
	header = (NodePtr)malloc(sizeof(struct node));
	header->value = 3;
	header->next = NULL;
	
	NodePtr node1 = (NodePtr)malloc(sizeof(struct node));
	node1->value = 5;
	node1->next = NULL;
	header->next = node1; // 헤더 노드의 포인터에 노드 1의 주소 저장

	NodePtr node2 = (NodePtr)malloc(sizeof(struct node));
	node2->value = 7;
	node2->next = NULL;
	node1->next = node2;

	NodePtr node3 = (NodePtr)malloc(sizeof(struct node));
	node3->value = 9;
	node3->next = NULL;
	node2->next = node3;

	// Linked-List test
	printf("header node value 확인 : %d\n", header->value); // 3 출력
	printf("노드 value 확인\n");
	NodePtr check = header->next;
	int i = 1;
	// 마지막 노드까지 접근해서 check의 pointer에 NULL이 저장되면 종료
	while (check != NULL) {
		printf("%d번째 노드 : %d\n", i,check->value); // 해당 노드의 value 출력
		check = check->next; // 해당 노드에 저장된 다음 주소를 다시 check에 저장
		i++;
	} // 5 7 9 출력
	

	// 2. Adding an Element at the Beginning (value = 4)
	header = add_first(header, 4);

	check = header->next; // header의 value부터 출력해야 하므로 check를 header로 초기화
	i = 1;
	printf("------------------------------\n맨 앞에 새로운 노드 추가\n");
	while (check != NULL) {
		printf("%d번째 노드 : %d\n", i,check->value);
		check = check->next;
		i++;
	} // 4 5 7 9 출력


	// 3. Adding an Element at the End (value = 10)
	header = add_last(header, 10);
	check = header->next; 
	i = 1;
	printf("------------------------------\n맨 뒤에 새로운 노드 추가\n");
	while (check != NULL) {
		printf("%d번째 노드 : %d\n", i, check->value);
		check = check->next;
		i++;
	} // 4 5 7 9 10 출력


	// 4. Accessing an Element (k=3)
	NodePtr k_node = access_node(header, 3);
	printf("------------------------------\nk(=3)번째 node 찾기\n");
	printf("k(=3)번째 노드의 value : %d\n", k_node->value); // 7 출력


	// 5. Adding an element at the k-th position (value = 8, k = 4)
	header = add_k(header,8,4);
	check = header->next;
	i = 1;
	printf("------------------------------\nk(=4)번째 위치에 새로운 노드(value = 8) 추가\n");
	while (check != NULL) {
		printf("%d번째 노드 : %d\n", i, check->value);
		check = check->next;
		i++;
	} // 4 5 7 8 9 10 출력


	// 6. Delete at the k-th position (k = 2)
	header = delete_k(header, 2);
	check = header->next;
	i = 1;
	printf("------------------------------\nk(=2)번째 노드(value = 5) 제거\n");
	while (check != NULL) {
		printf("%d번째 노드 : %d\n", i, check->value);
		check = check->next;
		i++;
	} // 4 7 8 9 10 출력


	check = header;
	int t = 0;
	while (check->next != NULL) {
		check = check->next;
		t++;
	} // t는 node 개수
	printf("------------------------------\n현재 노드 개수 : %d\n", t);
	// 마지막 노드부터 첫번째 노드까지 역순으로 동적 할당 된 메모리 반환
	while (t != 0) {
		free(access_node(header, t));
		printf("%d번째 노드 메모리 반환 완료\n", t);
		t--;
	}
	free(header); // 헤더 노드에 동적 할당 된 메모리 반환
	printf("header 노드 메모리 반환 완료");


	return 0;
}