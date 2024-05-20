#include "ft_printf.h"

int main(void)
{
  int n = 0;
  char *str = "My name is Luka!";

  while (n < 10)
  {
    ft_printf("#%d -> %s\n", n, str);
    n++;
  }
  return (0);
}
