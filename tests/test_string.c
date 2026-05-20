#include <stdio.h>
#include <stdbool.h>

void assert_true(bool condition, const char *message);
void assert_false(bool condition, const char *message);

void assert_true(bool condition, const char *message) {

  if (!condition) {
    printf("[X] FAIL: %s\n", message);
    exit(1);
  }

  printf("[ ] PASS: %s\n", message);

}

void assert_false(bool condition, const char *message) {

  if (condition) {
    printf("[X] FAIL: %s\n", message);
    exit(1);
  }

  printf("[ ] PASS: %s\n", message);

}