#ifndef __table_h
#define __table_h

#include <stdint.h>

#define COLUMN_USERNAME_SIZE 32
#define COLUMN_EMAIL_SIZE 255
#define size_of_attribute(Struct, Attribute) sizeof(((Struct*)0)->Attribute)

#define TABLE_MAX_PAGES 100

typedef struct Row {
    uint32_t id;
    char username[COLUMN_USERNAME_SIZE];
    char email[COLUMN_EMAIL_SIZE];
} Row;

typedef struct Table {
    uint32_t num_rows;
    void* pages[TABLE_MAX_PAGES];
} Table;


void serialize_row(Row* source, void* destination);
void deserialize_row(void* source, Row* destination);

Table* new_table();
void free_table(Table* table);

void print_row(Row* r);
void* row_slot(Table* t, uint32_t n);

#endif