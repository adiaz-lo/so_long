#include "so_long.h"

void throw_error(char *string_error) {
  perror(string_error); // ¿Cambiar por ft_printf para evitar el errno en el
                        // output?
  exit(1);
}
