class Leetcode_25.Reverse_Nodes_in_k-Group {
    public class ListNode {
        int val;
        ListNode next;

        ListNode(int val){
            this.val = val;
        }
    }
    ListNode oh = null;
    ListNode ot = null;
    ListNode th = null;
    ListNode tt = null;
    
    public void addFirstNode(ListNode node){
        
        if(th == null){
            th = node;
            tt = node;
        }
        else{
            node.next = th;
            th = node;
        }
        
    }
    public ListNode reverseBetween(ListNode head, int m, int n) {
        
        if(head == null || m == n)
            return head;
        
        ListNode curr = head;
        int idx = 1;
        ListNode prev = head;
        while(curr != null){
            
            while(idx >= m && idx <= n){
                ListNode fwd = curr.next;
                addFirstNode(curr);
                curr = fwd;
                idx++;
            }
            
            if(th == null){
                ot = curr;
            }
            else{
                if(ot != null)
                    ot.next = th;
                else
                    prev = th;
                ot = tt;
                ot.next = curr;
                break;
            }
            curr = curr.next;
            idx++;
        }
        return prev;
        
    }
}