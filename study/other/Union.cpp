#include<iostream>
#include<vector>
using namespace std;

class UnionFindSet {
	public:
		UnionFindSet(size_t n) {
			v.resize(n, -1);
		}
		
		//1.�������������Ͻ��кϲ����������ж����������ĸ��Ƿ���ͬ������ͬ˵���Ѿ���ͬһ����Ͳ����ںϲ�
		//�������ͬ���ͽ�һ�����ĸ��ӵȵ���һ�����ĸ���ȥ������������Ÿ��� 
		void Union(int x1, int x2) {
			//���ж��������ĸ��Ƿ���ͬ
			int root1 = FindRoot(x1);
			int root2 = FindRoot(x2);
			if (root1 != root2) {
				//����������ͬ����һ����ȥ����һ�����ĸ�
				v[root1] += v[root2];
				v[root2] = root1;
			}
		}

		//2.����һ�����ĸ���������x������±�Ϊx�������ŵ�����Ϊm����mС��0��˵����ǰλ��x���Ǹ���
		//���m����0���ټ����ж��±�Ϊm�������Ƿ�Ϊ������������������̣���v���Զ����һ��vector�� 
		size_t FindRoot(int x) {
			int index = x;
			while (v[index] >= 0) {
				//˵�������Ǹ�������������������ݴ�ŵ��Ƿ��Ǹ�
				index = v[index];
			}
			return index;
		}
		
		//3.����֪���ϲ���ɺ�һ���ж��ٸ��飺����һ�����飬�����ĸ������Ǹ��ĸ������ж��ٸ��������ж��ٸ��飩��  
		//���������Ҳ�����ж��ٸ�����
		int GetCount() {
			int num = 0;
			for (size_t i = 0; i < v.size(); ++i) {
				if (v[i] < 0) {
					++num;
				}
			}
			return num;
		}

	private:
		vector<int> v;
};
