#ifndef TYPE_H
# define TYPE_H

typedef enum e_bool {
	FALSE = -1,
	TRUE = 0
}			t_bool;

typedef enum e_dir {
	LEFT,
	RIGHT
}			t_dir;

typedef enum e_msg {
	PICK,
	EAT,
	SLEEP,
	THINK,
	DIE
}			t_msg;

#endif
