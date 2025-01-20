#include "so_long.h"

int open_file(char *file) {
  int map_fd;

  /*Initialize the map, to null */
  /*Read map (iterate the file), save it in the matrix & print it, test it with different maps*/
  /*Create function debug(char **map), it iterates it and print it*/
  map_fd = open(file, O_RDONLY);
  if (map_fd == -1)
    throw_error("The map couldn't be open successfully");
  return (map_fd);
}
