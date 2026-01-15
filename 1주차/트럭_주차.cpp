#include <bits/stdc++.h>
using namespace std;

int arr[100];
int bill[3];
int stamp[6];
int cnt[3];
int sum;


void count() {
  for(int i = stamp[0]; i < stamp[1]; i++){
    arr[i]++;
  }
  for(int i = stamp[2]; i < stamp[3]; i++){
    arr[i]++;
  }
  for(int i = stamp[4]; i < stamp[5]; i++){
    arr[i]++;
  }
  return;
}

void calculate() {
  for(int i : arr) {
    for (int j = 1; j < 4 ; j++){
      if(i == j){
        cnt[i-1]++;
      }
    }
  }
  
  for(int i = 0; i < 3; i++){
    sum += bill[i]*cnt[i]*(i+1);
  }

  cout << sum << '\n';

  return;
}


int main() {
  for(int i = 0; i < 3; i++){
    cin >> bill[i];
  }
  for(int i = 0; i < 6; i++){
    cin >> stamp[i];
  }
  
  count();
  calculate();

  return 0;
}