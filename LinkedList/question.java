public class question{

    public class ListNode {
        int val;
        ListNode next;

        ListNode(int val){
            this.val = val;
        }
    }

    //LeetCode 876 : getMid
    public ListNode middleNode(ListNode head) {
        if(head == null || head.next == null)
            return head;
        ListNode slow = head;
        ListNode fast = head;   
        
        while(fast != null && fast.next != null){
            slow = slow.next;
            fast = fast.next.next;
        }
        
        return slow;
    }

    //Leetcode - 206. Reverse Linked List
    public ListNode reverseList(ListNode head) {
        
        if(head == null || head.next == null)
            return head;
        
        ListNode prev = null;
        ListNode curr = head;
        
        while(curr != null){
            ListNode fwd = curr.next;
            curr.next = prev;
            prev = curr;
            curr = fwd;
        }
        
        return prev;
    }

    //class Question : reverse data
    public ListNode reverseData(ListNode head) {
        
        if(head == null || head.next == null)
            return head;
        
        ListNode curr = head;
        ListNode mid = getMid(curr);
        ListNode head1 = mid.next;
        mid.next = null;

        head1 = reverseList(head1);
        ListNode curr1 = head1;

        while(curr != null && curr1 != null){
            int temp = curr.val;
            curr.val = curr1.val;
            curr1.val = temp;
            curr = curr.next;
            curr1 = curr1.next;
        }

        head1 = reverseList(head1);
        mid.next = head1;
        return head;
    }

    public ListNode middleNode02(ListNode head) {
        if(head == null || head.next == null)
            return head;
        ListNode slow = head;
        ListNode fast = head;   
        
        while(fast.next != null && fast.next.next != null){
            slow = slow.next;
            fast = fast.next.next;
        }
        return slow;
    }

    // Leetcode : 234. Palindrome Linked List
    public boolean isPalindrome(ListNode head) {
        
        if(head == null || head.next == null)
            return true;
        
        ListNode curr = head;
        ListNode mid = middleNode02(curr);
        ListNode head1 = mid.next;
        mid.next = null;
        
        head1 = reverseList(head1);
        ListNode curr1 = head1;
        while(curr!=null && curr1!=null){
            if(curr.val != curr1.val)
                return false;
            curr = curr.next;
            curr1 = curr1.next;
        }
        
        return true;
    }
    

    //Leetcode : 203. Remove Linked List Elements
    public ListNode removeElements(ListNode head, int val) {
        
        if(head == null){
            return null;
        }
        if(head.next == null){
            if(head.val == val)
                return null;
            return head;
        }
        
        ListNode curr = head;
        ListNode prev = null;
        
        while(curr!=null){
            if(curr.val == val){
                if(curr == head){
                    ListNode temp = head;
                    head = head.next;
                    temp.next = null;
                    curr = head;
                    continue;
                }
                else{
                    ListNode temp = curr;
                    prev.next = curr.next;
                    curr = curr.next;
                    temp.next = null;
                    continue;
                }
            }
            prev = curr;
            curr = curr.next;
        }
        
        return head;
    }
 

    //LeetCode : 83. Remove Duplicates from Sorted List
    public ListNode deleteDuplicates(ListNode head) {
        
        if(head == null || head.next == null)
            return head;
        
        ListNode prev = head;
        ListNode curr = head.next;
        
        while(curr != null)
        {
            if(prev.val == curr.val){
                prev.next = curr.next;
                curr.next = null;
                curr = prev.next;
            }
            else{
                prev = curr;
                curr = curr.next;
            }
        }
        return head;
    }


    // LeetCode : 19. Remove Nth Node From End of List
    public ListNode removeNthFromEnd(ListNode head, int n) {
        
        if(head == null || n == 0)
            return head;
        
        if(head.next == null){
            if(n == 1){
                return null;
            }
            else{
                return head;
            }
        }
        
        ListNode slow = head;
        ListNode fast = head;
        
        while(n-->0){
            fast = fast.next;
            if(n != 0 && fast.next == null){
                head = head.next;
                return head;
            }
        }
        
        while(fast.next!=null){
            slow = slow.next;
            fast = fast.next;
        }
        
        ListNode temp = slow.next;
        slow.next = slow.next.next;
        temp.next = null;
        
        return head;
    }



}