/*
struct ListNode
{
  int data;
  ListNode *next;
};
链表类接口如下：
class List
{
public:
  List()
  {
    head = new ListNode;
    head->next = NULL;
  }
 
  ~List()
  {
    ListNode* curNode;
    while( head->next )
    {
      curNode = head->next;
      head->next = curNode->next;
      delete curNode;
    }       
    delete head;
  }
   //在链表第pos(pos>0)个结点之前插入新结点，新结点的值为toadd
   //链表实际结点从1开始计数。
   //调用时需保证pos小等于链表实际结点数 
   void List::insert(int toadd, int pos);
 
  // Data field
  ListNode *head; //head指向虚拟头结点，head-next指向第一个实际结点
};
*/
void List::insert(int toadd, int pos) {
  ListNode *temp = head;
  for (int i = 1; i < pos; ++i) {
    temp = temp->next;
    if (temp == nullptr)
      return;
  }
  auto res = new ListNode();
  res->next = temp->next;
  res->data = toadd;
  temp->next = res;
}