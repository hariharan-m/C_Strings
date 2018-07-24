#include "cstring.h"
#include "stdio.h"
/*******************************************************************
 Creates new String. 'array' needs to be nullterminated.
*******************************************************************/
String* new_String(char *array)
{
	String* temp = malloc(sizeof(String));
	if (temp)
		{
			char *tempStr = malloc(strlen(array) + sizeof(char)); // for null terminator
			if (tempStr)
				{
					temp->array = tempStr;
					while ((*tempStr++ = *array++) != '\0'); // copying from argument to allocated space
					*tempStr = '\0'; // Null term at the end of the string
					temp->destroy = _destroy;
					temp->length = _length;
					temp->contains = _contains;
					temp->findSubstring = _findSubstring;
					temp->append = _append;
					temp->insertAt = _insertAt;
					return temp;
				}
		}
	return NULL;
}

/*******************************************************************
 Returns length of the String.
*******************************************************************/
int _length(String* current)
{
	return strlen(current->array);
}

/*******************************************************************
 Deallocates the String object and the char* contained in it.
*******************************************************************/
void _destroy(String* current)
{
	if (current)
		{
			free(current->array);
			free(current);
		}
}

/*******************************************************************
 Returns the number of occurences of the character c in the String.
*******************************************************************/
int _contains(String *current, char c)
{
	int count = 0;
	char* ptr = current->array;
	for (; *ptr != '\0'; *ptr++)
		if (*ptr == c)
			count++;
	return count;
}

/*******************************************************************
 Returns 1 if str is present in current. Else returns 0.
*******************************************************************/
int _findSubstring(String* current, String* str)
{
	int *ret;
	ret = lcommon(current->array, str->array);
	if (ret[0] == str->length(str))
		{
			free(ret);
			return 1;
		}
	else
		{
			free(ret);
			return 0;
		}
}

/*******************************************************************
 Appends 1st argument with the second argument.
*******************************************************************/
void _append(String* current, String* str)
{
	current->array = (char*)realloc(current->array, current->length(current) + str->length(str) + sizeof(char)); // reallocating to accomodate new string + 1 for null term
	char* dest = (char*) current->array + current->length(current); // end of 1st string
	char* src = (char*) str->array;
	while ((*dest++ = *src++) != '\0');
	*dest = '\0';
}

/*******************************************************************
 Inserts char c at position n in the String
*******************************************************************/
void _insertAt(String* current, int n, char c)
{
	if (n > current->length(current))
		return;
	current->array = (char*)realloc(current->array, current->length(current) + sizeof(char));
	char* end = current->array + current->length(current) + 1; // last elt
	char* preend = current->array + current->length(current); // 2nd last elt
	int i = current->length(current) - n + 1; // number of elements to shift by
	while (i--) // shifting
		*end-- = *preend--;
	*(current->array + n) = c; // insert
}

/*******************************************************************
 Longest common Substring.
 Reference: https://en.wikibooks.org/wiki/Algorithm_Implementation/Strings/Longest_common_substring#C
*******************************************************************/

int *lcommon(char *s, char *t)
{
	int strlen1 = strlen(s);
	int strlen2 = strlen(t);
	int len = (strlen1 < strlen2) ? strlen2 : strlen1;
	int i, j, k;
	int longest = 0;
	int **ptr = (int **)malloc(2 * sizeof(int *));
	static int *ret;
	/*
	 * Maximum length of the return list (considering intermediate steps).
	 * It is the maximum length of the source strings + 1 (worst-case
	 * intermediate length) + the value of the longest match + the
	 * terminator value (-1).
	 */
	ret = (int *)malloc((len + 3) * sizeof(int));
	for (i = 0; i < 2; i++)
		ptr[i] = (int *)calloc(strlen2, sizeof(int));

	ret[1] = -1;
	for (i = 0; i < strlen1; i++)
		{
			memcpy(ptr[0], ptr[1], strlen2 * sizeof(int));
			for (j = 0; j < strlen2; j++)
				{
					if (s[i] == t[j])
						{
							if (i == 0 || j == 0)
								{
									ptr[1][j] = 1;
								}
							else
								{
									ptr[1][j] = ptr[0][j - 1] + 1;
								}
							if (ptr[1][j] > longest)
								{
									longest = ptr[1][j];
									k = 1;
								}
							if (ptr[1][j] == longest)
								{
									ret[k++] = i;
									ret[k] = -1;
								}
						}
					else
						{
							ptr[1][j] = 0;
						}
				}
		}
	for (i = 0; i < 2; i++)
		free(ptr[i]);
	free(ptr);
	/* store the maximum length in ret[0] */
	ret[0] = longest;
	return ret;
}
