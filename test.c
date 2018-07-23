#include "cstring.h"
#include "stdio.h"
void main(int argc, char const *argv[])
{
	char arr[] = "test_string";
	char arr2[] = "append_this";
	char c = 's';
	String* ptr = new_String(arr);
	if (ptr != NULL)
	{
		// Test Member Access
		printf("Initial Array %s\n", ptr->array );
		// Test length()
		printf("Length %d\n", ptr->length(ptr));

		// Test contains()
		printf("Count of %c is %d\n", c, ptr->contains(ptr, 'z') );

		// Testing Append
		String* append = new_String(arr2);
		printf("String to append \"%s\" of length %d\n", append->array, append->length(append));
		// Test destroy()
		ptr->destroy(ptr);
	}
	else
	{
		printf("Error creating String");
	}
}