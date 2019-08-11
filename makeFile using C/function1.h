typedef struct list
{
int data;
struct list *next,*prev;
}list;

void createcl(int n);
void disp(list *head);
void swapls(list *head);
