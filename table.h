#ifndef __table_h
#define __table_h

#include <stdint.h>
#include <stdbool.h>

#define COLUMN_USERNAME_SIZE 32
#define COLUMN_EMAIL_SIZE 255
#define size_of_attribute(Struct, Attribute) sizeof(((Struct*)0)->Attribute)

#define TABLE_MAX_PAGES 100

extern const uint32_t LEAF_NODE_MAX_CELLS;

typedef struct Row {
    uint32_t id;
    char username[COLUMN_USERNAME_SIZE + 1];
    char email[COLUMN_EMAIL_SIZE + 1];
} Row;

typedef struct Pager {
    int file_descriptor;
    uint32_t file_length;
    uint32_t num_pages;
    void* pages[TABLE_MAX_PAGES];
} Pager;

typedef struct Table {
    uint32_t root_page_num; //? -> 一共存了几个 page
    Pager* pager;
} Table;

typedef struct Cursor {
    Table* table;
    uint32_t page_num; // 第几个 page
    uint32_t cell_num; // 第几个 cell
    bool end_of_table;
} Cursor;


void serialize_row(Row* source, void* destination);
void deserialize_row(void* source, Row* destination);

Table* db_open(const char* filename);
void db_close(Table* table);

Pager* pager_open(const char* filename);
void* get_page(Pager* pager, uint32_t page_num);
void pager_flush(Pager* pager, uint32_t page_num);

void print_row(Row* r);

Cursor* table_start(Table* table);
Cursor* table_end(Table* table);

void* cursor_value(Cursor* cursor);
void cursor_advance(Cursor* cursor);

// 获取 node 中存了多少 cell
uint32_t* leaf_node_num_cells(void* node); 
// 获取 node 中的第几个 cell
void* leaf_node_cell(void* node, uint32_t cell_num);
// 获取 node 中的第几个 key
uint32_t* leaf_node_key(void* node, uint32_t cell_num);
// 获取 node 中的第几个 value
void* leaf_node_value(void* node, uint32_t cell_num);

void initialize_leaf_node(void* node);

void leaf_node_insert(Cursor* cursor, uint32_t key, Row* value);

void print_constants();
void print_leaf_node(void* node);

#endif