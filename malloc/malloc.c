#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lib.h"

/*
    Duplicates the input string by dynamically allocating memory for 
    the duplicate string using `malloc` and then copying the string
    into the allocated memory. Returns a pointer to the allocated memory.
    You may want to use the string_length function to figure out the
    length of the input string.
*/
char *string_dup(char *src)
{
	int length = strlen(src);
	char *new_string = malloc((length + 1) * sizeof(char));
	int i = 0;

	while (*(src + i) != '\0')
	{
		*(new_string + i) = *(src + i);
		i++;
	}
	*(new_string + i) = '\0';

	return new_string;
}

/*
    A generic version of string_copy, mem_copy receives a block of memory
    of any type and copies its contents to the destination pointer (dest).
    You may want to cast the input pointers to char pointers first before
    performing the copying. `n` is the amount of data that should be copied
    from `src` to `dest`. 
*/
void mem_copy(void *dest, const void *src, int n)
{
	char *cast_src = (char *)src;
	char *cast_dest = (char *)dest;
	int i = 0;
	while (i < n)
	{
		*(cast_dest + i) = *(cast_src + i);
		i++;
	}
	dest = cast_dest;
}

/*
    Given a pointer of `malloc`'d memory, this function will 
    attempt to resize the allocated memory to the new specified
    size. Any data that was previously in the old `malloc`'d 
    memory should be intact in the new resized block of memory. 
    Some edge cases to consider: how should resizing be handled
    in the case when old_size < new_size? What about when 
    old_size > new_size?
    
    Do not use the `realloc` function from the standard libary.
*/

void *resize_memory(void *ptr, int old_size, int new_size)
{
	char *new_memory = malloc(new_size);
	char *cast_ptr = (char *)ptr;
	int i = 0;
	if (new_size > old_size)
	{
		while (i < old_size)
		{
			*(new_memory + i) = *(cast_ptr + i);
			i++;
		}
		ptr = new_memory;
	}
	else
	{
		while (i < new_size)
		{
			*(new_memory + i) = *(cast_ptr + i);
			i++;
		}
		ptr = new_memory;
	}
	return new_memory;
}

#ifndef TESTING
int main(void)
{
	char *s = "Some string to duplicate.";
	char *dup = string_dup(s);

	printf("Duplicated string: %s\n", dup);

	int numbers[] = {100, 55, 4, 98, 10, 18, 90, 95, 43, 11, 47, 67, 89, 42, 49, 79};
	int n = sizeof(numbers) / sizeof(numbers[0]);
	int *target = malloc(n * sizeof(int));

	mem_copy(target, numbers, n * sizeof(int));

	printf("Copied array: ");

	for (int i = 0; i < n; i++)
	{
		printf("%d ", target[i]);
	}

	printf("\n");

	char *url = string_dup("http://lambdaschool.com");
	char *path = string_dup("/students/");
	int url_length = strlen(url);
	int path_length = strlen(path);

	int new_length = url_length - 1 + path_length;
	char *new_url = resize_memory(url, url_length, new_length);
	char *p = new_url + url_length;

	while (*path != '\0')
	{
		*p = *path;
		p++;
		path++;
	}

	printf("Full path string: %s\n", new_url);

	return 0;
}
#endif