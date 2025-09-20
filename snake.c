#define GRID 10
#define SPACE ' '
#define HEAD '@'
#define BODY '0'
#define INITIALSIZE 5

#include <stdio.h>
#include <unistd.h>

enum AXIS{X = 0, Y = 1};
enum DIRECTION{RIGHT, LEFT, DOWN, UP, KILL};

int snake[2][GRID * GRID];
int length = INITIALSIZE;
char key;

void clr(){printf("\e[1;1H\e[2J");}
void draw(), initializeSnake(), input_reader(), movement(int direction);

int main() {
  /*code gaes here*/
  initializeSnake();
  while(1) {
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
  }
}

void draw(){
  int found;
  for (int x = 0; x < GRID; x++) {
    printf("_");
  }
  printf("\n");
  for (int y = 0; y < GRID; y++) {
    for (int x = 0; x < GRID; x++) {
      found = 0;
      for (int segment = 0; segment < length; segment++) {
        if (snake[X][segment] == x && snake[Y][segment] == y) {
          printf("%c", BODY);
          found = 1;
          break;
        }
      }
      if (found == 0) {
        printf("%c", SPACE);
      }
    }
    printf("|\n");
    //printf("\t| %d\n", y);
  }
  for (int x = 0; x < GRID; x++) {
    printf("_");
  }
  printf("\n");
}

void input_reader() {
  scanf("%c", &key);
  switch (key) {
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
      movement(KILL);
  }
}

void movement(int direction) {
  for (int i = length - 1; i > 0; i--) {
    snake[X][i] = snake[X][i - 1];
    snake[Y][i] = snake[Y][i - 1];
  }
  switch (direction) {
    case LEFT:
      snake[X][0] -= 1;
      break;
    case RIGHT:
      snake[X][0] += 1;
      break;
    case UP:
      snake[Y][0] -= 1;
      break;
    case DOWN:
      snake[Y][0] += 1;
      break;
  }
}
