#include<iostream>
#include<vector>
using namespace std;

class UnionFindSet {
	public:
		UnionFindSet(size_t n) {
			v.resize(n, -1);
		}
		
		//1.并（将两个集合进行合并）：首先判断这两个数的根是否相同，若相同说明已经在同一组里，就不用在合并
		//如果不相同，就将一个数的根加等到另一个数的根上去，并将该数存放根。 
		void Union(int x1, int x2) {
			//先判断两个数的根是否相同
			int root1 = FindRoot(x1);
			int root2 = FindRoot(x2);
			if (root1 != root2) {
				//两个根不相同，让一个根去做另一个根的根
				v[root1] += v[root2];
				v[root2] = root1;
			}
		}

		//2.查找一个数的根：对于数x，如果下标为x的里面存放的数据为m，若m小于0，说明当前位置x就是根，
		//如果m大于0，再继续判断下标为m的数据是否为根，继续上面这个过程；（v是自定义的一个vector） 
		size_t FindRoot(int x) {
			int index = x;
			while (v[index] >= 0) {
				//说明还不是根，则继续查找它的内容存放的是否是根
				index = v[index];
			}
			return index;
		}
		
		//3.若想知道合并完成后一共有多少个组：遍历一遍数组，负数的个数就是根的个数（有多少个根，就有多少个组）。  
		//获得组数，也就是有多少个分组
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
