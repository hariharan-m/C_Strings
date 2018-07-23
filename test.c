#include "cstring.h"
#include "stdio.h"
void main(int argc, char const *argv[])
{
	char arr[] = "test_string";
	char arr2[] = "append_this";
	char arr3[] = "atest";
	char c = 's';
	char i = 'z';
	int n = 22;
	String* ptr = new_String("test_string");
	if (ptr != NULL)
		{
			// Test Member Access
			printf("Initial String: %s\n", ptr->array );
			// Test length()
			printf("Length: %d\n", ptr->length(ptr));

			// Test contains()
			printf("Count of %c is: %d\n", c, ptr->contains(ptr, c) );

			// Testing Append
			String* appStr = new_String(arr2);
			printf("String to append: \"%s\" of length: %d\n", appStr->array, appStr->length(appStr));
			ptr->append(ptr, appStr);
			printf("Appended String: %s of length: %d\n", ptr->array, ptr->length(ptr) );

			// Testing Substring
			String* subStr = new_String(arr3);
			if (ptr->findSubstring(ptr, subStr))
				{
					printf("Substring %s present\n", arr3);
				}
			else
				{
					printf("Substring %s not present\n", arr3);
				}

			// Testing insert
			ptr->insertAt(ptr, n, i);
			printf("Initial String: %s\n", ptr->array );
			// Test length()
			printf("Length: %d\n", ptr->length(ptr));
			// Test destroy()
			ptr->destroy(ptr);
		}
	else
		{
			printf("Error creating String");
		}
}