#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  Node* next;
  // 생성자: 데이터를 넣고 next는 null로 초기화
  Node(int value) : data(value), next(nullptr) {}
};

class LinkedList{
  private:
    Node* head;

  public:
    // 생성자 : 생성자 없으면 쓰레기값 들어가버림
    LinkedList() : head(nullptr) {}
    
    // 소멸자 : 없으면 링크드리스트 줄줄이 소세지 힙에 남아있어서 메모리 누수 발생
    ~LinkedList() {
      Node* cur = head; // head부터 출발
      while (cur != nullptr) {
        Node* nextNode = cur -> next; // nextNode에 cur이 가리키고 있는거 임시로 저장
        delete cur; // cur 자체를 삭제하는 게 아니라 cur 이 가리키고 있는 head Node 해제
        cur = nextNode; // cur에 nextNode를 할당
      }
    }

    void insertBack(int value) {
      Node* newNode = new Node(value); // 새 노드 생성

      // 1. 리스트가 비어있는 경우
      if (head == nullptr) { 
        head = newNode; 
        return;
      }

      // 2. 리스트에 값이 하나라도 있으면
      // 리스트 끝까지 이동
      Node* cur = head; // 현재 노드를 head부터 시작
      while (cur -> next != nullptr){ // 다음 노드가 없을 때까지(=!!마지막 노드에서 멈춰야함!!)
        cur = cur -> next; // 다음으로 이동
      }

      cur -> next = newNode; // 마지막 노드의 next가 새 노드를 가리키도록 연결
    }

    void insertFront(int value){
      Node* newNode = new Node(value); // 새 노드 생성

      newNode -> next = head; // 새 노드가 가리키는 next를 head로 설정
      head = newNode; // head를 newNode로 설정
    }

    bool search(int value){
      Node* cur = head; // 현재 노드를 head부터 시작

      while (cur != nullptr){ // !!얘는 마지막 노드도 검사해야해서 이렇게 씀!!
        if(cur-> data == value){ // 값이 있으면 true 반환
          return true;
        }
        cur = cur -> next; // 다음으로 이동
      }
      return false; // 값 없으면 false 반환
    }

    void remove(int value){
      // 1. 암것도 없는 경우 -> 암것도 못함
      if (head == nullptr) return;

      // 2-1. 삭제 대상이 head인 경우
      if(head -> data == value) {
        Node* temp = head; // 삭제할 head 노드 임시 저장(저장 안하면 이동하고 삭제값(temp) 찾을 도리가 없음)
        head = head -> next; // head를 다음 노드로 안전하게 이동
        delete temp; // 삭제 대상 node 저장 삭제
      }

      // 2-2. head가 아닌 경우 : 이전 노드 따라가며 찾기
      Node* cur = head; // head로 시작
      while (cur -> next != nullptr && cur -> next -> data != value){ 
        // “다음 노드가 존재하니?”, “다음 노드의 값이 우리가 찾는 값이 아니니?”
        // “다음 노드가 존재하고, 그 다음 노드의 값이 우리가 찾는 값이 아닐 동안만 앞으로 이동한다.”
        // -> 삭제할 노드의 ‘이전 노드’를 찾기 위해 이동한다.
        cur = cur -> next; 
        // cur->next가 존재하면서 아직 삭제 대상이 아닐 때만 이동하고,
      }

      // 루프가 끝나면 cur->next가 삭제 대상이거나 리스트의 끝이 됩니다.
      // cur -> next가 nullptr이면 못 찾은 것 -> 걍 암것도 안함
      if (cur -> next == nullptr) return;

      // cur -> next가 삭제 대상인 경우
      Node* temp = cur -> next; // 삭제할 노드 저장
      cur -> next = cur -> next -> next; // 연결을 건너뛰어 삭제 효과
      delete temp; //임시서장 삭제
    }


    void print() {
      Node* cur = head; // 현재 위치를 head로
      while (cur != nullptr) {
        cout << cur -> data << " ";
        cur = cur -> next;
      }
      cout << "\n";
    }
};


int main () {
  LinkedList list;
  list.insertBack(2);
  list.insertBack(3);
  list.insertBack(4);

  list.insertFront(1);

  cout << list.search(10) << "\n";  

  list.remove(20);

  list.print();

  return 0;
}