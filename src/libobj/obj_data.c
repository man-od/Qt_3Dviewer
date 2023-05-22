#include "obj_data.h"

#include <float.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 65536

static inline int is_space(char c) {
  return (c == ' ') || (c == '\t') || (c == '\r');
}

static inline int is_digit(char c) { return (c >= '0') && (c <= '9'); }

static inline float max(float num1, float num2) {
  return (num1 > num2) ? num1 : num2;
}

static inline float min(float num1, float num2) {
  return (num1 < num2) ? num1 : num2;
}

static inline const char *skip_space(const char *ptr) {
  for (; is_space(*ptr); ptr++)
    ;
  return ptr;
}

static inline const char *skip_line(const char *ptr) {
  for (; *ptr != '\n'; ptr++)
    ;
  return ++ptr;
}

static inline const char *next_index(const char *ptr) {
  if (*ptr == '/') {
    ptr++;
    for (; is_digit(*ptr); ptr++)
      ;
    ptr = next_index(ptr);
  }
  ptr = skip_space(ptr);
  return ptr;
}

static inline void obj_init(ObjData *data) {
  data->vertices.capacity = 1;
  data->facets.capacity = 1;
  data->vertices.max[0] = FLT_MIN;
  data->vertices.max[1] = FLT_MIN;
  data->vertices.max[2] = FLT_MIN;
  data->vertices.min[0] = FLT_MAX;
  data->vertices.min[1] = FLT_MAX;
  data->vertices.min[2] = FLT_MAX;
}

static inline exc_t push_position(ObjVertex *vertices, float position) {
  exc_t exc = NO_EXC;
  if (vertices->size == vertices->capacity - 1) {
    vertices->capacity *= 2;
    vertices->position = (float *)realloc(vertices->position,
                                          vertices->capacity * sizeof(float));
  }
  if (!vertices->position) {
    exc = ALLOC_FAIL;
  } else {
    vertices->position[vertices->size++] = position;
  }
  return exc;
}

static inline exc_t push_index(ObjFacet *facets, unsigned int index) {
  exc_t exc = NO_EXC;
  if (facets->size == facets->capacity - 1) {
    facets->capacity *= 2;
    facets->index = (unsigned int *)realloc(
        facets->index, facets->capacity * sizeof(unsigned int));
  }
  if (!facets->index) {
    exc = ALLOC_FAIL;
  } else {
    facets->index[facets->size++] = index;
  }
  return exc;
}

static const char *parse_vertex(const char *ptr, ObjVertex *vertices,
                                exc_t *exc) {
  float position;
  char *end = NULL;
  for (int axis = 0; (axis < 3) && (!*exc); axis++) {
    position = strtof(ptr, &end);
    if (end == ptr) {
      *exc = INVALID_FILE;
    } else {
      ptr = end;
      vertices->max[axis] = max(position, vertices->max[axis]);
      vertices->min[axis] = min(position, vertices->min[axis]);
      *exc = push_position(vertices, position);
    }
    ptr = skip_space(ptr);
  }
  return ptr;
}

static const char *parse_facet(const char *ptr, ObjFacet *facets,
                               unsigned int vert_size, exc_t *exc) {
  char *end = NULL;
  long int tmp_i;
  unsigned int start_i = facets->size, index;
  while ((*ptr != '\n') && (!*exc)) {
    tmp_i = strtol(ptr, &end, 10) - 1;
    index = (tmp_i < 0) ? (vert_size + 1) - (unsigned int)(-tmp_i)
                        : (unsigned int)tmp_i;
    if (end == ptr || index >= vert_size) {
      *exc = INVALID_FILE;
    } else {
      ptr = end;
      if (facets->size != start_i) {
        *exc = push_index(facets, index);
      }
      if (!*exc) {
        *exc = push_index(facets, index);
        ptr = next_index(ptr);
      }
    }
  }
  if (!*exc) {
    *exc = push_index(facets, facets->index[start_i]);
  }
  return ptr;
}

static void parse_buffer(const char *ptr, const char *end, ObjData *obj_data) {
  while ((ptr != end) && (!obj_data->exception)) {
    ptr = skip_space(ptr);
    if (*ptr == 'v') {
      ptr++;
      if (is_space(*ptr)) {
        ptr = parse_vertex(ptr, &obj_data->vertices, &obj_data->exception);
        obj_data->vertex_count++;
      }
    } else if (*ptr == 'f') {
      ptr++;
      if (is_space(*ptr)) {
        ptr = parse_facet(ptr, &obj_data->facets, obj_data->vertex_count,
                          &obj_data->exception);
        obj_data->facet_count++;
      }
    }
    ptr = skip_line(ptr);
  }
}

static void obj_read(ObjData *obj_data, const char *path) {
  FILE *file = fopen(path, "rb");
  if (!file) {
    obj_data->exception = NO_FILE;
  } else {
    unsigned int read, bytes;
    char *start, *end, *last;
    char *buffer = (char *)realloc(0, 2 * BUFFER_SIZE);
    if (!buffer) {
      obj_data->exception = ALLOC_FAIL;
    } else {
      start = buffer;
      while (!obj_data->exception) {
        read = fread(start, 1, BUFFER_SIZE, file);
        if (!read && start == buffer) {
          break;
        }
        if (read < BUFFER_SIZE) {
          if (!read || start[read - 1] != '\n') {
            start[read++] = '\n';
          }
        }
        end = start + read;
        if (end == buffer) {
          break;
        }
        last = end;
        while (last > buffer) {
          last--;
          if (*last == '\n') {
            break;
          }
        }
        if (*last != '\n') {
          break;
        }
        last++;
        parse_buffer(buffer, last, obj_data);
        bytes = (unsigned int)(end - last);
        memmove(buffer, last, bytes);
        start = buffer + bytes;
      }
    }
    fclose(file);
    free(buffer);
  }
}

ObjData *obj_data_get(const char *path) {
  ObjData *obj_data = (ObjData *)calloc(1, sizeof *obj_data);
  if (obj_data && strcmp(path, "0") != 0) {
    obj_init(obj_data);
    obj_read(obj_data, path);
  }
  return obj_data;
}

void obj_data_destroy(ObjData *obj_data) {
  if (obj_data) {
    free(obj_data->vertices.position);
    free(obj_data->facets.index);
    free(obj_data);
  }
}
