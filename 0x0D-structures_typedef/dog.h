/**
* Define a new type struct dog with name, age, owner
**/
struct dog
{
	char *name;
	float age;
	char *owner;
};

/* Define a new type dog_t as a new name for the type struct dog. */
typedef struct dog dog_t;
