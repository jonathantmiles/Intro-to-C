#include <stdio.h>

/*
    Swaps the integer values being pointed at by a and b. Keep in
    mind when you need to access a pointer's actual value (the
    address it's referring to) or the value at the address it's
    pointing at.
*/
void swap(int* a, int* b)
{
  int scratch = *a;
  *a = *b;
  *b = scratch;
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
  char *pointer = NULL;
  for (int i = 0; str[i] != '\0'; i ++) {
    if (str[i] == c) {
      pointer = &str[i];
      break;
    }
  }
  return pointer;
}

/*
    Given an empty (NULL) character pointer x and a character pointer y,
    copies the character contents of y over to x. Again, pointer arithmetic
    is necessary here. Also, make sure x points to a null character at its
    end to terminate it properly.

    Do not just use the `strcpy` function from the standard library.
*/
void string_copy(char *x, char *y)
{
  printf("copy from: %s\n", y);
  int i;
  for (i = 0; y[i]; i++) {
    x[i] = y[i];
    printf("x[i]: %c\n", x[i]);
  }
  x[i] = '\0';
  printf("copied to: %s\n", x);
}

/*
    Compares the character strings m and n and returns negative,
    0, or positive if n is lexicographically less than, equal to,
    or greater than n. To calculate lexicographic difference, find
    the difference between the first characters in m and n that differ.

    For example, given matching strings, this function should
    return 0. Given strings m = "hello world" and n = "goodbye",
    this function should return a positive value. Given strings
    m = "aardvark" and n = "zebra", should return a negative
    value.

    Do not just use the `strcmp` function from the standard library.
*/
int string_compare(char *m, char *n)
{
  for (int i = 0; m[i] || n[i]; i++) {
    if (m[i] != n[i]) {
      return (int) m[i] - (int) n[i];
    }
  }

  return 0;
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
  int searching = 1;
  char searchable_storage[100];
  char *searchable = searchable_storage[0];
  char result_storage[100];
  char *result = result_storage[0];
  string_copy(searchable, haystack);
  while (searching) {
    result = find_char(searchable, needle[0]);
    int i;
    for (i = 0; needle[i]; i++) {
      if (needle[i] != result[i]) {
        result ++;
        searchable = find_char(result, needle[0]);
        break;
      } else if (!result[i]) {
        return NULL;
      }
    }
    result[i] = '\0';
    searching = string_compare(result, needle);
  }

  return result;

  // printf("h: %s, n: %s\n", haystack, needle);
  // char *pointer = "";
  // char *result = NULL;
  // pointer = find_char(haystack, needle[0]);
  // printf("pointer: %s\n", pointer);
  // int i;
  // for (i = 0; needle[i]; i++) {
  //   printf("pointer: %s\n", pointer);
  //
  //   if (pointer[i] != needle[i]) {
  //     pointer = &pointer[1]
  //     find_char(pointer, needle[0])
  //   }
  //
  // }
  //
  // pointer[i]
    // string_copy(result, pointer);
    // printf("result: %s\n", result);
    // if you reach the end of needle without discovering a difference, return original pointer

    // if (!pointer[i]) {
    //   break;
    // } else if (pointer[i] != needle[i]) {
    //   pointer = find_char(pointer, needle[0]);
    //   printf("shunt: %s\n", pointer);
    // } else if (!needle[i]) {
    //   printf("else if: %s\n", pointer);
    //   return pointer;
    // }
    // else {
    //   printf("else\n");
    //   return NULL;
    // }

  // printf("after loop: %s\n", pointer);
  // return pointer;
}

#ifndef TESTING
int main(void)
{
    int x = 10, y = 20;
    swap(&x, &y);
    printf("x=%d, y=%d\n", x, y);

    char *hello = "Hello";
    char *world = "World";
    char buffer[1024];

    string_copy(buffer, hello);

    printf("Buffer is %s\n", buffer);
    printf("Comparison is %d\n", string_compare(hello, world));

    char *found_char = find_char(hello, 'e');
    char *found_string = find_string(world, "or");

    printf("Found char: %s\n", found_char);
    printf("Found string: %s\n", found_string);

    return 0;
}
#endif
