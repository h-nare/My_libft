#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
//#include <bsd/string.h>  // For testing strlcpy, strlcat, bzero on Linux
#include "libft.h"

/* -------------------- PART 1: libc functions -------------------- */

void test_is_functions(void) {
    printf("== is* functions ==\n");
    printf("ft_isalpha('A') = %d\n", ft_isalpha('A'));
    printf("ft_isdigit('9') = %d\n", ft_isdigit('9'));
    printf("ft_isalnum('a') = %d\n", ft_isalnum('a'));
    printf("ft_isascii(127) = %d\n", ft_isascii(127));
    printf("ft_isprint(31) = %d\n\n", ft_isprint(31));
}

void test_strlen_mem(void) {
    char buf1[20] = "hello";
    char buf2[20] = "hello";

    printf("== strlen / memset / bzero ==\n");
    printf("ft_strlen(\"hello\") = %zu\n", ft_strlen("hello"));

    ft_memset(buf1, 'A', 3);
    memset(buf2, 'A', 3);
    printf("ft_memset -> %s | system memset -> %s\n", buf1, buf2);

    ft_bzero(buf1, 5);
    bzero(buf2, 5);
    printf("ft_bzero -> '%s' | system bzero -> '%s'\n\n", buf1, buf2);
}

void test_memcpy_move(void) {
    char a[20] = "abcdef";
    char b[20] = "abcdef";

    printf("== memcpy / memmove ==\n");
    ft_memcpy(a + 2, a, 3);
    memcpy(b + 2, b, 3);
    printf("ft_memcpy overlap: %s | memcpy overlap: %s\n", a, b);

    strcpy(a, "abcdef");
    strcpy(b, "abcdef");
    ft_memmove(a + 2, a, 3);
    memmove(b + 2, b, 3);
    printf("ft_memmove overlap: %s | memmove overlap: %s\n\n", a, b);
}

void test_strings(void) {
    printf("== string funcs ==\n");
    printf("ft_strchr: %s\n", ft_strchr("hello", 'l'));
    printf("ft_strrchr: %s\n", ft_strrchr("hello", 'l'));
    printf("ft_strncmp: %d\n", ft_strncmp("abc", "abd", 3));
    printf("ft_strnstr: %s\n\n", ft_strnstr("hello world", "world", 11));
}

void test_atoi_calloc_strdup(void) {
    char *s;

    printf("== atoi / calloc / strdup ==\n");
    printf("ft_atoi(\"-42\") = %d\n", ft_atoi("-42"));

    s = ft_calloc(5, sizeof(char));
    strcpy(s, "test");
    printf("ft_calloc: %s\n", s);
    free(s);

    s = ft_strdup("libft");
    printf("ft_strdup: %s\n\n", s);
    free(s);
}

/* -------------------- PART 2: extra functions -------------------- */

void test_part2(void) {
    // char **split;
    char *s;

    printf("== Part 2 ==\n");

    s = ft_substr("hello world", 6, 5);
    printf("ft_substr: %s\n", s);
    free(s);

    s = ft_strjoin("hello ", "world");
    printf("ft_strjoin: %s\n", s);
    free(s);

    s = ft_strtrim("***hello***", "*");
    printf("ft_strtrim: %s\n", s);
    free(s);

    // split = ft_split("a,b,c", ',');
    // for (int i = 0; split[i]; i++) {
    //     printf("ft_split[%d]: %s\n", i, split[i]);
    //     free(split[i]);
    // }
    // free(split);

    s = ft_itoa(-1234);
    printf("ft_itoa: %s\n\n", s);
    free(s);
}

/* -------------------- PART 3: linked list -------------------- */

void del(void *p) { free(p); }

void *toupper_str(void *p) {
    char *s = strdup((char *)p);
    for (int i = 0; s[i]; i++)
        if (s[i] >= 'a' && s[i] <= 'z') s[i] -= 32;
    return s;
}

void test_list(void) {
    t_list *lst = NULL;
    t_list *new;

    printf("== Linked list ==\n");

    ft_lstadd_back(&lst, ft_lstnew(strdup("one")));
    ft_lstadd_back(&lst, ft_lstnew(strdup("two")));
    ft_lstadd_back(&lst, ft_lstnew(strdup("three")));

    printf("ft_lstsize = %d\n", ft_lstsize(lst));
    printf("ft_lstlast = %s\n", (char *)ft_lstlast(lst)->content);

    new = ft_lstmap(lst, toupper_str, del);

    printf("Mapped list:\n");
    while (new) {
        printf("%s\n", (char *)new->content);
        new = new->next;
    }

    ft_lstclear(&lst, del);
}

/* -------------------- MAIN -------------------- */

int main(void) {
    test_is_functions();
    test_strlen_mem();
    test_memcpy_move();
    test_strings();
    test_atoi_calloc_strdup();
    test_part2();
    test_list();

    return 0;
}
