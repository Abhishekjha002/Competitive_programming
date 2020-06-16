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

    // LeetCode : 143. Reorder List
    public void reorderList(ListNode head) {
        
        if(head == null || head.next == null)
            return;
        
        ListNode curr = head;
        ListNode mid = middleNode02(curr);
        ListNode head1 = mid.next;
        
        mid.next = null;
        
        head1 = reverseList(head1);
        
        ListNode curr1 = head;
        ListNode curr2 = head1;
        
        while(curr1 != null && curr2 != null){
            
            ListNode fwd1 = curr1.next;
            ListNode fwd2 = curr2.next;
            curr1.next = curr2;
            curr2.next = fwd1;
            curr1 = fwd1;
            curr2 = fwd2;
            
        }

        //Class Question - get the actual LL from reorder list
        public void reorderList(ListNode head) {
        
        if(head == null || head.next == null)
            return;
        
        ListNode h1 = head;
        ListNode h2 = head.next;
        
        ListNode f1 = h1;
        ListNode f2 = h2;
        
        while(f2 != null && f2.next != null){
            
            f1.next = f2.next;
            f1 = f2.next;
            f2.next = f1.next;
            f2 = f1.next;
            
        }
        
        h2 = reverseList(h2);
        f1.next = h2;
        
        }

        // LeetCode : 21. Merge Two Sorted Lists
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        
        if(l1 == null || l2 == null) return l1==null?l2:l1;
        
        ListNode head = new ListNode(-1);
        ListNode prev = head;
        
        ListNode curr1 = l1;
        ListNode curr2 = l2;
        
        while(curr1 != null && curr2 != null){
            if(curr1.val <= curr2.val){
                prev.next = curr1;
                prev = curr1;
                curr1 = curr1.next;
            }else{
                prev.next = curr2;
                prev = curr2;
                curr2 = curr2.next;
            }
        }
        
        if(curr1 != null){
            prev.next = curr1;
        }
        
        if(curr2 != null){
            prev.next = curr2;
        }
        
        return head.next;
    }


    // LeetCode : 328. Odd Even Linked List
    public ListNode oddEvenList(ListNode head) {
        
        if(head == null || head.next == null){
            return head;
        }
        
        ListNode h1 = head;
        ListNode h2 = head.next;
        
        ListNode f1 = h1;
        ListNode f2 = h2;
        
        while(f2 != null && f2.next != null){
            f1.next = f2.next;
            f1 = f2.next;
            f2.next = f1.next;
            f2 = f1.next;
        }
        
        f1.next = h2;
        return head;
    }
 
    //Class Question : odd - even
    public ListNode odd_even(ListNode head) {
        
        if(head == null || head.next == null){
            return head;
        }
        
        ListNode ho = null;
        ListNode he = null;
        
        ListNode f1 = null;
        ListNode f2 = null;
        
        ListNode prev = null;
        ListNode curr = head;
        
        
        while(curr != null){
            
            if(prev == null){
                if(curr.val%2 == 0){
                    he = curr;
                    f2 = he;
                }else{
                    ho = curr;
                    f1 = ho;
                }
            }
            
            else if(prev.val%2 != 0){
                if(curr.val%2 == 0){
                    if(he == null){
                        prev.next = null;
                        he = curr;
                        f2 = he;
                    }
                    else{
                        prev.next = null;
                        f2.next = curr;
                        f2 = curr;
                    }
                }
                else{
                    f1 = curr;
                }
            }
            
            else if(prev.val%2 == 0){
                if(curr.val%2 != 0){
                    if(ho == null){
                        prev.next = null;
                        ho = curr;
                        f1 = ho;
                    }
                    else{
                        prev.next = null;
                        f1.next = curr;
                        f1 = curr;
                    }
                }
                else{
                    f2 = curr;
                }
            }
            
            prev = curr;
            curr = curr.next;
            
        }
        
        f1.next = he;
        return ho;
    }

    // LeetCode : 141. Linked List Cycle
    public boolean hasCycle(ListNode head) {
        
        if(head == null || head.next == null)
            return false;
        
        ListNode slow = head;
        ListNode fast = head;
        
        while(fast != null && fast.next != null){
            
            slow = slow.next;
            fast = fast.next.next;
            if(slow == fast){
                return true;
            }
        }
        
        return false;
    }

    // Leetcode : 142. Linked List Cycle II
    public ListNode detectCycle(ListNode head) {
        
        if(head == null || head.next == null){
            return null;
        }
        
        ListNode slow = head;
        ListNode fast = head;
        
        while(fast != null && fast.next != null){
            slow = slow.next;
            fast = fast.next.next;
            if(slow == fast)
                break;
        }
        
        if(slow != fast){
            return null;
        }
        
        slow = head;
        while(slow != fast){
            slow = slow.next;
            fast = fast.next;
        }
        
        return slow;
        
    }

    // LeetCode : 160. Intersection of Two Linked Lists
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        
        if(headA == null || headB == null)
            return null;
        
        if(headA.next == null && headB.next == null){
            if(headA == headB)
                return headA;
            return null;
        }
        
        ListNode curr = headA;
        while(curr.next!=null){
            curr = curr.next;
        }
        
        curr.next = headA;
        
        ListNode ip = detectCycle(headB);
        
        curr.next = null;
        return ip;

    }

    // LeetCode : 148. Sort List
    public ListNode sortList(ListNode head) {
        
        if(head == null || head.next == null)
            return head;
        
        ListNode curr1 = head;
        ListNode mid = middleNode02(curr1);
        ListNode curr2 = mid.next;
        mid.next = null;
        
        return mergeTwoLists(sortList(curr1), sortList(curr2));
   
    }


    // LeetCode : 23. Merge k Sorted Lists
    public ListNode mergeKLists(ListNode[] lists) {
        
        int k = lists.length;
        if(k == 0){
            return null;
        }
        return mergeKLists_(lists, 0, k-1);
    }
    public ListNode mergeKLists_(ListNode[] lists, int si, int ei) {
        
        if(si == ei){
            return lists[si];
        }
        
        int mid = (si+ei)/2;
        
        return mergeTwoLists(mergeKLists_(lists,si,mid), mergeKLists_(lists,mid+1,ei));
    }

    


}