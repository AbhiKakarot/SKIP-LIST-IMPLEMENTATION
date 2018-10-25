#include<stdio.h>
#include<ctype.h>
#include<string.h>

int check_for_correctness(char s[])
{
int l = strlen(s);
for(int i=0;i<l;i++)
{

	if((isdigit(s[i]))||(s[i]=='+')||(s[i]=='-')||(s[i]=='*')||(s[i]=='/')||(s[i]=='^')||(s[i]=='(')||(s[i]==')'))
			return 0;
	else{printf("Illegal character [%c]",s[i]);
		return 1; }
}

}

int convert(char s[])
{

char main_stack[50];
char operator_stack[25];
int ms=0,os=0;
char push='n';
for(int i=0;s[i]!='\0';i++)
{
	if(isdigit(s[i]))
	{
		main_stack[ms++] = s[i];
		push = 'y';
	}
	else
	{
		operator_stack[os++] = s[i];
		push = 'n';
	}


	if(push == 'y')
	{
	if(s[i]=='^')
	{
		operator_stack[os] = '\0';
		main_stack[ms++] = operator_stack[--os];
	}
	else if(s[i]==')')
	{
		while(operator_stack[--os] != '(')
		{
			operator_stack[os+1] = '\0';
			main_stack[ms++] = operator_stack[os];
		}
		operator_stack[os] = '\0';
	}
	else if(((operator_stack[os-1]=='*')||(operator_stack[os-1]=='/'))&&((operator_stack[os-2]=='+')||(operator_stack[os-2]=='-')))
	{
		operator_stack[os] = '\0';
		main_stack[ms++] = operator_stack[--os];
	}
	}

}


while(os>=0)
{
main_stack[ms++] = operator_stack[--os];
}


int i=0;
while(main_stack[i]!='\0')
{
printf("%c",main_stack[i]);
i++;
}

return 0;
}



int main()
{

char s[50];
char ch;
int i=0;
printf("Enter an infix expression \n");
while( (ch = getchar()) != '\n' &&  i<50) {
    s[i] = ch;
    ++i;
}
check_for_correctness(s);

convert(s);

return 0;
}
