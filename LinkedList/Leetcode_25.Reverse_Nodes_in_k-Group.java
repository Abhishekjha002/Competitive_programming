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
    public int lengthLL(ListNode head){
        ListNode curr = head;
        int length = 0;
        while(curr != null){
            length++;
            curr = curr.next;
        }
        return length;
    }
    public ListNode reverseKGroup(ListNode head, int k) {
        
        if (head == null || head.next == null || k == 0 || k == 1)
            return head;

        // int len = len(head);
        
        int len = lengthLL(head);
        
        if(len < k){
            return head;
        }
        
        ListNode curr = head;
        while(curr != null){
            
            int tk = k;
            
            while(tk-->0){
                
                ListNode fwd = curr.next;
                curr.next = null;
                
                addFirstNode(curr);
                curr = fwd;
                
            }
            
            len -= k;
            
            if(ot == null){
                oh = th;
                ot = tt;
            }
            else{
                ot.next = th;
                ot = tt;
            }
            
            th = null;
            tt = null;
            
            if(len < k){
                ot.next = curr;
                break;
            }
    
    
        }
        
        return oh;    
        
    }
}