//1. 배열에 자연수 x를 넣는다
//2. 배열에서 가장 큰 값을 출력하고, 그 값을 배열에서 제거한다
//최대힙을 이용하여 다음 연산을 지원하는 프로그램 작성
#include <iostream>
#include <vector>

using namespace std;

bool isEmpty(vecotr<int>& heap) {
	return heap.size() == 1;
}

void push(int x, vector<int> &heap) {
	int idx = heap.size();
	//삽입
	heap.push_back(x);

	while (idx>1 && heap[idx]>heap[idx/2]) { //자식으로 부모 인덱스 아는법 /2 하기
		swap(heap[idx], heap[idx / 2]);
		idx /= 2;
		//인덱스가 들어가면 주의할 점.
		//idx가 0으로 계속 돌 수도 그래서 idx>1 넣어줌
	}
}

int pop(vector<int>& heap) {
	//루트원소를 마지막에 있는 걸로 바꾸고 내려가며 비교
	int item = heap[1];
	//마지막 원소를 구하는 법은 사이즈 -1
	heap[1] = heap[heap.size() - 1];
	heap.pop_back(); //마지막 벡터가 삭제되고 사이즈도 줄음
	
	int parent = 1, child = 2;
	int size = heap.size();


	//2. 둘 중 더 큰 자식이 나보다 클 때 바꾸는 것
	
	while (child < size) {
		//1. 왼쪽 오른쪽 비교
		if (child+1 < size && heap[child]< heap[child+1]) {
			child++; //왼쪽자식에서 오른쪽자식으로 바꾸는거
		}

		//2. 둘 중 더 큰 자식이 나보다 클 때 바꾸는 것
		if (heap[child] > heap[parent]) {
			swap(heap[child], heap[parent]);
			parent = child;
			child = parent * 2; 
		}
		else {
			break;
		}
	}
	return item;

}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, x;
	cin >> n;

	vector<int> heap(1,0); //배열도 가능하지만 웬만하면 벡터로 해라
	//첫번째 인덱스는 사용 안 할 거니까 0을 넣어두기



	while (n--) {
		cin >> x;
		switch (x) {
			case 0
				//삭제
				if (isEmpty(heap)) {
					cout<<pop(heap)<<'\n';
				}
				else {
					cout << "0\n";
				}
				break;
			default:
				//삽입
				push(x, heap);
				break;
		}
	}
	return 0;


}