#include "libft.h"

int main()
{
    t_list *lista = NULL;
    t_list *elemento;
    char *contenido = "hola";
    char *contenido2 = "hola2";
    char *contenido3 = "hola3";

    printf("%p\n", elemento);
    elemento = ft_lstnew(contenido);
    printf("%p\n", elemento);

    printf("%p\n", lista);
    ft_lstadd_back(&lista, elemento);
    printf("%p\n", lista);

    elemento = ft_lstnew(contenido2);
    ft_lstadd_back(&lista, elemento);

    elemento = ft_lstnew(contenido3);
    ft_lstadd_back(&lista, elemento);

    printf("%s", (char *)lista[0].content);
    printf("%s", (char *)lista[1].content);
    printf("%s", (char *)lista[2].content);

    return (0);
}