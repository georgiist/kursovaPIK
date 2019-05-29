#include "Interface_ListStorage.h"

void MainThread() {
	Ship* head = NULL;
	int n = 0, res;

	do{
		printf("How many ships do you want (MAX 3!!!): \n");
		scanf("%d", &n);
	} while (n > 3 && n < 1);
	head = createList(n);
		
	res = shooting(head, n);
	writeInFile(res);
	free(head);
}

Ship* createList(int size)
{
	Ship* head = NULL;
	Ship* temp = NULL;
	Ship* p = NULL;
	int i;
	for (i = 0; i < size; i++)
	{
		temp = (Ship*)malloc(sizeof(Ship));

		printf("\nEnter X of down point for the ship:");
		scanf("%d", &temp->xDown);
		printf("\nEnter Y of down point for the ship:");
		scanf("%d", &temp->yDown);
		printf("\nEnter X of upper point for the ship:");
		scanf("%d", &temp->xUp);
		printf("\nEnter Y of upper point for the ship:");
		scanf("%d", &temp->yUp);
		printf("\n");

		temp->next == NULL;

		if (head == NULL) {
			head = temp;
			p = head;
		}
		else {
			p->next = temp;
			p = p->next;
			if (((p->xDown >= head->xDown && p->xDown <= head->xUp) && (p->yDown >= head->yUp && p->yDown <= head->yDown))
				|| ((p->yUp >= head->yUp && p->yUp <= head->yDown) && (p->xUp >= head->xDown && p->xUp <= head->xUp))) {
				printf("\nEnter X of down point for the ship:");
				scanf("%d", &temp->xDown);
				printf("\nEnter Y of down point for the ship:");
				scanf("%d", &temp->yDown);
				printf("\nEnter X of upper point for the ship:");
				scanf("%d", &temp->xUp);
				printf("\nEnter Y of upper point for the ship:");
				scanf("%d", &temp->yUp);
				printf("\n");
			}
		}
	}
		return head;
	}

int shooting(Ship* head, int size) {
	Ship* prev_item = head;
	Ship* p = head;
	int n = 1, shootX, shootY;
	int try, result = 0;

	while (p != NULL) {
		try = 0;
		printf("\n");
		printf("\nYou have 2 tries for ship %d.", n);
		printf("\nWhere do you want to shoot ship%d- X:",n);
		scanf("%d", &shootX);
		printf("\nWhere do you want to shoot ship%d- Y:",n);
		scanf("%d", &shootY);

		if (((shootX >= p->xDown && shootX <= p->xUp) && (shootY >= p->yUp && shootY <= p->yDown))
			|| ((shootY >= p->yUp && shootY <= p->yDown) && (shootX >= p->xDown && shootX <= p->xUp)))
		{
			printf("\nSHIP %d IS DEAD",n);
			try++;
		}
		else{
			printf("\nWhere do you want to shoot ship%d- X:",n);
			scanf("%d", &shootX);
			printf("\nWhere do you want to shoot ship%d- Y:",n);
			scanf("%d", &shootY);
			if (((shootX >= p->xDown && shootX <= p->xUp) && (shootY >= p->yUp && shootY <= p->yDown))
				|| ((shootY >= p->yUp && shootY <= p->yDown) && (shootX >= p->xDown && shootX <= p->xUp))) {
				try += 2;
				printf("\nSHIP %d IS DEAD", n);

			}
		}
		if (try == 1) result += 10;
		if (try == 2) result += 5;
		p = p->next;
		n++;
		if (n == (size + 1)) {
			break;
		}
	}
	printf("\n\t\t\t\t\t\tTHE FINAL RESULT IS: %d", result);
	return result;
}

void writeInFile(int result) {
	FILE* fileOut;

	if ((fileOut = fopen(file, "w")) == NULL) {
		printf("ERROR OPENING THE FILE");
		exit(1);
	}
	fprintf(fileOut, "The result of the last round is: %d", result);
	fclose(fileOut);
}