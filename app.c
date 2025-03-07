#include <stdio.h>
#include <string.h>

int main()
{

    char str1[] = "hello"; // Automatically includes '\0' at the end
    printf("String 1: %s\n", str1);
    printf("Length of String 1 (strlen): %zu\n", strlen(str1));

    // ensure add \0 in the end of array,
    char str[4] = {'h', 'a', 'n', '\0'};
    printf("%s\n", str);
    printf("Length of String 2 (strlen): %zu\n", strlen(str));
}