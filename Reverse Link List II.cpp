ListNode* Solution::reverseBetween(ListNode* A, int B, int C) {
    ListNode *c = nullptr, *p = nullptr, *n = nullptr;
    ListNode *t1 = nullptr, *t2 = nullptr;
    int count = 0;

    c = A;
    while(count < B - 1){
        t1 = c;
        c = c->next;
        count++;
    }
    t2 = c;
    while(count < C){
        n = c->next;
        c->next = p;
        p = c;
        c = n;
        count++;
    }
    if(t1)
        t1->next = p;
    else
        A = p;
    t2->next = c;
    return A;
}
