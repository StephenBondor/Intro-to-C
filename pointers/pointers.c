#include <stdio.h>
#include <string.h>

/*
    Given a character pointer x (that points to an array of chars), and a
    character pointer y, copies the character contents of y over to x. Pointer
    arithmetic is necessary here. Also, make sure x points to a null terminator
    at its end to terminate it properly. 

    Example call:

    char buffer[1024];

    string_copy(buffer, "Hello!");
    printf("%s", buffer); // Prints "Hello!"
*/
void string_copy(char *x, char *y)
{
	int i = 0;

	while (*(y + i) != '\0')
	{
		*(x + i) = *(y + i);
		i++;
	}
	*(x + i) = '\0';
}

/*
    Searches the input string `str` for the first instance of the 
    character `c` (an unsigned char). This function returns a pointer
    that points to the first instance of the character `c` in the
    input string `str`.

    Do not use the `strchr` function from the standard library.
*/
char *find_char(char *str, int c)
{
	int i = 0;
	char *p;

	while (*(str + i) != '\0')
	{
		p = (str + i);
		if (*(str + i) == c)
		{
			break;
		}
		i++;
	}
	if (*(p + 1) == '\0')
	{
		return NULL;
	}
	return p;
}

/*
    Searches the input string `haystack` for the first instance of
    the string `needle`. This function returns a pointer that points
    to the first instance of the string `needle` in the input
    string `haystack`. 

    Do not use the `strstr` function from the standard library.
*/
char *find_string(char *haystack, char *needle)
{
	int haystack_length = strlen(haystack);
	int needle_length = strlen(needle);
	int found = 0;
	char *p = NULL;

	if (haystack_length >= needle_length)
	{
		for (int i = 0, t = 0; i < haystack_length; i++)
		{
			do
			{
				if (haystack[i] == needle[t])
				{
					if (p == NULL)
					{
						p = &haystack[i];
					}
					if (++found == needle_length)
					{
						return p;
					}
					i++;
					t++;
				}
				else
				{
					i -= found;
					found = 0;
					t = 0;
					p = NULL;
				}
			} while (found);
		}
		return NULL;
	}
	else
		return NULL;
}

#ifndef TESTING
int main(void)
{
	char *found_char = find_char(hello, 'e');
	char *found_string = find_string(world, "or");

	printf("Found char: %s\n", found_char);
	printf("Found string: %s\n", found_string);

	return 0;
}
#endif
