#include <stdio.h>
#include "../libft.h"

int ft_count_words(char const *s, char c);

/*int main(int argc, char *argv[]){
	//char	frase[] = "Alberto Díaz Lobezno";
	char	frase[] = "Alberto"; 
	char	**vuelta;
	int	i;

	vuelta = ft_split(frase, ' ');
	i = 0;
	while (i < ft_count_words(frase, ','))
	{
		printf("Split: %s\n", vuelta[i]);
		i++;
	}
	//printf("Token Number: %d\n", count_words(argv[1], ' '));
}
*/

int	main(int argc, char **argv)
{
	char	**vuelta;
	int	i;

	i = 0;
	vuelta = ft_split(argv[1], ' ');
	while (i <= ft_count_words(argv[1], ' '))
	{
		printf("Split: %s\n", vuelta[i]);
		i++;
	}
		printf("Word Number: %d\n", ft_count_words(argv[1], ' '));
}
