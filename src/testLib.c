#include <idk.h>
#include <stdio.h>

int main(int argc, char **argv)
{
  if (argc > 1)
  {
    printf("%s\n", argv[1]);
    printf("%s\n", reverse(argv[1]));
  }
  else
  {
    printf("No command-line arguments provided.\n");
  }

  return 0;
}
