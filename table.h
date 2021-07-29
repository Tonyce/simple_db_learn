#ifndef __table_h
#define __table_h

#include <stdint.h>

#define COLUMN_USERNAME_SIZE 32
#define COLUMN_EMAIL_SIZE 255
#define size_of_attribute(Struct, Attribute) sizeof(((Struct*)0)->Attribute)

#define TABLE_MAX_PAGES 100

typedef struct Row {
    uint32_t id;
    char username[COLUMN_USERNAME_SIZE + 1];
    char email[COLUMN_EMAIL_SIZE + 1];
} Row;

typedef struct Pager {
    int file_descriptor;
    uint32_t file_length;
    void* pages[TABLE_MAX_PAGES];
} Pager;

typedef struct Table {
    uint32_t num_rows;
    Pager* pager;
} Table;


void serialize_row(Row* source, void* destination);
void deserialize_row(void* source, Row* destination);

Table* db_open(const char* filename);
void db_close(Table* table);

Pager* pager_open(const char* filename);
void* get_page(Pager* pager, uint32_t page_num);
void pager_flush(Pager* pager, uint32_t page_num, uint32_t size);

void print_row(Row* r);
void* row_slot(Table* t, uint32_t n);

#endif