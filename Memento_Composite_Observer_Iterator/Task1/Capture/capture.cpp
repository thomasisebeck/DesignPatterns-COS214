void capture() 
{
	int *marks = new int[10];
	marks[10] = 0;
    delete marks;
}

int main()
{
	capture();
	return 0;
}
