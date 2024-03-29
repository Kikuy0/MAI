#ifndef DB_H
#define DB_H

#include <stdint.h>
#include <stdio.h>

#include "tier.h"

#define DB_OK 0
#define DB_ERROR 1

#define DB_ATTR_NAME 1 << 0
#define DB_ATTR_DESCRIPTION 1 << 1
#define DB_ATTR_COUNTRY 1 << 2
#define DB_ATTR_EXPORTC 1 << 3
#define DB_ATTR_VOLUME 1 << 4

struct database {
  /*
   * работает как std::vector
   * сам расширяется и реаллоцирует память при надобности
   *
   * rows аллоцируется malloc
   */
  uint64_t capacity; // вместительность
  uint64_t size;     // текущее количество элементов

  struct row_t **rows;

  FILE *file;
};

/*
 * создает пустую базу данных
 * резервирует res мест для строк базы
 */
struct database *DataBase_Create();

/*
 * освобождает место, выделенное для db,
 * уничтожает все записи
 */
void DataBase_Close(struct database *db);

/*
 * выводит полное содержимое базы данных
 */
void DataBase_Print(struct database *db);

/*
 * открывает существующую базу данных из файла
 */
struct database *DataBase_Open(const char *file);

/*
 * создает запись в базе данных
 */
void DataBase_InsertRow(struct database *db, const char *name,
                        const char *description, const char *country,
                        const char *exportC, uint64_t volume);

/*
 * удаляет i-ю строку
 * возвращаемые значения: DB_OK, RB_ERROR
 */
uint8_t DataBase_RemoveRow(struct database *db, uint64_t i);

/*
 * редактирует i строку
 * возможные атрибуты: DB_ATTR_*
 * возвращаемые значения: DB_OK, DB_ERROR
 */
uint8_t DataBase_EditRow(struct database *db, uint64_t i, const char *name,
                         const char *description, const char *country,
                         const char *exportC, uint64_t volume);

/*
 * выводит в консоль результат поиска
 * возможные значения mode: DB_SEARCH_MODE_*
 * возвращаемые значения: DB_OK, DB_ERROR
 */
uint8_t DataBase_SearchWithAttribute(struct database *db, uint8_t attr,
                                     const void *value);

/*
 * сортирует базу данных по заданному атрибуту DB_ATTR_*
 * НЕ ВЫВОДИТ РЕЗУЛЬТАТ
 * возвращаемые значения: DB_OK, DB_ERROR
 */
uint8_t DataBase_SortWithAttribute(struct database *db, uint8_t attr);

void DataBase_ReSave(const char *file);

/*
 * сохраняет текущее состояние базы данных и записывает его в файл
 */
void DataBase_Save(struct database *db);
/*
 * устанавливает файл для сохранения
 */
void DataBase_SetFile(struct database *db, const char *file);
#endif
