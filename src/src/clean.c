void    clean(char **map, int map_fd)
{
    free_map(map);
    close_file(map_fd);
}