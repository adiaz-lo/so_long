#include "so_long.h"

int	validate_map_name(char *map_name)
{
	char	*map_extension;
	int		result;
	int		size;

	size = ft_strlen(MAP_EXTENSION);
	// Check
	map_extension = ft_substr(map_name, ft_strlen(map_name) - size, size);
	result = ft_strncmp(".ber", map_extension, size);
	free(map_extension);
	if (result == 0)
		return (1);
	return (0);
}