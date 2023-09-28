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
	header->next = node1; // ��� ����� �����Ϳ� ��� 1�� �ּ� ����

	NodePtr node2 = (NodePtr)malloc(sizeof(struct node));
	node2->value = 7;
	node2->next = NULL;
	node1->next = node2;

	NodePtr node3 = (NodePtr)malloc(sizeof(struct node));
	node3->value = 9;
	node3->next = NULL;
	node2->next = node3;

	// Linked-List test
	printf("header node value Ȯ�� : %d\n", header->value); // 3 ���
	printf("��� value Ȯ��\n");
	NodePtr check = header->next;
	int i = 1;
	// ������ ������ �����ؼ� check�� pointer�� NULL�� ����Ǹ� ����
	while (check != NULL) {
		printf("%d��° ��� : %d\n", i,check->value); // �ش� ����� value ���
		check = check->next; // �ش� ��忡 ����� ���� �ּҸ� �ٽ� check�� ����
		i++;
	} // 5 7 9 ���
	

	// 2. Adding an Element at the Beginning (value = 4)
	header = add_first(header, 4);

	check = header->next; // header�� value���� ����ؾ� �ϹǷ� check�� header�� �ʱ�ȭ
	i = 1;
	printf("------------------------------\n�� �տ� ���ο� ��� �߰�\n");
	while (check != NULL) {
		printf("%d��° ��� : %d\n", i,check->value);
		check = check->next;
		i++;
	} // 4 5 7 9 ���


	// 3. Adding an Element at the End (value = 10)
	header = add_last(header, 10);
	check = header->next; 
	i = 1;
	printf("------------------------------\n�� �ڿ� ���ο� ��� �߰�\n");
	while (check != NULL) {
		printf("%d��° ��� : %d\n", i, check->value);
		check = check->next;
		i++;
	} // 4 5 7 9 10 ���


	// 4. Accessing an Element (k=3)
	NodePtr k_node = access_node(header, 3);
	printf("------------------------------\nk(=3)��° node ã��\n");
	printf("k(=3)��° ����� value : %d\n", k_node->value); // 7 ���


	// 5. Adding an element at the k-th position (value = 8, k = 4)
	header = add_k(header,8,4);
	check = header->next;
	i = 1;
	printf("------------------------------\nk(=4)��° ��ġ�� ���ο� ���(value = 8) �߰�\n");
	while (check != NULL) {
		printf("%d��° ��� : %d\n", i, check->value);
		check = check->next;
		i++;
	} // 4 5 7 8 9 10 ���


	// 6. Delete at the k-th position (k = 2)
	header = delete_k(header, 2);
	check = header->next;
	i = 1;
	printf("------------------------------\nk(=2)��° ���(value = 5) ����\n");
	while (check != NULL) {
		printf("%d��° ��� : %d\n", i, check->value);
		check = check->next;
		i++;
	} // 4 7 8 9 10 ���


	check = header;
	int t = 0;
	while (check->next != NULL) {
		check = check->next;
		t++;
	} // t�� node ����
	printf("------------------------------\n���� ��� ���� : %d\n", t);
	// ������ ������ ù��° ������ �������� ���� �Ҵ� �� �޸� ��ȯ
	while (t != 0) {
		free(access_node(header, t));
		printf("%d��° ��� �޸� ��ȯ �Ϸ�\n", t);
		t--;
	}
	free(header); // ��� ��忡 ���� �Ҵ� �� �޸� ��ȯ
	printf("header ��� �޸� ��ȯ �Ϸ�");


	return 0;
}