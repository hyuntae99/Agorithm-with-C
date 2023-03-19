#include <stdio.h>
#include <vector> 
#include <iostream> 
#include <algorithm>

using namespace std;

int n, k; // n:배열의 크기, k:색깔의 종류
vector <int> P; // 벡터 P
vector <int> color_P; // P에 대한 색깔의 수 벡터 
vector <int> color_Pl; // P'에 대한 색깔의 수 벡터
vector <int> answer; // double rainbow후보를 저장하기 위한 정답 벡터

// 색깔의 개수를 계산하는 함수
int count_color(vector <int> arr)
{
	// 이진탐색을 위한 정렬
	sort(arr.begin(), arr.end());
	// color[0] = 0으로 기본값으로 가지고 있으므로 arr.begin()+1
	if (binary_search(arr.begin()+1, arr.end(), 0))
		return 0;
	// 색깔 벡터에 모든 색깔이 있을 경우 -> O
	else
		return k;
}

// double rainbow를 탐색하는 함수
void double_rainbow(void)
{
	// 벡터의 왼쪽, 오른쪽 변수
	int left = 0;
	int right = 0;

	// left, right가 n을 넘지 않을 때까지 반복
	while ((left < n) && (right < n))
	{
		// P'이 k가지 색깔을 만족할 때
		if (count_color(color_Pl) == k)
		{
			// P-P'이 만족할 때 -> 정답 벡터에 저장한다.
			if (count_color(color_P) == k)
				// 아래 else문에서 right += 1을 color벡터에 반영시킨 후 적용했기때문에 (right - 1) - left + 1 => right - left
				answer.push_back(right - left);

			// P'의 왼쪽을 조인다. -> P'이 만족하지 못할 때까지
			left += 1;
			color_P[P[left-1]] += 1;
			color_Pl[P[left-1]] -= 1;
		}
		// P'이 k가지 색깔을 만족하지 못할 때
		else
		{
			// P'을 오른쪽으로 확장한다.
			color_P[P[right]] -= 1;
			color_Pl[P[right]] += 1;
			right += 1;
		}
	}
	// 위의 조건을 모두 만족하지 못할 때 -> double rainbow가 없을 경우
	if (answer.size() == 0)
		// 최솟값 출력을 위해 answer에 0추가.
		answer.push_back(0);
}


// 메인 함수
int main(void)
{
	cin >> n >> k;

	// 벡터 초기화
	color_P.assign(k + 1, 0);
	color_Pl.assign(k + 1, 0);

	// P 벡터 받기 + color1의 색깔 수 받기
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		P.push_back(a);
		// 색깔의 종류와 인덱스를 동일시해서 색깔의 개수 카운트한다. -> 색깔은 1부터이므로 0번 인덱스는 없는셈치고 진행해야함.
		// color벡터은 k+1개로 (0,a,b,c,d)로 표현할 수 있음. (a,b,c,d는 색깔의 개수)
		color_P[a] += 1;
	}

	// 함수 실행
	double_rainbow();

	// answer벡터(정답 후보)중 최솟값 출력
	int min = *min_element(answer.begin(), answer.end());
	cout << min << endl;

	return 0;
}