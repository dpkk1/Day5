//Reorder List 

void reverse(Node **head){
    Node *prev = NULL, *curr = *head, *next;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
 
    *head = prev;
}


void reorderList(Node* head) {
   Node *slow = head, *fast = head;
   while(fast -> next && fast -> next -> next){
       slow = slow -> next;
       fast = fast -> next -> next;
   }
   Node *head1 = head;
   Node *head2 = slow -> next;
   slow -> next = NULL;
   reverse(&head2);
   
   head = new Node(0); 
 
    Node* curr = head;
    while (head1 || head2) {
        if (head1) {
            curr->next = head1;
            curr = curr->next;
            head1 = head1->next;
        }
 
        if (head2) {
            curr->next = head2;
            curr = curr->next;
            head2 = head2->next;
        }
    }
 
    head = (head)->next;
}
