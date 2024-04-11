#include <stdio.h>
#include <malloc.h>

struct Node
{
	int val;
	struct Node *next;
};

struct Node *start = NULL, *pre;

void insertAtFirst()
{
	int value;
	printf("Enter the value to be inserted:\t");
	scanf("%d", &value);

	if (start == NULL)
	{
		start = (struct Node *)malloc(sizeof(struct Node));
		start->val = value;
		start->next = NULL;
		return;
	}

	pre = (struct Node *)malloc(sizeof(struct Node));
	pre->val = value;
	pre->next = start;
	start = pre;
}

void insertAtLast()
{

	int value;
	printf("Enter the value to be inserted:\t");
	scanf("%d", &value);

	if (start == NULL)
	{
		start = (struct Node *)malloc(sizeof(struct Node));
		start->val = value;
		start->next = NULL;
		return;
	}

	pre = (struct Node *)malloc(sizeof(struct Node));
	pre->val = value;
	pre->next = NULL;

	struct Node *temp = start;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = pre;
}

void insertAtMiddle()
{
	int position;
	printf("Enter the position:\t");
	scanf("%d", &position);

	if (position == 1)
	{
		insertAtFirst();
		return;
	}

	int cnt = 1;
	struct Node *temp = start;

	int value;
	printf("Enter the value to be inserted:\t");
	scanf("%d", &value);
	struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
	newNode->val = value;

	while (temp->next != NULL)
	{
		cnt++;

		if (cnt == position)
		{
			newNode->next = temp->next;
			temp->next = newNode;
			return;
		}

		temp = temp->next;
	}

	temp->next = newNode;
	newNode->next = NULL;
}

void displayAll()
{
	printf("Displaying all element:\n");
	struct Node *temp = start;
	while (temp != NULL)
	{
		printf("%d\t", temp->val);
		temp = temp->next;
	}
	printf("\n");
}

void searching()
{
	int value;
	printf("Enter the value to be searched:");
	scanf("%d", &value);

	struct Node *temp = start;

	int cnt = 1;
	while (temp != NULL)
	{
		if (temp->val == value)
		{
			printf("%d is founded at position %d\n", value, cnt);
			return;
		}
		cnt++;
		temp = temp->next;
	}
}

void deleteFirst()
{

	if (start == NULL)
	{
		printf("No node present ! first insert before delete node.\n");
		return;
	}

	pre = start;
	start = start->next;
	free(pre);
}

void deleteLast()
{

	if (start == NULL)
	{
		printf("No node present ! first insert before delete node.\n");
		return;
	}

	struct Node *temp = start;
	while (temp->next->next != NULL)
	{
		temp = temp->next;
	}

	pre = temp->next;
	temp->next = NULL;
	free(pre);
}

void deleteAnyNode()
{
	int position;
	printf("Enter the position for which node is to be deleted:");
	scanf("%d", &position);
	if (position == 1)
	{
		deleteFirst();
		return;
	}
	int cnt = 1;
	struct Node *temp = start;

	while (temp->next->next != NULL)
	{
		cnt++;
		if (cnt == position)
		{
			pre = temp->next;
			temp->next = temp->next->next;
			free(pre);
			return;
		}

		temp = temp->next;
	}

	deleteLast();
}

int main()
{

	int n;

	while (1)
	{
		printf("\n1:for insert at first\n2:for insert at last\n3:for insert at any position\n4:for searching element\n5:delete first node\n6:delete last node\n7:delete any node\n8:for displaying all\n9:for exit\n");
		scanf("%d", &n);

		switch (n)
		{
		case 1:
			insertAtFirst();
			break;

		case 2:
			insertAtLast();
			break;

		case 3:
			insertAtMiddle();
			break;

		case 4:
			searching();
			break;

		case 5:
			deleteFirst();
			break;

		case 6:
			deleteLast();
			break;

		case 7:
			deleteAnyNode();
			break;
		case 8:
			displayAll();
			break;

		case 9:
			exit(0);

		default:
			printf("wrong number !! please try again ");
			break;
		}
	}
	return 0;
}
