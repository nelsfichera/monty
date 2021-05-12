#define DELIMITER " \n\t\a"
#define LIFO 1
#define FIFO 0

typedef struct info_s
{
	char *command;
	char **argument;
	char *function;
	int l_number;
	FILE *fp;
	int type;
} info_t;
extern info_t info;

typedef struct error
{
	int error_code;
	void (*error_type)(void);
} error_t;

void fail_malloc(void);
void fail_usage(void);
void fail_permissions(void);
void command_unknown(void);
void push_error(void);
void pint_error(void);
void pop_error(void);
void swap_error(void);
void add_error(void);
void sub_error(void);
void mul_error(void);
void div_error(void);
void mod_error(void);
void error_handler(int code);

int coordinate(char *filename);
