# C-String-Handler
A string handler in c, that makes u able to use a lot of high language functions


int main() {
    const char* str1 = "Hello, world!";
    const char* str2 = "C is awesome!";
    const char* old_sub = "world";
    const char* new_sub = "universe";

    // Concatenate two strings using the existing function
    char* concatenated = string_concat(str1, str2);
    printf("Concatenated string: %s\n", concatenated);
    free(concatenated);

    // Concatenate two strings using the new function
    char result[MAX_LENGTH];
    concatenateStrings(str1, str2, result);
    printf("Concatenated string (new function): %s\n", result);

    // Find the length of a string using the existing function
    int length = string_length(str1);
    printf("Length of str1: %d\n", length);

    // Find the length of a string using the new function
    size_t len = stringLength(str1);
    printf("Length of str1 (new function): %zu\n", len);

    // Extract a substring using the existing function
    int start_index = 1;
    int end_index = 4;
    char* substring = string_slice(str1, start_index, end_index);
    printf("Substring: %s\n", substring);
    free(substring);

    // Extract a substring using the new function
    char sliced[MAX_LENGTH];
    sliceString(str1, start_index, end_index, sliced);
    printf("Substring (new function): %s\n", sliced);

    // Find and replace all occurrences of a substring using the existing function
    char* replaced = string_replace(str1, old_sub, new_sub);
    printf("Replaced string: %s\n", replaced);
    free(replaced);

    // Find and replace all occurrences of a substring using the new function
    char replaced_str[MAX_LENGTH];
    replaceSubstring(str1, old_sub, new_sub, replaced_str);
    printf("Replaced string (new function): %s\n", replaced_str);

    return 0;
}
