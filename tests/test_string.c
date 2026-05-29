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

  printf("\n==== TESTING _create() & _print() ====\n");

  String a = string_create("hello, world!");
  String b = string_create("0123456");

  string_print(&a);

  assert_true(
    a.length == (size_t)13,
    "String 'hello, world!' should have length of 13."
  );
  assert_true(
    a.data[0] == 'h',
    "First char of 'hello, world!' should be 'h'."
  );
  assert_true(
    b.data[4] == '4',
    "Char at index 4 of '0123456' should be '4'."
  );


  printf("\n==== TESTING _clear() ====\n");

  size_t a_cap = a.capacity;
  string_clear(&a, false);
  assert_true(
    a.length == 0, 
    "Length of string after clear should be 0, despite containing a null terminator."
  );
  assert_true(
    a.data[0] == '\0',
    "Empty string should start with a null terminator."
  );
  assert_true(
    a.capacity == a_cap, 
    "String capacity should remain the same after _clear() when reset_capacity=false."
  );
  string_clear(&a, true);
  assert_false(
    a.capacity == a_cap, 
    "String capacity should decrease after _clear() when reset_capacity=true."
  );
  assert_true(
    a.capacity == (size_t)8, 
    "Empty string capacity should be reduced to 8."
  );


  printf("\n==== TESTING _delete() ====\n");
  string_delete(&a);

  string_print(&b);
  string_delete(&b);

  assert_true(
    b.length == 0 && b.capacity == 0,
    "String length and capacity should both be 0 after _delete()."
  );


  printf("\n==== TESTING CAPACITY AND _is_equal() ====\n");

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