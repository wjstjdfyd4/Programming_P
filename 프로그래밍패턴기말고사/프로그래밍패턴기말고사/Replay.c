#define _CRT_SECURE_NO_WARNINGS
#include "Replay.h"
#include "data.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ���÷��� �����ʹ� ���ӿ� ���Ǿ��� �õ尪�� ���� ������ ��ȯ�� ��ġ�� �����մϴ�
// ���÷��� ��� �� ���� ��ġ - ���� ��ġ�� ���� ������ �����Ͽ� �̵��մϴ�
// ���� ��ġ ���� �� ���� ������ �ٽ� �����Ͽ� ������ ������ �ݺ��մϴ�

replaydata* createreplay(int x, int y) {
	replaydata* temp = (replaydata*)malloc(sizeof(replaydata));
	temp->location.x = x;
	temp->location.y = y;

	return temp;
}

void append(player* p, replaydata* newnode) {
	if (p->data == NULL) {
		newnode->link = newnode;
		p->data = newnode;
		return;
	}

	newnode->link = p->data->link;
	p->data->link = newnode;
	p->data = newnode;
}
// ���� �̸� �ڵ� ����
char* getname() {
	static char fname[100];

	int count = 1;
	char charcount[3];

	while (1) { //replay(n).dat ����
		char buffer[100] = "replay(";
		sprintf(charcount, "%d", count);
		strcat(buffer, charcount);
		strcat(buffer, ").dat");

		if (fopen(buffer, "r") == NULL) {	//������ �������� �ʴٸ� �ش� �̸����� ����
			strcpy(fname, buffer);
			break;
		}

		count++;
	}

	return fname;
}

FILE* made_replay() {
	return fopen(getname(), "wb");
}
// �����͸� ���Ϸ� ����
void savefile(player* p, int seed) {
	FILE* fp = made_replay();

	fwrite(&seed, sizeof(int), 1, fp); //�õ尪 ����
	replaydata* movement = p->data->link; //���÷��� ���ۺκ�

	do {
		replaydata* nextmovement = movement->link;

		if (movement->location.x != nextmovement->location.x && movement->location.y != nextmovement->location.y) {
			if (movement->link != p->data->link) {
				//���� �����ڵ�
				replaydata* next2movement = nextmovement->link;

				if (nextmovement->location.y == next2movement->location.y) {
					replaydata* correctionnode = (replaydata*)malloc(sizeof(replaydata));

					correctionnode->location.x = nextmovement->location.x;
					correctionnode->location.y = movement->location.y;

					correctionnode->link = nextmovement;
					movement->link = correctionnode;
				}

				else if (nextmovement->location.x == next2movement->location.x) {
					replaydata* correctionnode = (replaydata*)malloc(sizeof(replaydata));

					correctionnode->location.x = movement->location.x;
					correctionnode->location.y = nextmovement->location.y;

					correctionnode->link = nextmovement;
					movement->link = correctionnode;
				}
			}
		}

		fwrite(movement, sizeof(replaydata), 1, fp);

		movement = movement->link;
	} while (movement != p->data->link);

	printf("������ �Ϸ�Ǿ����ϴ�.\n");
	fclose(fp);
}
