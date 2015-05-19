Need to know what has gone wrong


/* Please implement a hash table.   Constraints:

* In C or C++

* only implement get, set, and the constructor/init function

* you can use a builtin hash function

* you can use higher level data structures like ilnked lists or array lists, but you cannot use a hash table, hash map, etc

* enforce uniqueness.   so if hash.put("foo", "bar"); hash.put("foo", "baz"); then hash.get("foo") should return "baz".

* don't worry about regrowing the table as it fills, but if your implementation can fill up, you must handle it gracefully (don't crash, don't enter an infinite loop)

* use any data types you want for the keys and the values. 
*/

int hash()

struct LinkListNode{
    Obj value;
    Obj key;
    int hashCode;
    ListNode* listNext;
    ListNode* next;
    LinkListNode(Obj key, Obj value):value(value),key(key), hashCode(0),listNext(nullptr),
            next(nullptr){};
};

ListListNode* head;

template<class Obj>
Obj get( Obj key ){
    int code = hash(key);
    LinkListNode * cur = head;
    while( cur != nullptr){
        if( cur->hashCode = code){
            break;
        }
        cur = cur->next;
    }
    
    while( cur->key != key || cur != nullptr ){
        cur = cur->listNext;
    }
    if(cur == nullptr) return Obj(); //return newly initialized Obj
    return cur->value;
}

template<class Obj>
void set(Obj key, Obj value){
    int code = hash(key);
    LinkListNode* cur = head;
    LinkListNode dummy(Obj(), Obj());
    LinkListNode* prev = &dummy;
    while( cur != nullptr ){
        if(cur->hashCode = code) break;
        prev = cur;
        cur = cur->next;
    }
    
    if( cur == nullptr ){
        LinkListNode node(key, value);
        prev->next = &node;
        node.hashCode = code;
    }else{
        while( cur != nullptr ){
            if( cur->key == key ) break;
            prev = cur;
            cur = cur->listNext;
        }
        if( cur != nullptr ){
            cur->value = value; //update
        }else{
            LinkListNode node(key, value);
            prev->next = &node;
            node.hashCode = code;
        }
            
    }
   
}