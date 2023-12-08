#include <stdio.h>
#include <string.h>
#include <ctype.h>

void print_square(char arr[12][9]);
void initialize_board(char arr[12][9]);
void move_piece(char arr[12][9], int A, int B, char turn);
void select_piece(char arr[12][9], char turn);
int convert_character(char Z);
  
int main()
{
  int playing = 1;
  char arr[12][9];
  char turn = 'B';

  printf("Welcome to the game\n pieces: 🍺>🍻>🍾 || 🍪>🥯>🥞\n");

  initialize_board(arr);
  print_square(arr);
  select_piece(arr, turn);

  return (0);
}

/**
 *Handles selecting of pieces
 */
void select_piece(char arr[12][9], char turn)
{
  char A, B;
  int a, b, c;

  if (turn != 'B' && turn != 'C')
    turn = 'B';

  printf("Please select a piece, it is now %c's turn\n", turn);
  while(1)
    {
      printf("A: ");
      A = toupper(getchar());
      while ((c = getchar()) != '\n' && c != EOF);
      printf("0: ");
      B = getchar();

      a = convert_character(A);
      b = (B - '0') - 1;

      if (arr[a][b] == turn)
	{
	  /** Visual feedback */
	  arr[a][b] = 'X';
	  printf("Piece at %c %c selected\n", A, B);
	  printf("============\n");
	  /** Move piece handler*/
	  move_piece(arr, a, b, turn);
	}
      else
	{
	  printf("Invalid piece\n");
	}
    }
}

void move_piece(char arr[12][9], int A, int B, char turn)
{
  int i = 0, c;
  while ((c = getchar()) != '\n' && c != EOF);
  printf("Possilbe movements:\n");

  /** Frontal movement representation*/
  if (A < 12)
    {
      arr[A + 1][B] = '@';
      if (B < 9)
	arr[A + 1][B + 1] = '@';
      if (B > 0)
	arr[A + 1][B - 1] = '@';
    }

  /** Diagonal back movement representation*/
  if (A > 1)
    {
      if (B < 9)
	arr[A - 1][B + 1] = '@';
      if (B > 0)
	arr[A - 1][B - 1] = '@';
    }
  print_square(arr);

  i = getchar();
  printf("Invalid move\n");
}

/**
 *Converts a char to an int
 */
int convert_character(char Z)
{
  /**
   * A = 0, B = 1, etc...
   */
  int i = 0;
  char A = 'A';

  while (A != Z)
    {
      A++;
      i++;
    }

  return(i);
}

void initialize_board(char arr[12][9])
{
  int i, j;
  for(i = 0; i < 12; i++)
    {
      for(j = 0; j < 9; j++)
	{
	  if (i == 0 && (j < 4 || j > 4))
	    arr[i][j] = 'B';
	  else if (i == 11 && (j < 4 || j > 4))
	    arr[i][j] = 'C';
	  else
	    arr[i][j] = '#';
	}
    }
}

void print_square(char arr[12][9])
{
  int i, j, k = 1;
  char alpha = 'A';

  printf("============\n");
  putchar(' ');
  for (k = 1; k < 10; k++)
    printf("%d", k);
  putchar('\n');

  for(i = 0; i < 12; i++)
    {
      for(j = 0; j < 9; j++)
	{
	  if (j == 0)
	    printf("%c", alpha++);
	  printf("%c", arr[i][j]);
	}
      printf("\n");
    }
  printf("============\n");
}
