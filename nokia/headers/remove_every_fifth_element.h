#pragma once

struct List
{
	List(int val) :val(val) {}

	struct List* next = nullptr;
	int val;
};

/*Write a function that remoes every fifth element from the list.*/

//O(N)
void remove(List* prev, List* current, int& counter);

void remove_every_fifth_element(List* list)
{
	int counter = 1;
	remove(nullptr, list, counter);
}

void remove(List* prev, List* current, int& counter)
{
	if (!current) return;

	if (counter == 5)
	{
		prev->next = current->next;

		counter = 1;
		remove(prev, prev->next, counter);
	}
	else
		remove(current, current->next, ++counter);
}