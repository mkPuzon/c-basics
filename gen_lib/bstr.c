#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


typedef struct {
  char *data;
  size_t length; // how many chars, including \0 are stored
  size_t capacity; // maximum space allocated
} String;


String string_create(const char *text);
void string_delete(String *s);
size_t string_get_len(const String *s);
size_t string_get_capacity(const String *s);
bool string_is_equal(const String *a, const String *b);
void string_clear(String *s, bool reset_capacity);

void string_expand(String *s, size_t size);
void string_append(String *s, const char *text);
String* string_copy(const String *s, char *dest);

// debugging
void string_print(String *s);

void string_print(String *s) {
  char c;
  printf("Length=%zu | Capacity=%zu\n", s->length, s->capacity);
  for (int i = 0; i < (int)s->capacity; i++){
    if (i > (int)s->length) {
      printf("[_]");
    } else {
      c = s->data[i];
      if (c == '\0') {
        printf("[\\0]");
      } else {
        printf("[%c]", c);
      }
    }
  }
  printf("\n");
}

String string_create(const char *text) {
  String s;

  // does NOT include null terminator
  s.length = strlen(text); 
  // allocate space to the nearest whole byte
  s.capacity = (s.length + 1) + (7 - (s.length % 8));
  // keep null terminator in data field for compatibility
  s.data = malloc(s.capacity);
  if (s.data == NULL) {
    s.length = 0;
    return s;
  }

  // doesn't rely on null terminator
  memcpy(s.data, text, s.length + 1);

  return s;
}

void string_clear(String *s, bool reset_capacity) {
  if (reset_capacity) {
    char *new_data = realloc(s->data, 8);
    if (new_data != NULL) {
      s->data = new_data;
      s->capacity = 8;
    }
  }

  s->length = 0;
  if (s->data != NULL) {
    s->data[0] = '\0';
  }
}

size_t string_get_len(const String *s) {
  return s->length;
}

size_t string_get_capacity(const String *s) {
  return s->capacity;
}

bool string_is_equal(const String *a, const String *b) {
  if (a->length != b->length) {
    return false;
  }
  return (memcmp(a->data, b->data, a->length) == 0 ? true : false);
}

void string_delete(String *s) {
  free(s->data);

  s->data = NULL;
  s->length = 0;
}
