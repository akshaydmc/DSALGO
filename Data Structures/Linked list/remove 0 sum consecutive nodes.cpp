class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        unordered_map<int,ListNode*>m;
        ListNode *x=new ListNode(0);
        x->next=head;
        head=x;
        ListNode*t=head;
        m[0]=x;
        int sum=0;
        int sum1=0;
        while(t!=NULL)
        {    
            sum +=t->val;
            auto itr=m.find(sum);
            
            if(itr!=m.end())
            {  ListNode*g=itr->second;
               ListNode *h=itr->second;
             
               sum1=sum;
                while(g!=t)
                {  
                    g=g->next;
                    sum1+=g->val;
                   // m.erase(sum1);
                    if(g!=t)
                        m.erase(sum1);
                
                }
                h->next=t->next;
            }
            else
            {
                m[sum]=t;
            }
             t=t->next;
        }
       
        return head->next;
    }
};
