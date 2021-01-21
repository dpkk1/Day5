// Binary Tree to CDLL

void inorder(Node *root,Node *&front,Node *&rear){
    if(root){
        inorder(root->left,front,rear);
        if(front==NULL){
            Node *temp=newNode(root->data);
            front=temp;
            rear=temp;
            front->left=rear;
            rear->right=front;
        }
        else{
            Node *temp=newNode(root->data);
            temp->left=rear;
            temp->right=front;
            front->left=temp;
            rear->right=temp;
            rear=temp;
        }
        inorder(root->right,front,rear);
    }
}
Node *bTreeToCList(Node *root){
    //add code here.
    Node *front=NULL,*rear=NULL;
    inorder(root,front,rear);
    return front;
}
