#ifndef ENVIRON_H
#define ENVIRON_H

void print_environment();
void print_help();
void print_variable_info(const char* var);
void set_variable(const char* var, const char* value);
void assign_variable(const char* var, const char* value);
void delete_variable(const char* var);
void clear_environment();

#endif
