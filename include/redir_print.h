#ifndef FL2K_REDIR_PRINT_H
#define FL2K_REDIR_PRINT_H

#define LOG_TRG_STDERR 1
#define LOG_TRG_STDOUT 2

#include <stdio.h>
#include "osmo-fl2k_export.h"

typedef void(*std_print_wrapper)(char target, char *text, void *ctx);

/* Configure a redirection for data printed to stdout or stderr
 * \param cb callback function to receive printed data
 * \param ctx user specific context to pass via the callback function
 * \return 0 on success
 */
FL2K_API int fl2k_print_redirection(std_print_wrapper cb, void *ctx);

/*
 * fprintf wrapper. If there's a registered redirection, it prints to a buffer
 * and sends it to the callback.
 * otherwise normal output to specified stream.
 */
int fl2k_fprintf(FILE *stream, const char* aFormat, ...);

#endif // FL2K_REDIR_PRINT_H
