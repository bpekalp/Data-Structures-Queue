#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif // _MSC_VER

#include <stdio.h>
#include <stdlib.h>

#define SIZE 10		//SIZE variable is a constant and it's value is 10, it can be changed.
int queue[SIZE];	//an array named queue with the size of 10.
int front = -1;		//these are our indexes.
int back = -1;		//they hold the front index and back index of our queues.
int isEmpty();
int isFull();
void enqueue(int);
void dequeue();
void printqueue();
void example();

int main()
{
	int choice;
	int number;
	while (1)
	{
		printf("1. Add item\n");
		printf("2. Remove item\n");
		printf("3. Print queue\n");
		printf("4. Clear the console\n");
		printf("5. Exit program\n");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("Enter a number to add: ");
			scanf("%d", &number);
			enqueue(number);
			break;
		case 2:
			dequeue();
			break;
		case 3:
			printqueue();
			break;
		case 4:
			system("cls");
			break;
		case 5:
			return 0;
		default:
			printf("Wrong input!\n");
			break;
		}
	}
}

int isEmpty()
{
	if (front == -1 || front > back)
	{
		front = -1;	//we dont want our front index to be greater than back index.
		back = -1;	//so we fix that just in case if the queue is empty by it's front index being greater than it's back index.
		return 1;	//since C doesn't have a boolean data type, we will take 1 as true
	}
	return 0;		//and 0 as false.
}

int isFull()
{
	if (back == SIZE - 1)
	{
		return 1;	//same goes here.
	}
	return 0;
}

void enqueue(int data)	//adding an item to queue
{
	if (isFull())	//if our queue is full this block will run.
	{
		printf("Queue is full!\n");
		return;
	}
	if (isEmpty())	//if our queue is empty this block will run.
	{
		front++;				//front index was -1, now its 0.
		back++;					//same goes here.
		queue[back] = data;		//we added our item to the back index of the queue.
		return;					//we returned from the function which means that next lines won't work in this function
	}
	back++;			//if our queue isn't empty these 2 lines will work.
	queue[back] = data;
}

void dequeue()		//removing an item from queue
{
	if (isEmpty())	//if our queue is empty this block will run.
	{
		printf("Queue is empty!\n");
		return;
	}
	//	queue[front] = NULL; this line is unnecessary because when the index changes the front member of the queue which we point to changes as well.
	front++;
	printf("Item removed.\n");
}

void printqueue()
{
	if (isEmpty())	//if our queue is empty this block will run.
	{
		printf("Queue is empty!\n");
		return;
	}
	for (int i = front; i <= back; i++)
	{
		printf("%d<==", queue[i]);	//the arrow is pointing to the front. for example:
	}								//1<==2<==324<==27<==34<==14<==7
	printf("\n");					//1 is in the front and 7 is in the back of the queue.
}

void example()
{
	printqueue();	//it should read queue is empty.
	enqueue(7);
	enqueue(27);
	enqueue(14);
	enqueue(34);
	enqueue(41);
	enqueue(54);
	printqueue();	//it should read 7<==27<==14<==34<==41<==54<==
	dequeue();
	dequeue();
	printqueue();	//it should read 14<==34<==41<==54<==
}