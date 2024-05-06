/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** The file containing the prototypes of the myshell functions
*/
/**
 * @file myshell.h
 * @brief The file containing the prototypes of the myshell functions
 */

#include "mymemory.h"
#include <termios.h>

#ifndef MYSHELL_H_
    #define MYSHELL_H_

    #define CTRL_KEYPRESS(k) ((k)  & 0x1f)

// TYPEDEFS :

/* The structure of an alias */
typedef struct alias_s {
    char *name; /* The name of the alias */
    char *value; /* The value of the alias */
    int is_concated;
} alias_t;

/* The structure of a variable */
typedef struct variable_s {
    char *name; /* The name of the variable */
    char *value; /* The value of the variable */
} variable_t;

/* The structure of the input command */
typedef struct input_command_s {
    char **args; /* The details of the command */
    char *command; /* The command */
    char *left; /* The left redirection */
    char *right; /* The right redirection */
    int left_type; /* The left redirection type */
    int right_type; /* The right redirection type */
    char *current; /* The current command */
} input_command_t;

/* The structure containing the shell variables */
typedef struct mysh_s {
    int exit_status; /* The exit status of the shell */
    int config_file; /* The fd of the configuration file (.42shrc) */
    char **env; /* The environment variables */
    char **path_list; /* The list of path for exec */
    char **args; /* The arguments of the command */
    char *old_pwd; /* The old pwd */
    char *line; /* The command line */
    int saved_stdin; /* The saved stdin */
    int saved_stdout; /* The saved stdout */
    char **multi_cmds; /* The multiple commands */
    node_t *operators_cmds; /* The operators commands */
    node_t *operators_list; /* The list of operators */
    char **pipe_cmds; /* The pipe commands */
    input_command_t **input_list; /* The input list */
    FILE *fd_history; /* The file descriptor for the history */
    char *history_path; /* The path of the history file */
    node_t *history; /* The history list */
    node_t *alias_list; /* The alias list */
    node_t *variable_list; /* The variable list */
} mysh_t;

/* The structure of a builtin command */
typedef struct builtin_s {
    char *name; /* The name of the builtin command */
    int (*builtin_function)(mysh_t *mysh); /* The functions of the command */
} builtin_t;



// FUNCTIONS PROTOTYPES :

    // Shell functions :

/**
 * @brief Get the shell structure
 * @return <b>mysh_t *</b> The shell structure
 */
mysh_t *get_mysh(void);

/**
 * @brief Initialize the shell structure
 * @param env The environment variables
 * @return <b>mysh_t *</b> The shell structure
 */
mysh_t *init_shell(char **env);

/**
 * @brief The shell loop
 * @param env The environment variables
 * @return <b>void</b>
 */
void shell(char **env);



    // Environment functions

/**
* @brief Set a new environment variable
* @param mysh The shell structure
* @param var The variable name
* @param value The variable value
* @return <b>int</b> <u>0</u> if the command succeed, <u>1</u> otherwise
*/
int set_new_env_var(mysh_t *mysh, char *var, char *value);

/**
 * @brief Get an environment variable
 * @param env The environment
 * @param var The variable to get
 * @return <b>char *</b> The value of the variable
 */
char *get_env_var(char **env, char *var);

/**
 * @brief Replace an environment variable
 * @param env The environment
 * @param name The name of the variable
 * @param value The new value
 * @return <b>void</b>
 */
void replace_env_var(char **env, char *name, char *value);

/**
 * @brief Check if the PATH is set in the environment and set it if not
 * @param mysh The shell structure
 * @return <b>void</b>
 */
void check_path(mysh_t *mysh);

/**
 * @brief Update the path list
 * @param mysh The shell structure
 * @return <b>void</b>
 */
void update_path_list(mysh_t *mysh);



    // Prompt functions

/**
 * @brief Check if the shell is a tty and display the prompt if it is
 * @return <b>void</b>
 */
void check_tty(void);

/**
 * @brief Set the title of the shell
 * @return <b>void</b>
 */
void set_title(void);

/**
 * @brief Display the prompt
 * @return <b>void</b>
 */

void display_prompt(void);

/**
 * @brief Check if we are in a git repository and display the branch
 * @return <b>void</b>
 */
void is_git_repository(void);



    // Commands functions

/**
 * @brief Check if the command exists
 * @param mysh The shell structure
 * @param command The command
 * @return <b>char *</b> The path of the command if it exists,
 * <u>NULL</u> otherwise
 */
char *check_command_exist(mysh_t *mysh, char *command);

/**
 * @brief Execute the command
 * @param mysh The shell structure
 * @param input The input command
 * @return <b>void</b>
 */
void command(mysh_t *mysh, input_command_t *input);




    // Builtins functions

/**
* @brief Get the builtin command
* @param index The index of the command
* @return <b>builtin_t *</b> The builtin command selected
*/
builtin_t *get_builtin_command(int index);

/**
* @brief The about builtin
* @param mysh The shell structure
* @return <b>int</b> <u>0</u> if the command succeed, <u>1</u> otherwise
*/
int exec_about(mysh_t *mysh);

/**
 * @brief The alias builtin
 * @param mysh The shell structure
 * @return <b>int</b> Always <u>0</u>
 */
int exec_alias(mysh_t *mysh);

/**
 * @brief The cd builtin
 * @param mysh The shell structure
 * @return <b>int</b> <u>0</u> if the command succeed, <u>1</u> otherwise
 */
int exec_cd(mysh_t *mysh);

/**
 * @brief The exec command builtin
 * @param mysh The shell structure
 * @return <b>int</b> <u>0</u> or the exit value of the command
 * if the command succeed, <u>1</u> otherwise
 */
int exec_command(mysh_t *mysh);

/**
 * @brief The echo builtin
 * @param mysh The shell structure
 * @return <b>int</b> The exit status of the echo command
 */
int exec_echo(mysh_t *mysh);


/**
 * @brief The else builtin
 * @param mysh The shell structure
 * @return <b>int</b> <u>0</u> if the command succeed, <u>1</u> otherwise
 */
int exec_else(mysh_t *mysh);

/**
 * @brief The else if builtin
 * @param mysh The shell structure
 * @param line_content The command arguments
 * @return <b>int</b> <u>0</u> if the command succeed, <u>1</u> otherwise
 */
int exec_else_if(mysh_t *mysh, char **line_content);

/**
 * @brief The endif builtin
 * @param mysh The shell structure
 * @return <b>int</b> <u>0</u> if the command succeed, <u>1</u> otherwise
 */
int exec_endif(mysh_t *mysh);

/**
 * @brief The env builtin
 * @note If there is no argument, it will display the environment,
 * else it will execute the command with the environment
 * @param mysh The shell structure
 * @return <b>int</b> <u>0</u> if the command succeed, return the exit value
 * of the env command if the command failed
 */
int exec_env(mysh_t *mysh);

/**
 * @brief The exit builtin
 * @param mysh The shell structure
 * @return <b>int</b> <u>0</u> or the exit value if the command succeed,
 * <u>1</u> otherwise
 */
int exec_exit(mysh_t *mysh);

/**
 * @brief The foreach builtin
 * @param mysh The shell structure
 * @return <b>int</b> <u>0</u> if the command succeed, <u>1</u> otherwise
 */
int exec_foreach(mysh_t *mysh);

/**
 * @brief The help builtin
 * @param mysh The shell structure
 * @return <b>int</b> <u>0</u> if the command succeed, <u>1</u> otherwise
 */
int exec_help(mysh_t *mysh);

/**
 * @brief The history builtin
 * @param mysh The shell structure
 * @return <b>int</b> <u>0</u> if the command succeed, <u>1</u> otherwise
 */
int exec_history(mysh_t *mysh);

/**
 * @brief The if builtin
 * @param mysh The shell structure
 * @return <b>int</b> <u>0</u> if the command succeed, <u>1</u> otherwise
 */
int exec_if(mysh_t *mysh);

/**
 * @brief The source builtin
 * @param mysh The shell structure
 * @return <b>int</b> <u>0</u> if the command succeed, <u>1</u> otherwise
 */
int exec_repeat(mysh_t *mysh);

/**
 * @brief The set builtin
 * @param mysh The shell structure
 * @return <b>int</b> <u>0</u> if the command succeed, <u>1</u> otherwise
 */
int exec_set(mysh_t *mysh);

/**
 * @brief The setenv builtin
 * @param mysh The shell structure
 * @return <b>int</b> <u>0</u> if the command succeed, <u>1</u> otherwise
 */
int exec_setenv(mysh_t *mysh);

/**
 * @brief The source builtin
 * @param mysh The shell structure
 * @return <b>int</b> <u>0</u> if the command succeed, <u>1</u> otherwise
 */
int exec_source(mysh_t *mysh);

/**
 * @brief The unalias builtin
 * @param mysh The shell structure
 * @return <b>int</b> <u>0</u> if the command succeed, <u>1</u> otherwise
 */
int exec_unalias(mysh_t *mysh);

/**
 * @brief The unset builtin
 * @param mysh The shell structure
 * @return <b>int</b> <u>0</u> if the command succeed, <u>1</u> otherwise
 */
int exec_unset(mysh_t *mysh);

/**
 * @brief The unsetenv builtin
 * @param mysh The shell structure
 * @return <b>int</b> <u>0</u> if the command succeed, <u>1</u> otherwise
 */
int exec_unsetenv(mysh_t *mysh);

/**
 * @brief The where builtin
 * @param mysh The shell structure
 * @return <b>int</b> <u>0</u> if the command succeed, <u>1</u> otherwise
 */
int exec_where(mysh_t *mysh);

/**
 * @brief The which builtin
 * @param mysh The shell structure
 * @return <b>int</b> <u>0</u> if the command succeed, <u>1</u> otherwise
 */
int exec_which(mysh_t *mysh);



    // Exit functions

/**
* @brief Free the input list
* @param mysh The shell structure
* @return <b>void</b>
*/
void free_input_list(mysh_t *mysh);

/**
* @brief Free the shell structure and exit the shell
* @param mysh The shell structure
* @param status The exit status
* @param message The message to display
* @return <b>void</b>
*/
void my_exit(mysh_t *mysh, unsigned char status, char const *message);



    // Signals functions

/**
* @brief Display the signal returned by executing a command
* @param signal The signal
* @return <b>void</b>
*/
void status_handler(int status);

/**
 * @brief Display the prompt when the SIGINT signal is received
 * @param signal The signal
 * @return <b>void</b>
 */
void print_line(int signal);

/**
 * @brief Display "exit" when the a CRTL+D is received
 * @note I disabled it because it didn't work
 * @param signal The signal
 * @return <b>void</b>
 */
void print_exit(int signal);



    // Tilde functions

/**
 * @brief Transform the tilde in the command line by the home path
 * @param mysh The shell structure
 * @return <b>int</b> <u>0</u> if the replacement is successful,
 * <u>1</u> otherwise
 */
int check_tilde(mysh_t *mysh);



    // Redirections functions

/**
 * @brief Browse the command line to get the redirection path
 * @param line The command line
 * @return <b>char *</b> The redirection path
 */
char *get_redirection_path(char *line);

/**
 * @brief Display the error message when the name is missing
 * @param mysh The shell structure
 * @param commands The command line
 * @return <b>int</b> Always <u>1</u>
 */
int missing_name(mysh_t *mysh, char **commands);



    // Analyse and select functions

/**
* @brief Analyse and execute backticks commands
* @param mysh The shell structure
* @param line The command line
* @return <b>void</b>
*/
void analyse_backticks(mysh_t *mysh, char *line);

/**
* @brief Analyse and execute multiple commands
* @param mysh The shell structure
* @param line The command line
* @return <b>void</b>
*/
void analyse_multi_commands(mysh_t *mysh, char *line);

/**
 * @brief Analyse the operators and execute the commands
 * @param mysh The shell structure
 * @param line The command line
 * @return <b>void</b>
 */
void analyse_operators(mysh_t *mysh, char *line);

/**
 * @brief Analyse and execute the pipes
 * @param mysh The shell structure
 * @param line The command line
 * @return <b>void</b>
 */
void analyse_pipes(mysh_t *mysh, char *line);

/**
 * @brief Execute the right redirection
 * @param mysh The shell structure
 * @param input The input command
 * @return <b>void</b>
 */
void exec_right_redirection(mysh_t *mysh, input_command_t *input);

/**
 * @brief Execute the left double redirection
 * @param mysh The shell structure
 * @param input The input command
 * @return <b>void</b>
 */
void exec_left_double_redirection(mysh_t *mysh, input_command_t *input);

/**
 * @brief Execute the left simple redirection
 * @param mysh The shell structure
 * @param input The input command
 * @return <b>void</b>
 */
void exec_left_simple_redirection(mysh_t *mysh, input_command_t *input);

/**
 * @brief Analyse and execute the good redirection
 * @param mysh The shell structure
 * @param input The input command
 * @return <b>void</b>
 */
void select_redirections(mysh_t *mysh, input_command_t *input);

/**
 * @brief Analyse the parentheses
 * @param mysh The shell structure
 * @param input The input command structure
 * @return <b>void</b>
 */
void analyse_parentheses(mysh_t *mysh, input_command_t *input);



    // Input command functions

/**
 * @brief Get the input command
 * @param command The command
 * @return <b>input_command_t *</b> The input command
 */
input_command_t *get_input_command(char *command);

/**
 * @brief Display the input command
 * @note The function is used for debugging
 * @param input_command The input command
 * @return <b>void</b>
 */
void display_input_command(input_command_t *input_command);



    // Parsing functions

/**
* @brief Check if a character is inhibited
* @param str The string to check
* @param index The index of the character
* @return <b>char</b> The inhibitor if the character is inhibited,
* <u>0</u> otherwise
*/
char char_is_inhibited(char *str, int index);

/**
 * @brief Check if a char is paranthesed
 * @param str The string
 * @param index The index
 * @return <b>int</b> <u>1</u> if the char is paranthesed, <u>0</u> otherwise
 */
int char_is_paranthesed(char *str, int index);

/**
 * @brief Check if a char is protected
 * @param str The string
 * @param index The index
 * @return <b>int</b> <u>1</u> if the char is protected, <u>0</u> otherwise
 */
int char_is_protected(char *str, int index);

/**
 * @brief Find a valid string in a string
 * depending on inhibitors and parentheses
 * @note It's an improved version of my_strstr
 * @param str The string to check
 * @param to_find The string to find
 * @return <b>char *</b> The address of the string if it's valid,
 * <u>NULL</u> otherwise
 */
char *find_valid_str(char *str, char const *to_find);



    // Inhibitors functions

/**
 * @brief Transform a string into an array of words with inhibitors
 * @param str The string to transform
 * @return <b>char **</b> The array of words
 */
char **str_to_array_inhibitors(char *str);

/**
 * @brief Transform a string into an array of words delimited by a string
 * with inhibitors
 * @param str The string to transform
 * @param separator The separator
 * @return <b>char **</b> The array of words
 */
char **array_string(char const *str, char const *separator);

/**
 * @brief Transform a string into an array of words delimited by separators
 * with inhibitors
 * @param str The string to transform
 * @param separator The separator
 * @return <b>char **</b> The array of words
 */
char **array_separators(char const *str, char const *separator);



    // Globbing functions

/**
 * @brief Analyse if arguments are globbing
 * @param args The arguments
 * @return <b>New Args</b>
 */
char **globbing(char **args);



    // Line editing functions

/**
* @brief Get the line from the stream
* @param line The line to store the command
* @param stream The stream
* @return <b>int</b> <u>0</u> if success, <u>-1</u> if error
*/
int my_getline(char **line, FILE *stream);

/**
 * @brief Save terminal attributes
 * @param saved_termios The termios structure to save the terminal attributes
 * @return <b>void</b>
 */
void save_termios(struct termios *saved_termios);

/**
 * @brief Restore terminal attributes
 * @param saved_termios The termios structure to restore the
 * terminal attributes
 * @return <b>void</b>
 */
void restore_termios(struct termios *saved_termios);

/**
 * @brief Disable the buffer
 * @return <b>int</b> <u>0</u> if the buffer is disabled, <u>-1</u> otherwise
 */
int disable_buffer(void);

/**
 * @brief Move the cursor
 * @param stream The stream
 * @param pos The position of the cursor
 * @param str The string
 * @param str2 The second string
 * @return <b>void</b>
 */
void move_cursor(int *pos, char *str, char **str2);

/**
 * @brief Handle the control key
 * @param c The character
 * @param pos The position of the cursor
 * @param str The string
 * @param str2 The second string
 * @return <b>int</b> <u>0</u> if success, <u>1</u> otherwise
 */
int ctrl(char c, int *pos, char *str, char **str2);

/**
 * @brief Handle the backspace key
 * @param c The character
 * @param pos The position of the cursor
 * @param str The string
 * @param str2 The second string
 * @return <b>int</b> <u>0</u> if success, <u>1</u> otherwise
 */
int backspace(char c, int *pos, char *str, char **str2);



    // .42shrc functions

/**
* @brief Execute a bash file
* @param mysh The shell structure
* @param file The file descriptor
* @param size The size of the file
* @return <b>int</b> The exit status of last command if the command succeed,
* <u>1</u> otherwise
*/
int execute_bash_file(mysh_t *mysh, int file, size_t size);

/**
 * @brief Check if the 42shrc file exists in the home directory
 * and create it if it doesn't
 * @param mysh The shell structure
 * @return <b>void</b>
 */
void check_42shrc(mysh_t *mysh);



    // History functions

/**
 * @brief Create the history file
 * @param mysh The shell structure
 * @return <b>void</b>
 */
void create_history(mysh_t *mysh);

/**
* @brief Set the command in the history
* @param mysh The shell structure
* @param line The line to set in the history
* @return <b>void</b>
*/
void set_command_in_history(mysh_t *mysh, char *line);

/**
 * @brief Replace '!' by history event
 * @param args The command arguments
 * @return <b>char **</b> The new command arguments
 */
char **replace_history(char **args);



    // Alias functions

/**
 * @brief Replace the alias if it already exists
 * @param mysh The shell structure
 * @return <b>char **</b> args to be interpreted and executed
*/
char **replace_alias_in_line(char **args, node_t **alias_list);

/**
 * @brief sort the alias list
 * @param begin The alias list
 * @param cmp The compare function
 * @return <b>void</b>
*/
void my_sort_alias(node_t **begin, int (*cmp)());



    // Variables functions

/**
* @brief Check if the variable is valid
* @param variable The variable
* @param builtin The builtin who called the function
* @return <b>int</b> <u>1</u> if the variable is valid, <u>0</u> otherwise
*/
int is_valid_variable(char *variable, char *builtin);

/**
 * @brief Add a variable to the list
 * @param mysh The shell structure
 * @param name The name of the variable
 * @param value The value of the variable
 * @return <b>void</b>
 */
void add_variable(mysh_t *mysh, char *name, char *value);

/**
 * @brief Get the value of a variable
 * @param mysh The shell structure
 * @param name The name of the variable
 * @return <b>char *</b> The value of the variable
 */
char *get_variable_value(mysh_t *mysh, char *name);

/**
 * @brief Replace the variables in the command arguments
 * @param mysh The shell structure
 * @return <b>int/b> The new command arguments
 */
int replace_variables(mysh_t *mysh);



    // Scripting functions

/**
* @brief Remove the comments from a line
* @param line The line
* @return <b>void</b>
*/
void remove_comments(char *line);

/**
 * @brief Read a file and execute the commands in it
 * @param file The file path
 * @return <b>int</b> <u>0</u> if success, <u>1</u> if an error occurred
 */
int read_file_in_stdin(char *file);



    // Condition functions

/**
* @brief Get the condition result from a string
* @param str The string to calculate
* @return <b>int</b> The result of the condition : 0 if false, 1 if true
* and -1 if an error occurred
*/
int get_condition(char *str);

#endif /* MYSHELL_H_ */
