#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../gen_lib/bstr.c"

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



int main() {

  String t = string_create("hello");
  String s = string_create("hello");

  assert_true(
    string_is_equal(&t, &s),
    "Strings with same chars should be equal."
  );
  
  t.capacity += 8;

  assert_true(
    string_is_equal(&t, &s),
    "Strings with same chars but different capacities should be equal."
  );

  assert_false(
    t.capacity == s.capacity,
    "Strings should not have same capacities."
  );
  
  return 0;
}