#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct player {
  char user_name[30];
  int score;
  int rounds;
};

struct player tracey;

int bit = 8;

int setup_game (struct player);

void get_binary (char *);

void print_binary (char *);

int get_results(char *);

int user_score (int *, int, struct player);

int start_game ();

// ==== Begin Main Function ==== //
int main(int argc, char *argv[]) {

  int i = 0;
  int rounds = setup_game (tracey);
  int max_score = rounds * 100;
  int percent = 0;

  if (rounds > 10) {
    printf("Sorry I Can't Go That High\n");
    return 1;
  }

  while (i < rounds) {
    printf("Current Score: { %d }\n\n", tracey.score);
    start_game ();
    i++;
  }

  percent = (tracey.score * 100) / max_score;

  printf("\nYour Final Score Is: { %d Out Of %d Points } Thats %d%%\n", tracey.score, max_score, percent);

  return 0;
}
// ==== End Main Function ==== //

int setup_game (struct player one) {
  printf("Hello There And Welcome To Binary Math Game!!\n");

  printf("Before We Begin Let's Add Your Username: ");
  scanf("%s", one.user_name);

  printf("Awesome %s, How Many Rounds Would You Like To Play: (Max Rounds: 10) ", one.user_name);
  scanf("%d", &one.rounds);
  printf("\n");

  return one.rounds;
}

void get_binary (char *bin_ptr) {
  int num = 0;
  srand(time(0));

  for (int i = 0; i < bit; i++) {
    num = rand() % 2;
    if (num == 0) {
      bin_ptr[i] = '0';
    } else if (num == 1) {
      bin_ptr[i] = '1';
    }
  }

}

void print_binary (char *bin_ptr) {
  for (int i = 0; i < bit; i++) {
    printf("%c\t", bin_ptr[i]);
  }
  printf("\n");
}

int get_results(char *bin) {
  int res = 0;

  if (bin[7] == '1') {
    res += 1;
  }
   if (bin[6] == '1') {
    res += 2;
  }
  if (bin[5] == '1') {
    res += 4;
  }
   if (bin[4] == '1') {
    res += 8;
  }
  if (bin[3] == '1') {
    res += 16;
  }
  if (bin[2] == '1') {
    res += 32;
  }
  if (bin[1] == '1') {
    res += 64;
  }
  if (bin[0] == '1') {
    res += 128;
  }

  return res;
}

int user_score (int *int_ptr, int res, struct player one) {
  printf("\nWhat's The Final Result Of This Binary Number: (Remember To Read From Right (0) To Left (128)) \n");
  scanf("%d", int_ptr);

  if (*int_ptr == res) {
    printf("Congragulations, You Nailed It Right On The Head!!!!\n");
    one.score = 100;
  } else {
    printf("OH, Sorry But That's Not Correct...\n");
  }

  printf("\nThe Final Result Is: { %d }\n\n", res);

  return one.score;
}

int start_game () {
  int res = 0;
  int score = 0;
  char bin[bit];
  char *bin_ptr = bin;
  int user_guess = 0;
  int *guess_ptr = &user_guess;

  get_binary (bin_ptr);

  print_binary (bin_ptr);

  res = get_results (bin_ptr);

  score = user_score (guess_ptr, res, tracey);
  tracey.score += score;

  return 0;
}
