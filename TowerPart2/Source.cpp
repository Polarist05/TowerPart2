#include<stdio.h>
#include<iostream>
#include<vector>
#include<map>
#include<limits.h>
using namespace std;
map<int, vector<int> > ma;
bool bo[100005];
int f1(vector<int>& v) {
	int ans=INT_MIN;
	vector<int> v1;
	for (int i = 0; i < v.size(); i++) {
		ans = max(ans, v[i]);
		for (int j = 0; j < ma[v[i]].size(); j++) {
			if (!bo[ma[v[i]][j]]) {
				bo[ma[v[i]][j]] = true;
				v1.push_back(ma[v[i]][j]);
			}
		}
	}
	v = v1;
	return ans;
}
int main() {
	int a, b, c,ans=INT_MIN;
	cin >> a >> b >> c;
	for (int i = 0; i < c; i++) {
		int d, e;
		cin >> d >> e;
		ma[d].push_back(e);
	}
	vector<int> v = ma[1];
	bo[1] = true;
	for(int i=0;i<a;i++)
		ans=max(ans, f1(v));
	printf("%d",ans);
}