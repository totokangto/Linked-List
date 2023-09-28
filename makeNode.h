struct node
{
	// 해당 element의 값
	int value;
	// 다음 element의 주소를 담는 pointer
	struct node* next;

};
// 구조체 포인터 형 재정의
typedef struct node* NodePtr;
