#include "s21_string.h"

//  1
void *s21_memchr(const void *str, int c, s21_size_t n) {
    unsigned char *p = (unsigned char*)str;
    unsigned char *isCharFound = s21_NULL;

    while ((str != s21_NULL) && (n--)) {
        if (*p != (unsigned char)c) {
            p++;
        } else {
            isCharFound = p;
            break;
        }
    }
    return isCharFound;
}

//  2
int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
    const unsigned char *p = str1;
    const unsigned char *q = str2;
    int charCompareCheck = 0;
    if (str1 == str2) {
        return charCompareCheck;
    }

    while (n > 0) {
        if (*p != *q) {
            if (*p > *q) {
                charCompareCheck = 1;
            } else {
                charCompareCheck = -1;
            }
            break;
        }
        n--;
        p++;
        q++;
    }
    return charCompareCheck;
}

//  3
void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
    char* d = dest;
    const char* s = src;
    for (int i = 0; i < (int)n; i++) {
        d[i] = s[i];
    }
    return dest;
}

//  4
void *s21_memmove(void *dest, const void *src, s21_size_t n) {
    //  unsigned char isCopyRequire = 0;
    char *pDest = (char*)dest;
    const char *pSrc = (const char*)src;

    if ((pSrc == s21_NULL) || (pDest == s21_NULL)) {
        return s21_NULL;
    }

    if ((pSrc < pDest) && (pDest < pSrc + n)) {
        for (pDest += n, pSrc +=n; n--;) {
            *--pDest = *--pSrc;
        }
    } else {
        while (n--) {
            *pDest++ = *pSrc++;
        }
    }
    return dest;
}

//  5
void *s21_memset(void *str, int c, s21_size_t n) {
    unsigned char* p = str;

    while (n--) {
        *p++ = (unsigned char)c;
    }

    return str;
}

//  6
char* s21_strcat(char *dest, const char* src) {
    int i, j;

    for (i = 0; dest[i] != '\0'; i++) {}

    for (j = 0; src[j] != '\0'; j++) {
        dest[i + j] = src[j];
    }

    dest[i + j] = '\0';

    return dest;
}

//  7
char *s21_strncat(char *dest, const char *src, s21_size_t n) {
    int i, j;

    for (i = 0; dest[i] != '\0'; i++) {
    }

    for (j = 0; src[j] != '\0' && j < (int)n; j++) {
        dest[i + j] = src[j];
    }

    dest[i + j] = '\0';

    return dest;
}

//  8
char *s21_strchr(const char *str, int c) {
    const char *isCharFound = s21_NULL;

    if (str != s21_NULL) {
        do {
            if (*str == (char)c) {
                isCharFound = str;
                break;
            }
        }
        while (*str++);
    }
    return (char *)isCharFound;
}

//  9
int s21_strcmp(const char *str1, const char *str2) {
    while (*str1) {
        if (*str1 != *str2) {
            break;
        }
        str1++;
        str2++;
    }
    return *(const unsigned char*)str1 - *(const unsigned char*)str2;
}

//  10
// NEEEEEEEEED EXTRA FIX NEEEEEEEEED EXTRA FIX
int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
    while (*str1) {
        int k = 1;
        if (*str1 != *str2 || k <= (int)n) {
            break;
        }
        str1++;
        str2++;
        k++;
    }
    return *(const unsigned char*)str1 - *(const unsigned char*)str2;
}

//  11
char *s21_strcpy(char *dest, const char *src) {
    for (int i = 0; src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    return dest;
}

//  12
char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
    if ((dest == s21_NULL) && (src == s21_NULL)) {
        return s21_NULL;
    }

    char* start = dest;

    while (*src && n--) {
        *dest = *src;
        dest++;
        src++;
    }

    *dest = '\0';

    return start;
}

//  13
s21_size_t s21_strcspn(const char *str1, const char *str2) {
    int count = 0;
    for (int i = 0; str1[i] != '\0'; i++) {
        for (int j = 0; j < str2[j] && str2[j]!= '\0'; j++) {
            if (str1[i] == str2[j]) {
                count = i++;
                break;
            }
        }
        if (count > 0) {
            break;
        }
    }
    return count;
}

//  14
char *int_to_char(int number) {
    /* Функция для преобразования числа в символьный массив. Принимает
     число int и возвращает массив символов char */

    static char str1[20];
    char part_number;
    int temp_number = number, i = 0;

    if (number < 0) {
        temp_number *= -1;
    } else if (number == 0) {
        str1[i++] = '0';
    }

    for (; temp_number; i++) {
        part_number = (char)(temp_number%10) + '0';
        str1[i] = part_number;
        temp_number /= 10;
    }

    if (number < 0) {
        str1[i++] = '-';
    }

    for (int temp, j = 0; j < (i + (i%2))/2; j++) {
        temp = str1[j];
        str1[j] = str1[i-1-j];
        str1[i-1-j] = temp;
    }

    str1[i] = '\0';

    return str1;
}

char *s21_strerror(int errnum) {
    /* Ищет во внутреннем массиве номер ошибки errnum и возвращает указатель
     на строку сообщения об ошибке. */
    char *error_code, *p;

    if (Mac) {
        if (errnum >= MIN && errnum <= MAX) {
            p = STRERROR_ERRORS[errnum];
        } else {
            char error_unknown[50] = "Unknown error: ";
            error_code = int_to_char(errnum);
            s21_strcat(error_unknown, error_code);
            p = error_unknown;
        }
    } else if (Linux) {
        if (errnum >= MIN && errnum <= MAX) {
            p = STRERROR_ERRORS[errnum];
        } else {
            char error_unknown[50] = "Unknown error ";
            error_code = int_to_char(errnum);
            s21_strcat(error_unknown, error_code);
            p = error_unknown;
        }
    }

    return p;
}

//  15
s21_size_t s21_strlen(const char *str) {
    s21_size_t len = 0;
    for (; str[len]; len++) {}
    return len;
}

//  16
char *s21_strpbrk(const char *str1, const char *str2) {
    if ((str1 == s21_NULL) || (str2 == s21_NULL)) {
        return s21_NULL;
    }

    while (*str1) {
        if (s21_strchr(str2, *str1)) {
            return (char*)str1;
        } else {
            str1++;
        }
    }
    return s21_NULL;
}

//  17
char *s21_strrchr(const char *str, int c) {
    const char *isCharFound = s21_NULL;

    if (str != s21_NULL) {
        do {
            if (*str == (char)c) {
                isCharFound = str;
            }
        }
        while (*str++);
    }
    return (char *)isCharFound;
}

//  18
s21_size_t s21_strspn(const char *str1, const char *str2) {
    unsigned int len = 0;

    if ((str1 == s21_NULL) || (str2 == s21_NULL)) {
        return len;
    }

    while (*str1 && s21_strchr(str2, *str1++)) {
        len++;
    }
    return len;
}

//  19
int compare(const char *haystack, const char *needle) {
    while (*haystack && *needle) {
        if (*haystack != *needle) {
            return 0;
        }
        haystack++;
        needle++;
    }
    return (*needle == '\0');
}

char *s21_strstr(const char *haystack, const char *needle) {
    while (*haystack != '\0') {
        if ((*haystack == *needle) && compare(haystack, needle)) {
            return (char*)haystack;
        }
        haystack++;
    }
    return s21_NULL;
}

//  20
unsigned int is_delim(char c, const char *delim) {
    while (*delim != '\0') {
        if (c == *delim) {
            return 1;
        }
        delim++;
    }
    return 0;
}

char *s21_strtok(char *str, const char *delim) {
    static char *backup_string;

    if (!str) {
        str = backup_string;
    }
    if (!str) {
        return s21_NULL;
    }

    while (1) {
        if (is_delim(*str, delim)) {
            str++;
            continue;
        }
        if (*str == '\0') {
            return s21_NULL;
        }
        break;
    }

    char *ret = str;

    while (1) {
        if (*str == '\0') {
            backup_string = str;
            return ret;
        }
        if (is_delim(*str, delim)) {
            *str = '\0';
            backup_string = str + 1;
            return ret;
        }
        str++;
    }
}