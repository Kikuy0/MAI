#include <stdlib.h>
#include <string.h>

#include "db.h"
#include "serialization.h"
#include "text.h"

/*
 * сдвинуть строки, заполнив место удаленной строки
 * db->size уменьшается на 1
 */
static void moveRows(struct database *db, size_t idx) {
  free(db->rows[idx]);

  for (size_t i = idx; i < db->size - 1; i++) {
    db->rows[i] = db->rows[i + 1];
  }

  db->size--;
}

/*
 * печатает строку
 */
static void printRow(struct row_t *row, uint8_t hightlight, uint64_t idx) {
  if (hightlight) {
    printf(FG_GREEN);
  }

  printf("%lu\t%s\t%s\t\t\t%s\t\t%s\t\t%lu\n", idx, row->name, row->description,
         row->country, row->exportc, row->volume);

  printf(RESET);
}

struct database *DB_Create() {
  struct database *db = malloc(sizeof(struct database));

  db->capacity = 10;
  db->size = 0;

  db->rows = malloc(sizeof(struct row_t *) * db->capacity);

  printf(BOLD INF "База данных успешно создана\n" RESET);

  return db;
}

void DB_Close(struct database *db) {
  for (size_t i = 0; i < db->size; i++) {
    free(db->rows[i]);
  }

  fclose(db->file);

  free(db);

  printf(BOLD INF "База данных успешно закрыта\n" RESET);
}

void DB_Print(struct database *db) {
  if (db->size == 0) {
    printf(FG_RED "База данных пуста\n" RESET);
    return;
  }

  printf("\nNumber\tName\tDescription\t\tCountry\t\tExport\t\tVolume\n");
  for (size_t i = 0; i < db->size; i++) {
    printRow(db->rows[i], 0, i);
  }
  printf("\n");
}

struct database *DB_Open(const char *file) {
  FILE *f = fopen(file, "rb");

  if (f == NULL) {
    printf(BOLD INF "Файл не существует\n" RESET);
    return NULL;
  }

  struct database *db = DB_Create();

  deserialize(f, db);

  rename(".backup.db", file);

  fclose(f);

  db->file = fopen(file, "wb");

  printf(BOLD INF "База данных успешно открыта из файла [%s]\n" RESET, file);

  return db;
}

void DB_InsertRow(struct database *db, const char *name,
                  const char *description, const char *country,
                  const char *exportc, uint64_t volume) {
  if (db->size == db->capacity) {
    db->capacity *= 2;
    db->rows = realloc(db->rows, db->capacity * sizeof(struct row_t *));
  }

  db->rows[db->size++] =
      DB_CreateRow(name, description, country, exportc, volume);
}

uint8_t DB_RemoveRow(struct database *db, uint64_t i) {
  if (i > db->size) {
    return DB_ERROR;
  }
  moveRows(db, i);
  return DB_OK;
}

uint8_t DB_EditRow(struct database *db, uint64_t i, const char *name,
                   const char *description, const char *country,
                   const char *exportc, uint64_t volume) {
  if (i > db->size) {
    return DB_ERROR;
  }

  strncpy(db->rows[i]->name, name, 64);
  strncpy(db->rows[i]->description, description, 64);
  strncpy(db->rows[i]->country, country, 64);
  strncpy(db->rows[i]->exportc, exportc, 64);
  db->rows[i]->volume = volume;

  return DB_OK;
}

uint8_t DB_SearchWithAttribute(struct database *db, uint8_t attr,
                               const void *value) {
  // код - лапша, но работает
  for (size_t i = 0; i < db->size; i++) {
    switch (attr) {
    case DB_ATTR_NAME: {
      const char *str = (char *)value;
      if (!strcmp(db->rows[i]->name, str)) {
        printRow(db->rows[i], 1, i);
      }
      break;
    }

    case DB_ATTR_DESCRIPTION: {
      const char *str = (char *)value;
      if (!strcmp(db->rows[i]->description, str)) {
        printRow(db->rows[i], 1, i);
      }
      break;
    }

    case DB_ATTR_COUNTRY: {
      const char *str = (char *)value;
      if (!strcmp(db->rows[i]->country, str)) {
        printRow(db->rows[i], 1, i);
      }
      break;
    }

    case DB_ATTR_EXPORTC: {
      const char *str = (char *)value;
      if (!strcmp(db->rows[i]->exportc, str)) {
        printRow(db->rows[i], 1, i);
      }
      break;
    }

    case DB_ATTR_VOLUME: {
      uint64_t *a = (uint64_t *)value;
      if (*a == db->rows[i]->volume) {
        printRow(db->rows[i], 1, i);
      }
      break;
    }

    default:
      return DB_ERROR;
    }
  }
  return DB_OK;
}

static int cmpName(const void *a, const void *b) {
  const struct row_t *pa = *(const struct row_t **)a;
  const struct row_t *pb = *(const struct row_t **)b;

  return strcmp(pa->name, pb->name);
}

static int cmpDescription(const void *a, const void *b) {
  const struct row_t *pa = *(const struct row_t **)a;
  const struct row_t *pb = *(const struct row_t **)b;

  return strcmp(pa->description, pb->description);
}

static int cmpCountry(const void *a, const void *b) {
  const struct row_t *pa = *(const struct row_t **)a;
  const struct row_t *pb = *(const struct row_t **)b;

  return strcmp(pa->country, pb->country);
}

static int cmpExportc(const void *a, const void *b) {
  const struct row_t *pa = *(const struct row_t **)a;
  const struct row_t *pb = *(const struct row_t **)b;

  return strcmp(pa->exportc, pb->exportc);
}

static int cmpVolume(const void *a, const void *b) {
  const struct row_t *pa = *(const struct row_t **)a;
  const struct row_t *pb = *(const struct row_t **)b;

  return pa->volume > pb->volume;
}

uint8_t DB_SortWithAttribute(struct database *db, uint8_t attr) {
  switch (attr) {
  case DB_ATTR_NAME:
    qsort(db->rows, db->size, sizeof(struct row_t *), cmpName);
    break;
  case DB_ATTR_DESCRIPTION:
    qsort(db->rows, db->size, sizeof(struct row_t *), cmpDescription);
    break;
  case DB_ATTR_COUNTRY:
    qsort(db->rows, db->size, sizeof(struct row_t *), cmpCountry);
    break;
  case DB_ATTR_EXPORTC:
    qsort(db->rows, db->size, sizeof(struct row_t *), cmpExportc);
    break;
  case DB_ATTR_VOLUME:
    qsort(db->rows, db->size, sizeof(struct row_t *), cmpVolume);
    break;
  default:
    return DB_ERROR;
  }

  printf(BOLD INF "База данных успешно отсортирована\n" RESET);

  return DB_OK;
}

void DB_ResSave(const char *file) { rename(".backup.db", file); }

void DB_Save(struct database *db) {
  serialize(db->file, db);

  printf(BOLD INF "База данных успешно записана в файл\n" RESET);
}

void DB_SetFile(struct database *db, const char *file) {
  db->file = fopen(file, "wb");

  printf(BOLD INF "Файл для сохранения успешно установлен [%s]\n" RESET, file);
}
