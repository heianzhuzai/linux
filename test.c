#include <stdio.h>

void test0()
{
	char c;
	char *pc;

	printf("======================\n");
	printf("&c  = %p\n", &c);
	printf("&pc = %p\n", &pc);
	printf("======================\n");

	c = 'A';
	pc = &c;

	printf("c  = %c\n", c);
	printf("pc = %p\n", pc);
	printf("======================\n");

	printf("*pc = %c\n", *pc);	
}

void test1()
{
	int ia;
	int *pi;
	char *pc;

	printf("&ia = %p\n", &ia);
	printf("&pi = %p\n", &pi);
	printf("&pc = %p\n", &pc);

	ia = 0x12345678;
	pi = &ia;
	pc = (char *)&ia;
	printf("ia = 0x%x\n", ia);
	printf("pi = %p\n", pi);
	printf("pc = %p\n", pc);	

	printf("*pi = 0x%x\n", *pi);
	printf("pc = %p\t", pc);	printf("*pc = 0x%x\n", *pc); pc++;
	printf("pc = %p\t", pc);	printf("*pc = 0x%x\n", *pc); pc++;
	printf("pc = %p\t", pc);	printf("*pc = 0x%x\n", *pc); pc++;
	printf("pc = %p\t", pc);	printf("*pc = 0x%x\n", *pc);
}

void test2()
{
	char ca[3] = {'a', 'b', 'c'};
	char *pc;

	printf("======================\n");
	printf("ca  = %p\n", ca);
	printf("&pc = %p\n", &pc);
	printf("======================\n");

	pc = ca;

	printf("pc = %p\n", pc);
	printf("pc = %p\t", pc);	printf("*pc = 0x%x\n", *pc); pc++;
	printf("pc = %p\t", pc);	printf("*pc = 0x%x\n", *pc); pc++;
	printf("pc = %p\t", pc);	printf("*pc = 0x%x\n", *pc);
	printf("======================\n");

}

void test3()
{
	int ia[3] = {0x12345678, 0x12342131, 0x87654321};
	int *pi;

	printf("ia  = %p\n", ia);
	printf("&pi = %p\n", &pi);

	pi = ia;
	printf("pi = %p\n", pi);
	printf("pi = %p\t", pi); printf("*pi = 0x%x\n", *pi); pi = pi + 1;
	printf("pi = %p\t", pi); printf("*pi = 0x%x\n", *pi); pi = pi + 1;
	printf("pi = %p\t", pi); printf("*pi = 0x%x\n", *pi);
}

void test4()
{
	char *pc = "abc";

	printf("&pc = %p\n", &pc);
	printf("pc = %p\n", pc);
	printf("*pc = %c\n", *pc); pc ++;
	printf("*pc = %c\n", *pc);
	printf("pc str=%s\n", pc);

}

int main(int argc, char **argv)
{
	printf("sizeof(char	)=%d\n", sizeof(char ));
	printf("sizeof(int	)=%d\n", sizeof(int ));
	printf("sizeof(char *)=%d\n", sizeof(char *));
	printf("sizeof(char	**)=%d\n", sizeof(char **));
	printf("========================\n");
	// test0();
	// test1();
	// test2();
	// test3();
	test4();

	return 0;
}


