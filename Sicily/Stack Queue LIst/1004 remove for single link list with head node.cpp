void List::remove(int pos) {
  if (pos <= 0 || head->next == nullptr)
    return;
  auto temp = head;
  for (int i = 1 ; i < pos; ++i) {
    temp = temp->next;
    if(temp->next == nullptr)
      return;
  }
  auto toDel = temp->next;
  temp->next = toDel->next;
  delete toDel;
}