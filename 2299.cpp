//�����ֲ�ɶ���������ĺ͵���ʽ
//@author yuhaozh88
#include<iostream>
#include<algorithm>
#include<deque>
#include<queue>
#include<stack>
#include<vector>
using namespace std;

bool isPalindrome(int x) {
	if (x < 0) {//����û�л�����
		return false;
	}
	else {//��������0
		int copy = x;
		int test = 0;
		while (copy != 0) {
			int temp = copy % 10;
			copy = (copy - temp) / 10;
			test = 10 * test + temp;
		}
		if (test == x) {
			return true;
		}
		else {
			return false;
		}
	}
};

int main()
{
	int num;
	cin >> num;
	while (!isPalindrome(num)) {
		int sum=0;
		int temp;
		int copy = num;
		int length;
		deque<int> store;
		queue<int> part;
		stack<int> reverse;
		vector<int> arr;
		arr.push_back(0);
		while (copy != 0) {//���ǻ����������ֲ�ɵ�������
			temp = copy % 10;
			store.push_back(temp);
			arr.push_back(temp);
			copy -= temp;
			copy /= 10;
		}
		length = arr.size()-1;
		if (length % 2 != 0) {//���������ӵ�л���λ
			int cen = (length + 1) / 2;
			int pos_l = cen - 1;
			int pos_r = cen + 1;
			 while (pos_l>=1&&pos_r<=length) {
				if (arr[pos_l] >= arr[pos_r]) {
					arr[pos_l] = arr[pos_r];
					pos_l--;
					pos_r++;
				}
				else {
					arr[cen] -= 1;
					break;
				}
			}
			while (pos_l >= 1 && pos_r <= length) {
				arr[pos_l] = arr[pos_r];
				pos_l--;
				pos_r++;
			}
		}
		else {//���������ӵ��ż��λ
			int pos_l = length / 2;
			int pos_r = length / 2 + 1;
			int cen = pos_r;
			while (pos_l >= 1 && pos_r <= length) {
				if (arr[pos_l] >= arr[pos_r]) {
					arr[pos_l] = arr[pos_r];
					pos_l--;
					pos_r++;
				}
				else {
					arr[cen] -= 1;
					break;
				}
			}
			while (pos_l >= 1 && pos_r <= length) {
				arr[pos_l] = arr[pos_r];
				pos_l--;
				pos_r++;
			}
		}
		for (int i = length; i >=1; i--) {
			sum = sum * 10 + arr[i];
		}
		cout << sum << endl;
		num -= sum;
	}
	cout << num << endl;
	return 0;
}