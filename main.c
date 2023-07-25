#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

int string_length(const char* str) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

char* string_concat(const char* str1, const char* str2) {
    int len1 = string_length(str1);
    int len2 = string_length(str2);

    char* result = (char*)malloc((len1 + len2 + 1) * sizeof(char));

    if (result == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    int i, j;

    for (i = 0; i < len1; i++) {
        result[i] = str1[i];
    }

    for (j = 0; j < len2; j++) {
        result[i + j] = str2[j];
    }

    result[i + j] = '\0';

    return result;
}

char* string_slice(const char* str, int start, int end) {
    int len = string_length(str);

    // Check for valid indices
    if (start < 0 || start >= len || end < 0 || end >= len || start > end) {
        printf("Invalid start or end index.\n");
        exit(1);
    }

    int slice_len = end - start + 1;
    char* result = (char*)malloc((slice_len + 1) * sizeof(char));

    if (result == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    int i;
    for (i = start; i <= end; i++) {
        result[i - start] = str[i];
    }

    result[i - start] = '\0';

    return result;
}

char* string_replace(const char* str, const char* old_sub, const char* new_sub) {
    int len = string_length(str);
    int old_sub_len = string_length(old_sub);
    int new_sub_len = string_length(new_sub);

    // Count the occurrences of the old_sub in str
    int count = 0;
    const char* tmp = str;
    while ((tmp = strstr(tmp, old_sub)) != NULL) {
        count++;
        tmp += old_sub_len;
    }

    // Calculate the length of the new string
    int new_len = len + count * (new_sub_len - old_sub_len);

    char* result = (char*)malloc((new_len + 1) * sizeof(char));
    if (result == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    int i = 0;
    while (*str) {
        if (strstr(str, old_sub) == str) {
            strcpy(&result[i], new_sub);
            i += new_sub_len;
            str += old_sub_len;
        } else {
            result[i++] = *str++;
        }
    }
    result[i] = '\0';

    return result;
}

void concatenateStrings(const char *str1, const char *str2, char *result) {
    strcpy(result, str1); // Uses strcpy to copy str1 to the result buffer
    strcat(result, str2); // Uses strcat to concatenate str2 to the result buffer
}

size_t stringLength(const char *str) {
    return strlen(str); // Uses strlen to calculate the length of the string
}

void copyString(const char *source, char *destination) {
    strcpy(destination, source);
}

int compareStrings(const char *str1, const char *str2) {
    return strcmp(str1, str2);
}

int findSubstring(const char *str, const char *substring) {
    char *found = strstr(str, substring);
    return (found != NULL) ? (found - str) : -1;
}

int containsSubstring(const char *str, const char *substring) {
    return (strstr(str, substring) != NULL);
}

void replaceSubstring(const char *original, const char *substring, const char *replacement, char *result) {
    const char *found = strstr(original, substring); // Uses strstr to find the substring in the original string
    if (found) {
        int beforeSub = found - original; // Calculates the position before the substring
        strncpy(result, original, beforeSub); // Uses strncpy to copy characters before the substring to the result buffer
        result[beforeSub] = '\0'; // Null-terminates the result buffer at the end of the copied part
        strcat(result, replacement); // Uses strcat to concatenate the replacement string to the result buffer
        strcat(result, found + strlen(substring)); // Uses strcat to concatenate characters after the substring to the result buffer
    } else {
        strcpy(result, original); // If the substring is not found, copies the original string as is to the result buffer
    }
}

void sliceString(const char *str, int start, int end, char *sliced) {
    if (start < 0 || end >= strlen(str) || start > end) {
        printf("Invalid slicing indices.\n");
        sliced[0] = '\0';
    } else {
        int i, j = 0;
        for (i = start; i <= end; i++) {
            sliced[j++] = str[i];
        }
        sliced[j] = '\0';
    }
}

