//Determine whether it is a complete binary tree

bool isCompleteBTree(bTree* tree){
    queue<bTreeNode*> allnode;
    bTreeNode* temp = tree;
    bool isleaf = false;
    if(tree == NULL){
        return false;
    }
    if(tree->lChild == NULL && tree->rChild == NULL){
        return true;
    }else{
        allnode.enQueue(temp);
        while (!allnode.empty()) {
            if(!isleaf){
                if(temp->lChild == NULL && temp->rChild != NULL){
                    return false;
                }else{
                    allnode.get_front(temp);
                    allnode.deQueue();
                    if(temp->rChild == NULL){
                        isleaf = tree;
                    }
                }
            }else{
                if(temp->lChild != NULL || temp->rChild != NULL){
                    return false;
                }else{
                    allnode.get_front(temp);
                    allnode.deQueue();
                }
            }
        }
        return true;
    }
}
