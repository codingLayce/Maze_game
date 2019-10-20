#ifndef UTILS_H_GUARD
#define UTILS_H_GUARD

/* Copy the string sender into the receiver.
 * @param receiver String to fill with the sender
 * @param sender to copy into the receiver
 * @param nb_char number of characters to copy (length of sender or a part)
 */
void copy_string (char *receiver, const char *sender, size_t nb_char);

/* Reads an int entered by the user.
 * @return the int entered by the user
 */
int read_int();

/* Reads a char entered by the user.
 * @return the char entered by the user.
 */
char read_char();

/* Clears the buffer by reading all the inputs until the end.
 */
void clear_buffer();

/* Reads only one key and returns.
 * @return the key pressed (ASCII char)
 */
char read_key();

#endif
