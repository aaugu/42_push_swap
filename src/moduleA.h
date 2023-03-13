#ifdef

typedef struct s_tower
{
	int *stack;
	int size;
} t_tower;

int tower_init(t_tower* t, int size, int* list);
void tower_swap(t_tower* t);
void tower_push(t_tower* source, t_tower* dest, char* op);


tower_push(a, b, "pa")
tower_push(b, a, "pb")
