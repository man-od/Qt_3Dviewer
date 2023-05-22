#ifndef OBJ_DATA_H
#define OBJ_DATA_H

typedef enum { NO_EXC, NO_FILE, INVALID_FILE, ALLOC_FAIL } exc_t;

typedef struct {
  float *position;
  float max[3];
  float min[3];
  unsigned int size;
  unsigned int capacity;
} ObjVertex;

typedef struct {
  unsigned int *index;
  unsigned int size;
  unsigned int capacity;
} ObjFacet;

typedef struct {
  exc_t exception;

  unsigned int vertex_count;
  unsigned int facet_count;

  ObjVertex vertices;
  ObjFacet facets;
} ObjData;

#ifdef __cplusplus
extern "C" {
#endif

ObjData *obj_data_get(const char *);
void obj_data_destroy(ObjData *);

#ifdef __cplusplus
}
#endif

#endif  // OBJ_DATA_H
