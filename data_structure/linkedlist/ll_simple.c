#include <stdio.h>
#include <stdlib.h>

typedef struct t_linkedList
{
    int value;
    struct t_linkedList * next;
}t_linkedList;

// Initialization
void LL_v_Init(t_linkedList** t_linkedList, int s_value);

// Create node
t_linkedList *LL_t_NewNode(int s_value, t_linkedList *t_next);

// append
void LL_v_Append(t_linkedList ** pp_linkedList, int s_value);

// prepend
void LL_v_Prepend(t_linkedList ** pp_linkedList, int s_value);

// printList
void LL_v_Print(t_linkedList * p_linkedList);

// Insert new node
void LL_v_Insert(t_linkedList ** pp_linkedList, int s_pos, int s_value);

// Get Lenght
int LL_s_GetLen(t_linkedList * p_linkedList);

// Delete node
void LL_v_Delet(t_linkedList ** pp_linkedList, int s_pos);

// free memory
void LL_v_DeInit(t_linkedList* t_linkedList);


int main()
{
    t_linkedList *my_list = NULL;
    LL_v_Init(&my_list,6);
    LL_v_Append(&my_list,8);
    LL_v_Prepend(&my_list,5);
    LL_v_Insert(&my_list,2,7);
    LL_v_Print(my_list);
    LL_v_Delet(&my_list,0);
    LL_v_Print(my_list);
    LL_v_DeInit(my_list);
    return 0;
}

void LL_v_Init(t_linkedList** t_linkedList, int s_value)
{
    *t_linkedList = LL_t_NewNode(s_value,NULL);
}

t_linkedList *LL_t_NewNode(int s_value, t_linkedList* t_next)
{
    t_linkedList* t_allocate;
    t_allocate = (t_linkedList*) malloc(sizeof(t_linkedList));
    if(t_allocate == NULL)
    {
        printf("Exception 'memory not allocated'\n");
    }
    t_allocate->value = s_value;
    t_allocate->next = t_next;
    return t_allocate;
}

void LL_v_Append(t_linkedList ** pp_linkedList, int s_value)
{
    while ((*pp_linkedList)->next != NULL)
    {
        pp_linkedList = &(*pp_linkedList)->next;
    }
    (*pp_linkedList)->next = LL_t_NewNode(s_value,NULL);
}

void LL_v_Prepend(t_linkedList ** pp_linkedList, int s_value)
{
    (*pp_linkedList) = LL_t_NewNode(s_value,*pp_linkedList);
}

void LL_v_Insert(t_linkedList ** pp_linkedList, int s_pos, int s_value)
{
    if(s_pos == 0)
    {
        LL_v_Prepend(pp_linkedList,s_value);
    }
    else if((s_pos > LL_s_GetLen(*pp_linkedList)) || (pp_linkedList == NULL))
    {
        printf("Exeption error: List has not %d position\n",s_pos);
    }
    else
    {
        int counter = 0;
        while (counter < s_pos-1)
        {
            pp_linkedList = &(*pp_linkedList)->next;
            counter++;
        }
        (*pp_linkedList)->next = LL_t_NewNode(s_value,(*pp_linkedList)->next);     
    }
}

void LL_v_Delet(t_linkedList ** pp_linkedList, int s_pos)
{
    if((s_pos > LL_s_GetLen(*pp_linkedList)-1) || (s_pos < 0) || (pp_linkedList == NULL))
    {
        printf("Exeption error: List has not %d position\n",s_pos);
    }
    else
    {
        int counter = 0;
        t_linkedList* t_prev;
        t_linkedList* t_free;
        if(s_pos == 0)
        {
            t_free = *pp_linkedList;
            *pp_linkedList = (*pp_linkedList)->next;
        }
        else
        {
            while (counter < s_pos)
            {
                t_prev = *pp_linkedList;
                pp_linkedList = &(*pp_linkedList)->next;
                t_free = *pp_linkedList;
                counter++;
            }
            t_prev->next = (*pp_linkedList)->next;
        }
        free(t_free);    
    }
}

int LL_s_GetLen(t_linkedList * p_linkedList)
{
    int counter = 0;
    while (p_linkedList != NULL)
    {
        p_linkedList = p_linkedList->next;
        counter++;
    }
    return counter;
}

void LL_v_DeInit(t_linkedList* pt_linkedList)
{
    t_linkedList* t_freeList;
    while (pt_linkedList != NULL)
    {
        t_freeList = pt_linkedList;
        pt_linkedList = pt_linkedList->next;
        free(t_freeList);
    }    
}

void LL_v_Print(t_linkedList * p_linkedList)
{
    while (p_linkedList != NULL)
    {
        printf("%d \t", p_linkedList->value);
        p_linkedList = p_linkedList->next;
    }
    printf("\n");    
}