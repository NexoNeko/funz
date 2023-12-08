#include <stdio.h>

int main(int argc, char *argv[])
{
  int i = 0, j = 0;

  /**If we have no arguments, dont print the text box */
  if (argc > 1)
    {
      /** Prints the top box border */
      printf("             |");
      for (int i = 1; i < argc; i++)
	{
	  for (j = 0; argv[i][j] != '\0'; j++)
	    printf("-");
	  if (i > 1)
	    printf("-");
	  j = 0;
	}
      printf("|\n");

      /**This is where the actual
       * text begins to get printed */
      printf("             |");
      for (int i = 1; i < argc; i++)
	{
	  printf("%s", argv[i]);
	  if (i != argc - 1)
	    putchar(' ');
	}
      printf("|\n");

      /**This prints the bottom line */
      printf("              ");
      for (int i = 1; i < argc; i++)
	{
	  for (j = 0; argv[i][j] != '\0'; j++)
	    printf("-");
	  if (i > 1)
	    printf("-");
	  j = 0;
	}
      /** Prints the '\/' */
      printf("\n              \\/\n");
    }

  /**Prints the cow */
  printf("           __n__n__\n    .------`-\\00/-'\n   /  ##  ## (oo)\n  / \\## __   ./\n     |//YY \\|/\n     |||   |||\n");

  return (0);
}
