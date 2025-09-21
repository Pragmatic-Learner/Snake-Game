#include <stdio.h>

#define GRIDY 30
#define GRIDX GRIDY * 2
#define SPACE ' '
#define HEAD '@'
#define BODY '0'
#define BODYVERTICAL '|'
#define BODYHORIZONTAL '-'
#define INITIALSIZE 3


enum AXIS{X, Y, POINT};
enum DIRECTION{RIGHT, LEFT, DOWN, UP, KILL};

int loop = 1;
int snake[3][GRIDX * GRIDY], length = INITIALSIZE;

void clr(){printf("\e[1;1H\e[2J");}
void draw(), initializeSnake(), input_reader(), movement(int direction);

int main() {
  /*code gaes here*/
  initializeSnake();
  while(loop) {
    clr();
    draw();
    input_reader();
  }
  return 0;
}


void initializeSnake() {
  for (int initialize = 0; initialize < INITIALSIZE; initialize++) {
    snake[X][initialize] = INITIALSIZE - initialize - 1;
    snake[Y][initialize] = 0;
    snake[POINT][initialize] = RIGHT;
  }
}

void draw(){
  for (int x = 0; x < GRIDX; x++)
    printf("_");

  printf("\n");

  for (int y = 0; y < GRIDY; y++) {
    for (int x = 0; x < GRIDX; x++) {
      for (int segment = 0; segment < length; segment++) {
        /*Check each segment, must look for better way*/
        if (snake[X][segment] == x && snake[Y][segment] == y) {
          if (segment == 0) {
            printf("%c", HEAD);
          } else {
            if (snake[POINT][segment] == LEFT || snake[POINT][segment] == RIGHT) {
              printf("%c", BODYHORIZONTAL);
            } else if (snake[POINT][segment] == UP || snake[POINT][segment] == DOWN) {
              printf("%c", BODYVERTICAL);
            }
          }
          break;
        } else if (segment == length - 1) {
          printf("%c", SPACE);
        }
      }
    }
    printf("|\t%d\n", y);
  }

  for (int x = 0; x < GRIDX; x++)
    printf("_");

  printf("\n");
}

void input_reader() {
  switch (getchar()) {
    case 'a':
      movement(LEFT);
      break;
    case 'd':
      movement(RIGHT);
      break;
    case 'w':
      movement(UP);
      break;
    case 's':
      movement(DOWN);
      break;
    case 'q':
      loop = 0;
    default:
      break;
  }
}

void movement(int direction) {
  for (int i = length - 1; i > 0; i--) {
    snake[X][i] = snake[X][i - 1];
    snake[Y][i] = snake[Y][i - 1];
    snake[POINT][i] = snake[POINT][i - 1];
  }
  switch (direction) {
    case LEFT:
      snake[X][0] -= 1;
      snake[POINT][0] = LEFT;
      break;
    case RIGHT:
      snake[X][0] += 1;
      snake[POINT][0] = RIGHT;
      break;
    case UP:
      snake[Y][0] -= 1;
      snake[POINT][0] = UP;
      break;
    case DOWN:
      snake[Y][0] += 1;
      snake[POINT][0] = DOWN;
      break;
  }
}
