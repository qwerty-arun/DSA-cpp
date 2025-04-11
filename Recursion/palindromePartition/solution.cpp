#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isPalin(string s)
{
	string s2 = s;
	reverse(s2.begin(),s2.end());
	return s==s2;
}
void getAllParts(std::string s, std::vector<std::string>& partitions, std::vector<std::vector<std::string>> &ans)
{
	if(s.size()==0)
	{
		ans.push_back(partitions);
		return;
	}


	for(int i=0;i<s.size();i++)
	{
		string part = s.substr(0,i+1);
	
		if(isPalin(part))
		{
			partitions.push_back(part);
			getAllParts(s.substr(i+1),partitions,ans);
			partitions.pop_back();
		}
	}
}


int main()
{
	string s ="aab";
	vector<string> partitions;
	vector<vector<string>> ans;
	getAllParts(s, partitions, ans);

	for(int i = 0;i<ans.size();i++)
	{
		vector<string> part = ans[i];
		for(int j=0;j<part.size();j++)
		{
			cout<<part[j]<<" ";
		}
		cout<<"\n";
	}
}


