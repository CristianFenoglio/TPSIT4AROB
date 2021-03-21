

bool is_empty(struct queque_node *punt){
    return punt==NULL
}

void enqueue(struct queue_node **head, struct queue_node **tail, struct queue_node element){
    if(is_empty(*head))
        *head=element;
    else
    {
        (tail)->next=element;
    }
    *tail=element;
    element->next=NULL;
}


struct queue_node*  dequeue(struct queue_node **head, struct queue_node **tail){
    struct queue_node *ret=*head;
    if(is_empty(*head))
        return NULL;
    else
        *head=ret->next;
    if(*head==NULL)
        *tail=NULL;
    return ret;
}