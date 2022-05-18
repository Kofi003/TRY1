#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define BUFFER_SIZE 256
#define ENV_SEPARATOR "="
#define ESCAPE_SEPARATOR "#"
#define PATH_SEPARATOR ":"
#define COMMAND_SEPARATOR ";\n"
#define SEPARATORS " \n"
#define PROMPT "$ "

extern char **environ;

/**
 * struct environment_s - environment variable
 *
 * @name: environment name
 * @value: environment value
 * @next: points to the next node
 */
typedef struct environment_s
{
	char *name;   /* ex: PATH */
	char *value;  /* ex: /bin:/usr/bin */
	char *global; /* PATH=/bin:/usr/bin */
	struct environment_s *next;
} environment_t;

/**
 * struct appData_s - data variable
 *
 * @arguments: argument's array
 * @buffer: buffer
 * @command: command name
 */
typedef struct appData_s
{
	char **arguments;
	char *buffer;
	char *commandName;
	char **commandList;
	char **history;
	char *programName;
	environment_t *env;
} appData_t;

/**
 * struct errorMessage_s - An structure for each error message
 *
 * @ecode: error code
 * @msg: pointer to error message
 * @size: error message length.
 */
typedef struct errorMessage_s
{
	int code;
	char *msg;
} errorMessage_t;

/**
 * struct customCommand_s - struct conversion to function
 *
 * @command: flag string
 * @func: pointer to func
 */
typedef struct customCommand_s
{
	char *commandName;
	void (*func)(appData_t *);
} customCommand_t;

environment_t *A_addEnvNodeEnd(
	environment_t **prmHeadNode,
	char *prmGlobal
);
void A_addWord(char *prmWord, int *prmIndex, char **prmArray);
int A_atoi(char *prmString);
void *C_calloc(unsigned int prmNumber, unsigned int prmSize);
void C_cdHelp(void);
void C_changeDirectory(appData_t *prmData);
void C_changeToAnyDirectory(appData_t *prmData, char *prmCurrentDirectory);
void C_changeToHomeDirectory(appData_t *prmData, char *prmCurrentDirectory);
void C_changeToPreviousDirectory(appData_t *prmData, char *prmCurrentDirectory);
int C_checkEndCharacter(char *prmString);
int C_checkEscapeSeparators(char prmChar, char *prmEscapeSeparators);
int C_checkSeparators(char prmChar, char *prmSeparators);
char *C_cleanString(char *prmString);
environment_t *C_createEnvNode(char *prmGlobal);
void C_ctrlC(int prmSignal);
void D_defaultHelp(char *prmCommand);
int D_deleteEnvNode(environment_t *prmHead, char *prmName);
void _prompt(void);
void E_env(appData_t *prmData);
void E_envHelp(void);
void E_errorHandler(appData_t *prmData, int messageCode);
void E_errorHandler(appData_t *prmData);
void E_exitStatus(appData_t *prmData);
void E_exitHelp(void);
void F_freeAppData(appData_t *prmData);
void F_freeCharDoublePointer(char **prmPtr);
void F_freeEnvList(environment_t *prmHeadNode);
char *G_generateAbsolutePath(char *prmPath, char *prmCommandName);
char *G_generateEnvGlobal(char *prmName, char *prmValue);
void (*G_getCustomFunction(char *prmCommand))(appData_t *);
environment_t *G_getenv(environment_t *prmEnviron, char *prmName);
char *G_getenvname(char *prmVariable);
char *G_getenvvalue(char *prmVariable);
int G_getenvIndex(environment_t *prmHead, char *prmName);
environment_t *G_getenvNodeAtIndex(
	environment_t *prmHead,
	unsigned int prmIndex
);
environment_t *G_getLastEnvNode(environment_t *prmHeadNode);
void G_getline(appData_t *prmData);
char *G_getword(char *prmGlobal, int prmOffset, int prmSize);
void H_help(appData_t *prmData);
void H_helpHelp(void);
int I_inArray(char prmChar, char *prmArray);
appData_t *I_initData(char **prmArgv);
void I_initEnvData(appData_t *prmData);
int I_isdigit(char prmChar);
int I_isNumber(char *s);
char *I_itoa(int prmNumber);
int L_listEnvLen(environment_t *prmHead);
char *M_memcpy(char *prmDest, char *prmSrc, unsigned int prmLimit);
char *M_memset(char *prmString, char prmCharacter, unsigned int prmLimit);
int N_nbrLen(int prmNumber);
char **P_parsingPathEnvironment(appData_t *prmData);
void P_printenv(environment_t *prmEnviron);
int _putchar(char prmChar);
int P_puts(char *prmStr);
void *R_realloc(void *prmPtr, unsigned int prmOldSize, unsigned int prmNewSize);
void S_setenv(environment_t *prmEnviron, char *prmName, char *prmValue, int prmOverwrite);
void SS_setenvHelp(void);
void SS_setenvironment(appData_t *prmData);
char *S_strcat(char *prmDest, char *prmSrc);
int S_strcmp(char *prmString1, char *prmString2);
char *S_strcpy(char *prmDest, char *prmSrc);
char *S_strconcat(char *prmString1, char *prmString2);
char *S_strncpy(char *prmDest, char *prmSrc, int prmLimit);
unsigned int S_strcspn(char *prmString, char *prmDeny);
char *S_strdup(char *prmString);
int S_strlen(char *prmStr);
char *S_strstr(char *prmHaystack, char *prmNeedle, int prmBegin);
char **S_strtow(char *prmString, char *prmSeparators, char *prmEscapeSeparators);
void U_unsetenv(appData_t *prmData, char *prmName);
void UU_unsetenvHelp(void);
void UU_unsetenvironment(appData_t *prmData);
char *W_which(appData_t *prmData);
int WW_wordNumber(char *prmString, char *prmSeparators);

#endif
