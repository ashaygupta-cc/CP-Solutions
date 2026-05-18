class MinStack{
public:
    struct ListNode{
        int val;
        int min;
        ListNode* next;
        
    ListNode(int val,int curmin){
        this->val = val;
        this->min = curmin;
        this->next = NULL;
    }

    };
    
    ListNode* head;

    MinStack(){
        head = NULL;
    }
    
    void push(int val){
        if(head == NULL){
            head = new ListNode(val,val);
        } 
        else{
            int curmin = min(val,head->min);
            ListNode* newNode = new ListNode(val,curmin);
            newNode->next = head;
            head = newNode;
        }
    }
    
    void pop(){
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
    
    int top(){
        if (head == NULL) return NULL;
        return head->val;
    }
    
    int getMin() {
        if (head == NULL) return NULL;
     return head->min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */