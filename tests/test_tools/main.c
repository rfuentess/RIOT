/*
 * Copyright (C) 2019 Freie Universität Berlin
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @file
 * @brief       Specific shell implementation for testing the testing tools.
 *
 * @author      Gaëtan Harter <gaetan.harter@fu-berlin.de>
 *
 */

#include <stdio.h>

#include "shell_commands.h"
#include "shell.h"

#if !defined(SHELL_NO_ECHO) || !defined(SHELL_NO_PROMPT)
#error This test assumes no shell echo or shell prompt
#endif


/**
 * @brief true - do nothing, successfully
 *
 * true [ignored command line arguments]
 *
 * Description taken from `man true` in coreutils.
 *
 * @param[in] argc  Number of arguments
 * @param[in] argv  Array of arguments
 *
 * @return  0
 *
 */
static int cmd_true(int argc, char **argv)
{
    (void)argc;
    (void)argv;
    return 0;
}


/**
 * @brief shellping, replies shellpong
 *
 * Test if the shell is ready to take commands
 *
 * @param[in] argc  Number of arguments
 * @param[in] argv  Array of arguments
 *
 * @return  0
 *
 */
static int cmd_shellping(int argc, char **argv)
{
    (void)argc;
    (void)argv;
    puts("shellpong");
    return 0;
}


static const shell_command_t shell_commands[] = {
    { "shellping", "Just print 'shellpong'", cmd_shellping },
    { "true", "do nothing, successfully", cmd_true },
    { NULL, NULL, NULL }
};

int main(void)
{
    puts("Running 'tests_tools' application");

    char line_buf[SHELL_DEFAULT_BUFSIZE];
    shell_run(shell_commands, line_buf, SHELL_DEFAULT_BUFSIZE);

    return 0;
}
