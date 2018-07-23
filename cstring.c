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
			while ((*tempStr++ = *array++) != '\0');
			*tempStr = '\0';
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
	free(current->array);
	free(current);
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
int _findSubstring(String* current, String* str)
{

}
void _append(String* current, String* str)
{

}
void _insertAt(String* current, int n, char c)
{

}