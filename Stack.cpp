#include <bits/stdc++.h>
using namespace std;

class Stack {
  private:
    static const int MAX = 100;
    //tatic은 해당 멤버가 객체가 아니라 클래스에 속하도록 하기 위한 키워드입니다.
    // MAX는 각 Stack 객체의 상태가 아니라,
    // Stack이라는 자료구조의 공통 규칙이기 때문에 static으로 선언했습니다.
    // 또한 배열 크기처럼 컴파일 타임에 필요한 값으로 사용하기 위해서도 static이 필요합니다.
    int arr[MAX];
    int top;
  
  public :
    Stack() : top(-1) {} // 생성자 : 처음엔 비어있으므로 -1


    // 추가
    bool push(int x){
      if(top == MAX - 1) return false; // 스택 꽉 차있으면(인덱스라 -1해줌)
    
      arr[++top] = x; // top 증가후 값 저장
      return true;
    }


    // 맨 위 값 제거
    bool pop(){
      if(top == -1) return false; // 스택비어 있으면 실패
      top--; // top만 줄이면 제거 효과 !! -> 그럼 메모리 낭비 아님? ㄴㄴ 이미 할당된 배열공간이기 때문에 top만 관리하면 됨
      return true;
    }

    // 제일 위 값 확인
    int peek() {
      if(top == -1) return -1; // 비어 있으면 -1 반환
      }
      return arr[top]; // 맨 위 값 반환
    }

    // 비어있는지 확인
    bool isEmpty() {
      return top == -1;
    }

};


// ✅ 사용 예시
int main() {
  Stack st;                     // 스택 생성

  st.push(10);                  // 10 push
  st.push(20);                  // 20 push
  cout << st.peek() << "\n";    // 20 출력

  st.pop();                     // 20 pop
  cout << st.peek() << "\n";    // 10 출력

  cout << st.isEmpty() << "\n"; // 0 출력(안 비었음)

  st.pop();                     // 10 pop
  cout << st.isEmpty() << "\n"; // 1 출력(비었음)

  return 0;
}