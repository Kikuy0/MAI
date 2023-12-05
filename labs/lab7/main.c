#include <stdlib.h>
#include <string.h>

#include "db.h"
#include "text.h"

struct database *db = NULL;

/*
 * считывает произвольные данные
 */
#define read(buffer, size, format, ...)                                        \
  do {                                                                         \
    fgets(buffer, size, stdin);                                                \
    size_t len = strlen(buffer);                                               \
    if (len > 0 && buffer[len - 1] == '\n') {                                  \
      buffer[len - 1] = '\0';                                                  \
    }                                                                          \
    sscanf(buffer, format, __VA_ARGS__);                                       \
  } while (0);

/*
 * считывает строку
 */
#define readString(buffer, size)                                               \
  do {                                                                         \
    fgets(buffer, size, stdin);                                                \
    size_t len = strlen(buffer);                                               \
    if (len > 0 && buffer[len - 1] == '\n') {                                  \
      buffer[len - 1] = '\0';                                                  \
    }                                                                          \
  } while (0)

int main() {
  char buf[512]; // буфер для пользовательского ввода

  printf(BOLD "Выберите действие:" RESET "\n1. Создать новую базу данных"
              "\n2. Открыть существующую базу данных"
              "\n---> ");

  int i = 0;

  read(buf, sizeof(buf), "%i", &i);

  char filename[253];

  switch (i) {
  case 1:
    printf(BOLD "Введите имя файла: " RESET);
    read(buf, sizeof(buf), "%s", filename);
    strcat(filename, ".db");
    db = DB_Create();
    DB_SetFile(db, filename);
    break;
  case 2:
    printf(BOLD "Введите имя файла: " RESET);
    read(buf, sizeof(buf), "%s", filename);
    strcat(filename, ".db");
    db = DB_Open(filename);
    break;
  default:
    printf(ERR "Некорректный ввод\n" RESET);
    return 1;
  }

  if (db == NULL) {
    printf(ERR "Произошла ошибка!\n" RESET);
    return 1;
  }

  while (1) {
    int i; // выбор пользователя
    printf(BOLD "Выберите действие:" RESET "\n1. Добавить запись"
                "\n2. Удалить запись"
                "\n3. Найти запись"
                "\n4. Редактировать запись"
                "\n5. Сортировать базу данных"
                "\n6. Вывести содержимое базы данных"
                "\n"
                "\n7. Сохранить данные и выйти" FG_RED "\n8. Выйти без "
                "сохранения" RESET "\n--->"
                " ");
    read(buf, sizeof(buf), "%i", &i);

    switch (i) {
    case 1: {
      char n[64], c[64], a[64], m[64];
      long unsigned int v;

      printf("Введите данные товара:\n");

      printf("Название товара:");
      readString(n, 64);

      printf("Краткое описание товара:");
      readString(c, 64);

      printf("Страна:");
      readString(a, 64);

      printf("Куда экспортируется товар:");
      readString(m, 64);

      printf("Объем поставляемой продукции в рублях:");
      read(buf, sizeof(buf), "%lu", &v);

      DB_InsertRow(db, n, c, a, m, v);

      break;
    }
    case 2: {
      printf("Введите номер строки: ");
      int i;
      read(buf, sizeof(buf), "%i", &i);

      DB_RemoveRow(db, i);

      break;
    }
    case 3: {
      printf("Введите название столбца (название товара, описание, "
             "страна, куда экспортируется, "
             "объем поставляемой продукции в рублях): ");
      char attr[16];
      readString(attr, 16);

      if (strcmp(attr, "название товара") == 0) {
        char value[64];
        printf("Введите название:");
        readString(value, 64);

        DB_SearchWithAttribute(db, DB_ATTR_NAME, value);
      } else if (strcmp(attr, "описание") == 0) {
        char value[64];
        printf("Введите описание товара: ");
        readString(value, 64);

        DB_SearchWithAttribute(db, DB_ATTR_DESCRIPTION, value);
      } else if (strcmp(attr, "страна") == 0) {
        char value[64];
        printf("Введите страну: ");
        readString(value, 64);

        DB_SearchWithAttribute(db, DB_ATTR_COUNTRY, value);
      } else if (strcmp(attr, "куда экспортируется товар") == 0) {
        char value[64];
        printf("Введите куда экспортируется товар: ");
        readString(value, 64);

        DB_SearchWithAttribute(db, DB_ATTR_EXPORTC, value);
      } else if (strcmp(attr, "объем поставляемой продукции в рублях") == 0) {
        unsigned long int g;
        printf("Введите объем поставляемой продукции в рублях: ");
        read(buf, sizeof(buf), "%lu", &g);

        DB_SearchWithAttribute(db, DB_ATTR_VOLUME, &g);
      } else {
        printf(ERR "Повторите ввод!" RESET);
      }
      break;
    }
    case 4: {
      printf("Введите номер строки: ");
      int i;
      read(buf, sizeof(buf), "%i", &i);

      char n[64], c[64], a[64], m[64];
      long unsigned int v;

      printf("Введите данные товара\n");

      printf("Название товара: ");
      readString(n, 64);

      printf("Краткое описание товара: ");
      readString(c, 64);

      printf("Страна: ");
      readString(a, 64);

      printf("Куда экспортируется товар: ");
      readString(m, 64);

      printf("Объем поставленной продукции в рублях: ");
      read(buf, sizeof(buf), "%lu", &v);

      DB_EditRow(db, i, n, c, a, m, v);

      break;
    }
    case 5: {
      printf("Введите название столбца (название товара, описание, "
             "страна, куда экспортируется, "
             "объем поставляемой продукции в рублях): ");
      char attr[16];
      readString(attr, 16);

      if (strcmp(attr, "название товара") == 0) {
        DB_SortWithAttribute(db, DB_ATTR_NAME);
      } else if (strcmp(attr, "описание") == 0) {
        DB_SortWithAttribute(db, DB_ATTR_DESCRIPTION);
      } else if (strcmp(attr, "страна") == 0) {
        DB_SortWithAttribute(db, DB_ATTR_COUNTRY);
      } else if (strcmp(attr, "куда экспортируется") == 0) {
        DB_SortWithAttribute(db, DB_ATTR_EXPORTC);
      } else if (strcmp(attr, "объем поставляемой продукции в рублях") == 0) {
        DB_SortWithAttribute(db, DB_ATTR_VOLUME);
      } else {
        printf(ERR "Повторите ввод!" RESET);
      }
      break;
    }
    case 6: {
      DB_Print(db);
      break;
    }
    case 7: {
      DB_Save(db);
      goto exit;
    }
    case 8: {
      DB_ReSave(filename);
      goto exit;
    }
    default:
      printf(ERR "Некорректный ввод\n" RESET);
      return 1;
    }
  }

exit:
  DB_Close(db);
  return 0;
}
