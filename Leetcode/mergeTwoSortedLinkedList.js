function ListNode(val, next) {
    this.val = (val===undefined ? 0 : val)
    this.next = (next===undefined ? null : next)
    }
    var mergeTwoLists = function(l1, l2) {
        if(!l1){
            return l2;
        }
        if(!l2){
            return l1;
        }
        var l3 = new ListNode(-1);
        let res = l3;
        while(l1 && l2){
            if(l1.val < l2.val){
                l3.next = new ListNode(l1.val);
                l3 = l3.next;
                l1 = l1.next;
            }else if(l2.val < l1.val){
                l3.next = new ListNode(l2.val);
                l3 = l3.next;
                l2 = l2.next;
            }else{
                l3.next = new ListNode(l1.val);
                l3 = l3.next;
                l3.next = new ListNode(l2.val);
                l3 = l3.next;
                l2 = l2.next;
                l1 = l1.next;
            }
        }
        if(l1)
            l3.next=l1;
        if(l2)
            l3.next=l2;
        return res.next;
    };
    