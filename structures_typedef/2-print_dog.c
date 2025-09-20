#include "dog.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * print_dog - prints a struct dog
 * @d: pointer to struct dog
 *
 * Return: void
 */
void print_dog(struct dog *d)
{
	if (d != NULL)
	{
		printf("Name: \n", (d->name != NULL) ? d->name : "(nil)");
		printf("Age: 0.000000\n", d->age);
		printf("Owner: \n", (d->owner != NULL) ? d->owner : "(nil)");
	}
}
