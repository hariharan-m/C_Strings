/** @file cstring.h
* 
* @brief String Implementation in C 
*
*/ 

// include guard
#ifndef CSTRING_H
#define CSTRING_H

// define this as extern for c++
#ifdef __cplusplus
extern "C" {
#endif

#include <libraries>

#define DEFAULT_LEN 10

typedef struct {
	char *array;

	void (*destroy)(String current);
	int (*length)(String current);
	int (*contains)(String current, char c);
	int (*findSubstring)(String current, String str);
	void (*append)(String current, String str);
	void (*insertAt)(String current, int n, char c);

} String;

String* new_String(char* array);
void _destroy(String current);
int _length(String current);
int _contains(String current, char c);
int _findSubstring(String current, String str);
void _append(String current, String str);
void _insertAt(String current, int n, char c)



// end c++ guard
#ifdef __cplusplus
}
#endif 
// end include guard
#endif
