/**
* _isupper - checks for uppercase character.
* @c int to be checked
* Return: 1 if c is lowercase, 0 otherwise
**/

int _isupper(int c)
{
	if ( c >= 'A' && c <= 'Z')
	{
		return (0);
	}
	else
		return (1);
}
