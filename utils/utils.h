#ifndef UTILS_H_GUARD
#define UTILS_H_GUARD

/* Function that copy the string sender in the receiver string.
 */
void copy_string (char *receiver, const char *sender, size_t nb_char);

/* Function that wait the user to enter an int.
 * Returns -1 if an error occured or if the user enter something else than a int.
 */
int read_int();

char read_char();

/* Function that clear the buffer by reading all the inputs until the end.
 */
void clear_buffer();

char read_key();

#endif
