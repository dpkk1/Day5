//Merge Sort on Doubly Linked List 

Node *split(Node *head){
    Node *fast= head,*slow = head;
    while(fast -> next && fast->next->next){
        slow = slow -> next;
        fast = fast -> next->next;
    }
    Node *temp = slow -> next;
    slow->next = NULL;
    return temp;
}

Node *merge(Node *first, Node *second){
    if(first == NULL)
    return second;
    
    if(second == NULL)
    return first;
    
    if(first -> data < second->data){
        first -> next = merge(first -> next, second);
        first -> next->prev = first;
        first->prev == NULL;
        return first;
    }
    else{
        second -> next = merge(first, second -> next);
        second -> next -> prev = second;
        second -> prev = NULL;
        return second;
    }
}
// Function to merge two DLLs
struct Node *sortDoubly(struct Node *head)
{
    if(head || head->next)
    return head;
    
    Node *second = split(head);
    head = sortDoubly(head);
    second = sortDoubly(second);
    
    return merge(head, second);
}
