#include <stdio.h>
#include <strings.h>
#include "libft.h"

int main(int argc, char *argv[]){
	char	*str_srch = "Halfonso";
	char	ctf = 'o';

	printf("ft_strrchr: %s\n", ft_strrchr(str_srch, ctf)); 
	printf("strrchr: %s\n", strrchr(str_srch, ctf)); 
	//printf("Token Number: %d\n", count_words(argv[1], ' '));
}
