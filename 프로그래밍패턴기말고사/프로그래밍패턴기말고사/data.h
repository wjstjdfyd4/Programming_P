#pragma once
#define boardx 37	//������ xũ��
#define boardy 13	//������ yũ��

typedef struct {
	int x;
	int y;
} Location;

typedef struct {	//���� ���Ḯ��Ʈ
	struct ListNode* left;
	struct ListNode* right;
	Location location;
} ListNode;

typedef struct {
	struct replaydata* link;
	Location location;
} replaydata;

typedef struct {
	ListNode* last; //���� ���Ḯ��Ʈ
	replaydata* data;
	int olddirection; //������ �̵� ����
	int direction;	//�̵� ����
	int length;		//���� ����
	int speed;		//�̵� �ӵ�
	int movable;	//�̵� �������� �Ǵ��ϴ� bool�� ( ���ӿ��� �Ǵ� )
} player;

void insert_first(player* p, ListNode* newnode);

ListNode* createnode(int x, int y);

void gotoxy(int x, int y);

void gotonode(Location node);

extern Location feed; //���̸� ���������� ����