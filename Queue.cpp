#include <bits/stdc++.h>
using namespace std;

class Queue {
  private :
    static const int MAX = 100;
    // static은 해당 멤버가 객체가 아니라 클래스에 속하도록 하기 위한 키워드입니다.
    // MAX는 각 Stack 객체의 상태가 아니라,
    // Stack이라는 자료구조의 공통 규칙이기 때문에 static으로 선언했습니다.
    // 또한 배열 크기처럼 컴파일 타임에 필요한 값으로 사용하기 위해서도 static이 필요합니다.
    int arr[MAX];
    int front; // 맨 앞 요소 인덱스
    int rear; // 다음 삽입 위치 인덱스
    int size; // 현재 들어있는 원소 개수

  public : 
    Queue() : front(0), rear(0), size(0) {} // 초기화
    

    // 뒤에 추가
    bool enqueue(int x) {
      if(size == MAX) return false; // 꽉 차 있으면 false 리턴
      arr[rear] = x;
      rear = (rear + 1) % MAX; // rear을 원형으로 이동
      size++;
      return true;
    }

    bool dequeue() {
      if(size == 0) return false; // 아무것도 없으면 false 리턴
      front = (front + 1) % MAX; // stack의 pop 처럼 인덱스 조절만으로 삭제효과 발동(이미 선언된 배열이라 메모리 누수X)
      size--;
      return true;
    }

    int getFront() {
      if(size == 0) return -1; // 비어 있으면 -1 반환
      return arr[front];
    }

    bool isEmpty() {
      return size == 0;
    }
};


int main() {
  Queue q;                          // 큐 생성

  q.enqueue(1);                     // 1 삽입
  q.enqueue(2);                     // 2 삽입
  q.enqueue(3);                     // 3 삽입

  cout << q.getFront() << "\n";     // 1 출력

  q.dequeue();                      // 1 제거
  cout << q.getFront() << "\n";     // 2 출력

  cout << q.isEmpty() << "\n";      // 0 (안 비었음)

  q.dequeue();                      // 2 제거
  q.dequeue();                      // 3 제거
  cout << q.isEmpty() << "\n";      // 1 (비었음)

  return 0;
}