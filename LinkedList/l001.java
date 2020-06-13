public class l001{

    public static class linkedlist{

        public class Node{
            int data;
            Node next = null;

            public Node(int data){
                this.data = data;
            }
        }

        Node head = null;
        Node tail = null;
        int size = 0;

        //generalutil===========================

        public int size(){
            return this.size;
        }

        public Boolean isEmpty(){
            return this.size == 0;
        }

        @Override
        public String toString(){
            Node curr = this.head;
            String str = "";
            while(curr != null){
                str += (curr.data + " -> ");
                curr = curr.next;
            }
            return str;
        } 

        public Node getNodeAt(int pos){
            Node curr = this.head;
            while(pos-->0){
                curr = curr.next;
            }
            return curr;
        }

        //add =============================================
        private void addFirstNode(Node node){
            if(this.size == 0){
                this.head = node;
                this.tail = node;
            }
            else
            {
                node.next = this.head;
                this.head = node;
            }
            this.size++;
        }
        public void addFirst(int data){
            Node node = new Node(data);
            addFirstNode(node);
        }

        private void addLastNode(Node node){
            if(this.size == 0){
                this.head = node;
                this.tail = node;
            }
            else{
                this.tail.next = node;
                this.tail = node;
            }
            this.size++;
        }
        public void addLast(int data){
            Node node = new Node(data);
            addLastNode(node);
        }

        private void addAtNode(Node node, int pos){
            if(pos == 0){
                addFirstNode(node);
            }
            else if(pos == this.size){
                addLastNode(node);
            }
            else{
                Node prev = getNodeAt(pos-1);
                Node temp = prev.next;
                prev.next = node;
                node.next = temp;
            }
            
            this.size++;
        }
        public void addAt(int data, int pos){
            Node node = new Node(data);
            if(pos >= this.size || pos < 0){
                System.out.println("Null Point Exception!");
                return;
            }
            
            addAtNode(node, pos);
        }

        //remove Function===========================================

        public int removeFirst(){
            if(this.size == 0){
                System.out.println("EmptyList!");
                return -1;
            }
            
            Node rnode = this.head;
            if(this.size == 1){
                this.head = null;
                this.tail = null;
            }
            else{
                this.head = this.head.next;
                rnode.next = null;
            }
            this.size--;
            return rnode.data;
        }

        public int removeLast(){
            if(this.size == 0){
                System.out.println("EmptyList!");
                return -1;
            }
            
            Node rnode = this.tail;
            if(this.size == 1){
                this.head = null;
                this.tail = null;
            }
            else{
                Node secondLastNode = getNodeAt(this.size-2);
                secondLastNode.next = null;
                this.tail = secondLastNode;
            }
            this.size--;
            return rnode.data;
        }

        public int removeAt(int pos){
            
            if(pos >= this.size || pos < 0){
                System.out.println("Null Point Exception!");
                return -1;
            }

            if(pos == 0)
                return removeFirst();
            
            else if(pos == this.size-1)
                return removeLast();

            else{
                Node prev = getNodeAt(pos-1);
                Node temp = prev.next;
                prev.next = prev.next.next;
                temp.next = null;
                this.size--;
                return temp.data;
            }

        }

        //get Function =============================================
        
        public int getFirst(){
            if(this.size == 0){
                System.out.println("EmptyList!");
                return -1;
            }
            return this.head.data;
        }

        public int getLast(){
            if(this.size == 0){
                System.out.println("EmptyList!");
                return -1;
            }
            return this.tail.data;
        }

        public int getAt(int pos){
            
            if(pos >= this.size || pos < 0){
                System.out.println("Null Point Exception!");
                return -1;
            }

            return getNodeAt(pos).data;
        }


    }

    public static void main(String[] args){
        
        linkedlist ll = new linkedlist();
        for(int i=1;i<10;i++){
            ll.addFirst(i*10);
        }
        for(int i=1;i<10;i++){
            ll.addLast(i*10);
        }
        System.out.print(ll);

    }

}