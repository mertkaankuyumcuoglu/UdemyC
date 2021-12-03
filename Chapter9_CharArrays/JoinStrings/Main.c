#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *join(char *delimiter, char **list)
{
    if (delimiter == NULL || list == NULL || list[0] == NULL)
    {
        return NULL;
    }

    size_t delimiter_len = strlen(delimiter);
    size_t max_result_len = 100;
    char *result = (char *)malloc(max_result_len * sizeof(char));
    result[0] = '\0';

    int i = 0;
    while (list[i] != NULL)
    {
        size_t current_result_len = strlen(result);
        size_t current_input_len = strlen(list[i]);

        size_t new_result_len = current_result_len + current_input_len;

        if (i > 0)
        {
            new_result_len += delimiter_len;
        }

        if (new_result_len > max_result_len - 2)
        {
            result = realloc(result, new_result_len + 1);
        }

        if (i > 0)
        {
            strncat(result, delimiter, max_result_len);
        }

        strncat(result, list[i], max_result_len);
        i++;
    }

    return result;
}

int main()
{
    char *list1[] = {NULL};
    char *list2[] = {"Clara", NULL};
    char *list3[] = {"Clara", "Florian", NULL};
    char *list4[] = {"Clara", "Florian", "Jan", NULL};
    char *s = NULL;

    s = join(" -> ", list1); // ""
    if (s != NULL)
    {
        printf("List1: %s\n", s);
        free(s);
    }

    s = join(" -> ", list2); // "Clara"
    if (s != NULL)
    {
        printf("List2: %s\n", s);
        free(s);
    }

    s = join(" -> ", list3); // "Clara -> Florian"
    if (s != NULL)
    {
        printf("List3: %s\n", s);
        free(s);
    }

    s = join(" -> ", list4); // "Clara -> Florian -> Jan"
    if (s != NULL)
    {
        printf("List4: %s\n", s);
        free(s);
    }

    return 0;
}
